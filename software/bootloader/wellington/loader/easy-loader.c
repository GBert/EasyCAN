/*------------------------------------------------------------------------------
;
; Title:	Take it Easy Loader for The Wellington Boot Loader for PIC18
;
; Copyright:	Copyright (c) 2014 Agent Easy
;		Copyright (c) 2014 The Duke of Welling Town
;
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;   This file is part of The Wellington Boot Loader.
;
;   The Wellington Boot Loader is free software: you can redistribute it and/or
;   modify it under the terms of the GNU General Public License as published
;   by the Free Software Foundation.
;
;   The Wellington Boot Loader is distributed in the hope that it will be
;   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
;   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
;   GNU General Public License for more details.
;
;   You should have received a copy of the GNU General Public License along
;   with The Wellington Boot Loader. If not, see http://www.gnu.org/licenses/
;-----------------------------------------------------------------------------*/

/*
 * DISCLAIMER:
 *
 * This program has no relation to any 1970s popular music of a similar
 * name. This is purely co-incidental. You are not discouraged, however,
 * from humming along to it's tune when using this program.
 */

/*
 * Various UNIX and Linux header files
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>
#include <assert.h>
#include <sysexits.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <net/if.h>
#ifdef __linux
#include <linux/can.h>
#endif

/*
 * Generic buffer
 *
 * Must be as large as the largest PIC18 write row size
 */
#define BUFLEN (1536)
#define BUFMAX (BUFLEN - 1)

/*
 * Easy loader `Hello' query
 */
#define HELLO (0xC1)

/*
 * Wellington boot loader `hello' response packet
 */
struct hello_packet {
	uint8_t row;
	uint8_t erah, eral;
	uint8_t startu, starth, startl;
	uint8_t eeh, eel;
	uint8_t response;
} __attribute__((packed));

/*
 * Wellington boot loader responses
 */
#define RESPONSE_OK 'K'			/* 0x4B */
#define RESPONSE_ERROR_CHECKSUM 'N'	/* 0x4E */
#define RESPONSE_ERROR_UNKNOWN  'U'	/* 0x55 */

/*
 * Easy loader command packet
 */
struct command_packet {
	uint8_t addru, addrh, addrl;
	uint8_t command;
	uint8_t datasize;
	uint8_t data[BUFLEN];
} __attribute__((packed));

/*
 * Easy loader commands
 */
#define COMMAND_FLASH_ERASE (1)
#define COMMAND_FLASH_WRITE (2)
#define COMMAND_FLASH_READ  (4)
#define COMMAND_EE_WRITE    (8)
#define COMMAND_EE_READ    (16)

/*
 * I/O time out time in seconds
 */
#define TIMEOUT (2)

/*
 * Non-blocking I/O in or out
 */
#define IN  (1)
#define OUT (0)

/*
 * CAN Bus
 */
#define CAN_ID        (0x667)
#define CAN_MSG_DELAY (1000)
#define CAN_CMD_DELAY (10000)

/*
 * Easy loader session
 */
typedef struct easy {
	FILE *info;	/* Information stream     */
	int fd;		/* I/O descriptor         */
	int fdtyp;	/* I/O type 0=uart, 1=CAN */
	int cid;	/* CAN bus id             */
} easy_t;

/*******************************************************************************
 *
 * Open serial device
 *
 * Toggle RTS if required
 *
 ******************************************************************************/
int
openDevice(const char *dev, speed_t baudrate, int toggle)
{
	int fd, status;
	struct termios options;

	fd = open(dev, O_RDWR | O_NOCTTY | O_NONBLOCK);
	if (fd < 0)
		return fd;

	fcntl(fd, F_SETFL, O_NONBLOCK | fcntl(fd, F_GETFL));

	tcgetattr(fd, &options);

	/*
	 * Raw mode
	 *
	 *  Linux TERMIOS(3)
	 */

	options.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
	options.c_oflag &= ~(OPOST);
	options.c_cflag &= ~(CSIZE | PARENB);
	options.c_cflag |= (CS8);
	options.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);

	options.c_cc[VMIN] = 0;
	options.c_cc[VTIME] = 0;

	cfsetispeed(&options, baudrate);
	cfsetospeed(&options, baudrate);

	tcsetattr(fd, TCSANOW, &options);

	tcflush(fd, TCIOFLUSH);

	if (toggle) {
		ioctl(fd, TIOCMGET, &status);

		status |= TIOCM_RTS;
		ioctl(fd, TIOCMSET, &status);
		usleep(200000);

		status &= ~TIOCM_RTS;
		ioctl(fd, TIOCMSET, &status);
		usleep(100000);
	}
	return fd;
}

/*******************************************************************************
 *
 * Open Linux CAN socket
 *
 ******************************************************************************/
int
openCanSock(const char *dev)
{
#ifdef __linux
	struct ifreq ifr;
	struct sockaddr_can addr;
	int fsock, rc;

	fsock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (fsock < 0) {
		return fsock;
	}

	bzero(&ifr, sizeof(ifr));
	strncpy(ifr.ifr_name, dev, IFNAMSIZ);

	rc = ioctl(fsock, SIOCGIFINDEX, &ifr);
	if (rc < 0) {
		close(fsock);
		return rc;
	}

	bzero(&addr, sizeof(addr));
	addr.can_family = AF_CAN ;
	addr.can_ifindex = ifr.ifr_ifindex;

	rc = bind(fsock, (struct sockaddr *)&addr, sizeof(addr));
	if (rc < 0) {
		close(fsock);
		return rc;
	}

	return fsock;
#else
	return -1;
#endif
}

/*******************************************************************************
 *
 * Write 1 byte message to Linux CAN socket
 *
 *  If this fails with ENOBUFS, then increase the TX queue with:
 *
 *	ip link set can0 txqueuelen 1024
 *
 ******************************************************************************/
int
canWrite(easy_t *t, uint8_t *buffer, int buflen)
{
#ifdef __linux
	struct can_frame frame;
	int rc;

	if (buflen == 0)
		return 0;

	bzero(&frame, sizeof(frame));

	frame.can_id = t->cid;
	frame.can_dlc = 1;
	frame.data[0] = buffer[0];

	rc = write(t->fd, &frame, sizeof(frame));
	if (rc <= 0)
		return rc;
	if (rc != sizeof(frame))
		return -1;

	usleep(CAN_MSG_DELAY);

	return 1;
#else
	errno = EBADF;

	return -1;
#endif
}

/*******************************************************************************
 *
 * Read 1 byte message from Linux CAN socket
 *
 ******************************************************************************/
int
canRead(easy_t *t, uint8_t *buffer, int buflen)
{
#ifdef __linux
	struct can_frame frame;
	int rc;

	if (buflen == 0)
		return 0;

	bzero(&frame, sizeof(frame));

	rc = read(t->fd, &frame, sizeof(frame));
	if (rc <= 0)
		return rc;
	if (rc != sizeof(frame))
		return -1;
	
	if (frame.can_id != t->cid) {
		errno = EAGAIN; /* Filter message */
		return -1;
	}

	if (frame.can_dlc != 1) {
		errno = EAGAIN; /* Filter message */
		return -1;
	}

	memcpy(buffer, frame.data, frame.can_dlc);

	return frame.can_dlc;
#else
	errno = EBADF;

	return -1;
#endif
}

/*******************************************************************************
 *
 * Malloc with panic on error
 *
 ******************************************************************************/
static inline void *
xmalloc(size_t n, int c)
{
	void *s;

	if (!n)
		return NULL;
	s = malloc(n);
	if (s == NULL)
		exit(EX_OSERR);
	return memset(s, c, n);
}

/*******************************************************************************
 *
 * Free with sanity check
 *
 ******************************************************************************/
static inline void *
xfree(void *s)
{
	if (s)
		free(s);
	return NULL;
}

/*******************************************************************************
 *
 * Select in/out
 *
 ******************************************************************************/
static inline int
fdselect(easy_t *t, long timeout, int io)
{
	int rc;
	struct timeval tv;
	fd_set fdset;

	tv.tv_sec = timeout;
	tv.tv_usec = 0;

	FD_ZERO(&fdset);
	FD_SET(t->fd, &fdset);

	if (io == IN)
		rc = select(t->fd + 1, &fdset, NULL, NULL, &tv);
	else	/* OUT */
		rc = select(t->fd + 1, NULL, &fdset, NULL, &tv);

	return rc;
}

/*******************************************************************************
 *
 * Read/write
 *
 ******************************************************************************/
static inline int
fdreadwrite(easy_t *t, uint8_t *buffer, int buflen, int io)
{
	int rc;

	if (io == IN) {
		if (t->fdtyp)
			rc = canRead(t, buffer, buflen);
		else
			rc = read(t->fd, buffer, buflen);
	} else {	/* OUT */
		if (t->fdtyp)
			rc = canWrite(t, buffer, buflen);
		else
			rc = write(t->fd, buffer, buflen);
	}

	return rc;
}

/*******************************************************************************
 *
 * Non-blocking I/O
 *
 ******************************************************************************/
int
fdio(easy_t *t, uint8_t *buffer, int buflen, long timeout, int io)
{
	int rc;
	int nb = 0;

	while (nb < buflen) {
		rc = fdselect(t, timeout, io);
		if (rc < 0) {
			if (errno == EINTR)
				continue;
			fprintf(stderr, "Select failed [%d/%d].\n", nb, buflen);
			return rc;
		}
		if (rc == 0) {
			fprintf(stderr, "Select timed-out [%d/%d]\n", nb, buflen);
			return 0;
		}
		rc = fdreadwrite(t, &buffer[nb], buflen - nb, io);
		if (rc < 0) {
			if (errno == EINTR || errno == EAGAIN)
				continue;
			fprintf(stderr, "R/W failed [%d/%d].\n", nb, buflen);
			return rc;
		}
		if (rc == 0) {
			fprintf(stderr, "EOF [%d/%d].\n", nb, buflen);
			break; /* EOF */
		}

		nb += rc;
	}

	return nb;
}

/*******************************************************************************
 *
 * Read Hex Nibble
 *
 ******************************************************************************/
uint8_t
hex2nib(char c)
{
	uint8_t n = 0;

	if (c >= 'a' && c <= 'f') {
		n = c - 'a' + 10;
	}
	else if (c >= 'A' && c <= 'F') {
		n = c - 'A' + 10;
	}
	else if (c >= '0' && c <= '9') {
		n = c - '0';
	}
	return n;
}

/*******************************************************************************
 *
 * Read Hex Byte
 *
 ******************************************************************************/
static inline uint8_t
hex2byt(char *s)
{
	return hex2nib(s[0]) << 4 | hex2nib(s[1]);
}

/*******************************************************************************
 *
 * Read Hex Line
 *
 ******************************************************************************/
int
gethex(FILE *fp, uint16_t *addr, uint8_t *typ, uint8_t *bin, uint8_t *binlen)
{
	char line[BUFLEN];
	int i;
	uint8_t sum, len;

	if (fgets(line, BUFLEN, fp) == NULL)
		return 0;

	line[BUFMAX] = '\0';

	if (line[0] != ':')
		return -1;

	i = strlen(line) - 1;
	while (i >= 0 && (line[i] == '\r' || line[i] == '\n'))
		line[i--] = '\0';
		
	if (i & 1 || i < 10)
		return -1;

	sum = 0;
	*binlen = 0;
	for (i = 1; line[i]; i += 2) {
		bin[*binlen] = hex2byt(&line[i]);
		sum += bin[(*binlen)++];
	}
	if (sum)
		return -1;

	len = bin[0];
	if (*binlen != (len + 5))
		return -1;

	*addr = bin[1] << 8 | bin[2];
	*typ = bin[3];
	
	return len;
}

/*******************************************************************************
 *
 * Read Hex File
 *
 *  The hex file data is read into flash memory image.
 *
 *  Only data below the GOTO app vector is accepted.
 *
 ******************************************************************************/
int
readFile(const char *file, uint8_t *flash, uint16_t *eeprom, uint32_t startaddr, uint16_t eesize)
{
	FILE *fp;
	uint16_t addr, ext_addr = 0;
	uint8_t typ = 0, bin[BUFLEN], binlen, *data = &bin[4];
	uint32_t i, j, address, nbytes = 0, gotoapp = startaddr - 4;

	fp = fopen(file, "rb");
	if (!fp) {
		return -1;
	}
	while (typ != 1 && (gethex(fp, &addr, &typ, bin, &binlen) > 0)) {
		switch (typ) {
		case 0:	/* data */
			binlen -= 5;
			address = ext_addr << 16 | addr;
			for (i = 0; i < binlen; ++i) {
				j = address + i;
				if (j < gotoapp) {
					flash[j] = data[i];
					nbytes++;
				} else if (j >= 0xF00000 && j < (0xF00000 + eesize)) {
					eeprom[j - 0xF00000] = data[i];
					nbytes++;
				}
			}
			break;
		case 4: /* address */
			ext_addr = bin[4] << 8 | bin[5];
			break;
		}
	}
	fclose(fp);

	return nbytes;
}

/*******************************************************************************
 *
 * Fix GOTO
 *
 *  Preserve boot loader reset vector and store application reset vector in
 *  bootloader GOTO application vector.
 *
 ******************************************************************************/
void
fixGOTO(uint8_t *flash, uint32_t startaddr)
{
	uint32_t gotoapp;

	// GOTO application
	gotoapp = startaddr - 4; 
	flash[gotoapp] = flash[0];
	flash[gotoapp + 1] = flash[1];
	flash[gotoapp + 2] = flash[2];
	flash[gotoapp + 3] = flash[3];

	// GOTO bootloader
	flash[0] = ((startaddr & 0x00001FE) >> 1);
	flash[1] = 0xEF;
	flash[2] = ((startaddr & 0x001FE00) >> 9);
	flash[3] = ((startaddr & 0x01E0000) >> 17) | 0xF0;
}

/*******************************************************************************
 *
 * Calculate Checksum
 *
 ******************************************************************************/
uint8_t
getChecksum(uint8_t *buffer, int blen)
{
	int i;
	uint8_t csum = 0;

	for (i = 0; i < blen; ++i)
		csum -= buffer[i];

	return csum;
}

/*******************************************************************************
 *
 * Send command to boot loader
 *
 ******************************************************************************/
int
doCommand(easy_t *t, struct command_packet *cmd, int blen, int rlen)
{
	uint8_t *bcmd = (uint8_t *)cmd;
	int rc;

	while (1) {
#if 0
		printf("%s() address  = 0x%02X%02X%02X\n", __func__, cmd->addru, cmd->addrh, cmd->addrl);
		printf("%s() command  = 0x%02X\n", __func__, cmd->command);
		printf("%s() datasize = 0x%02X\n", __func__, cmd->datasize);
		printf("%s() data[0]  = 0x%02X\n", __func__, cmd->data[0]);
#endif
		assert(blen > 0);

		rc = fdio(t, bcmd, blen, TIMEOUT, OUT);
		if (rc != blen) {
			if (rc < 0) {
				fprintf(stderr, "I/O error in write [%s].\n", strerror(errno));
				return -1;
			}
			fprintf(stderr, "I/O timed-out in write [cmd = 0x%02X].\n", cmd->command);
			return -1;
		}
		if (t->fdtyp)
			usleep(CAN_CMD_DELAY);
	
		assert(rlen > 0 && rlen < BUFLEN);

		rc = fdio(t, bcmd, rlen, TIMEOUT, IN);
		if (rc != rlen) {
			if (rc < 0) {
				fprintf(stderr, "I/O error in read [%s].\n", strerror(errno));
				return -1;
			}
			fprintf(stderr, "I/O timed-out in read [cmd = 0x%02X].\n", cmd->command);
			return -1;
		}
		
		break;
	}

	if (bcmd[rlen - 1] != RESPONSE_OK) {
		fprintf(stderr, "I/O comms error [0x%02X != '%c'].\n", bcmd[rlen - 1], RESPONSE_OK);
		return -1;
	}
	return 0;
}

/*******************************************************************************
 *
 * Test for a blank flash row
 *
 ******************************************************************************/
static inline int
isBlank(uint8_t *flash, int size)
{
	int i;

	for (i = 0; i < size; ++i)
		if (flash[i] != 0xFF)
			return 0;
	return 1;
}

/*******************************************************************************
 *
 * Upload to flash
 *
 *  Erase and Write rows. For some devices the erase row is larger than
 *  the write row.
 *
 ******************************************************************************/
int
uploadFlash(easy_t *t, int simulate, uint8_t *flash, uint32_t startaddr, uint16_t erasesize, uint8_t rowsize, int verify)
{
	struct command_packet cmd;
	uint8_t *bcmd = (uint8_t *)&cmd;
	int eaddress, raddress, i;

	/* For each erase row */
	for (eaddress = 0; eaddress < startaddr; eaddress += erasesize) {
		if (isBlank(&flash[eaddress], erasesize))
			continue;
		/* Erase then write first row */
		cmd.addru = (eaddress & 0xFF0000) >> 16;
		cmd.addrh = (eaddress & 0x00FF00) >> 8;
		cmd.addrl = (eaddress & 0x0000FF);
		cmd.command = COMMAND_FLASH_ERASE;
		if (isBlank(&flash[eaddress], rowsize)) {
			cmd.datasize = 1;
			cmd.data[0] = getChecksum(bcmd, 5);
			if (!simulate)
				if (doCommand(t, &cmd, 6, 1) < 0)
					return -1;
			if (t->info) fprintf(t->info, "ERASE FLASH ROW 0x%06X %4d BYTES PAYLOAD\n",
				eaddress, cmd.datasize - 1);
		} else { /* Erase then write */
			cmd.datasize = 1 + rowsize;
			memcpy(cmd.data, &flash[eaddress], rowsize);
			cmd.data[rowsize] = getChecksum(bcmd, 5 + rowsize);
			if (!simulate)
				if (doCommand(t, &cmd, 6 + rowsize, 1) < 0)
					return -1;
			if (t->info) fprintf(t->info, "ERASE FLASH ROW 0x%06X %4d BYTES PAYLOAD\n",
				eaddress, cmd.datasize - 1);
			if (verify) {
				cmd.addru = (eaddress & 0xFF0000) >> 16;
				cmd.addrh = (eaddress & 0x00FF00) >> 8;
				cmd.addrl = (eaddress & 0x0000FF);
				cmd.command = COMMAND_FLASH_READ;
				cmd.datasize = 1;
				cmd.data[0] = getChecksum(bcmd, 5);
				if (doCommand(t, &cmd, 6, 1 + rowsize) < 0)
					return -1;
				if (memcmp(&flash[eaddress], bcmd, rowsize) == 0) {
					if (t->info) fprintf(t->info, " VERIFY OK\n");
				} else {
					fprintf(stderr, " VERIFY ERROR\n");
				}
			}
		}
		/* For each other write row */
		for (i = rowsize; i < erasesize; i += rowsize) {
			raddress = eaddress + i;
			if (isBlank(&flash[raddress], rowsize))
				continue;
			/* Write other rows */
			cmd.addru = (raddress & 0xFF0000) >> 16;
			cmd.addrh = (raddress & 0x00FF00) >> 8;
			cmd.addrl = (raddress & 0x0000FF);
			cmd.command = COMMAND_FLASH_WRITE;
			cmd.datasize = 1 + rowsize;
			memcpy(cmd.data, &flash[raddress], rowsize);
			cmd.data[rowsize] = getChecksum(bcmd, 5 + rowsize);
			if (!simulate)
				if (doCommand(t, &cmd, 6 + rowsize, 1) < 0)
					return -1;
			if (t->info) fprintf(t->info, "WRITE FLASH ROW 0x%06X %4d BYTES PAYLOAD\n",
				raddress, cmd.datasize - 1);
			if (verify) {
				cmd.addru = (raddress & 0xFF0000) >> 16;
				cmd.addrh = (raddress & 0x00FF00) >> 8;
				cmd.addrl = (raddress & 0x0000FF);
				cmd.command = COMMAND_FLASH_READ;
				cmd.datasize = 1;
				cmd.data[0] = getChecksum(bcmd, 5);
				if (doCommand(t, &cmd, 6, 1 + rowsize) < 0)
					return -1;
				if (memcmp(&flash[raddress], bcmd, rowsize) == 0) {
					if (t->info) fprintf(t->info, " VERIFY OK\n");
				} else {
					fprintf(stderr, " VERIFY ERROR\n");
				}
			}
		}
	}
	return 0;
}

/*******************************************************************************
 *
 * Upload to EEPROM
 *
 ******************************************************************************/
int
uploadEEPROM(easy_t *t, int simulate, uint16_t *eeprom, uint16_t eesize, int verify)
{
	struct command_packet cmd;
	uint8_t *bcmd = (uint8_t *)&cmd;
	int i;

	for (i = 0; i < eesize; ++i) {
		if (eeprom[i] == 0xFFFF)
			continue;
		cmd.addru = 0;
		cmd.addrh = (i & 0x00FF00) >> 8;
		cmd.addrl = (i & 0x0000FF);
		cmd.command = COMMAND_EE_WRITE;
		cmd.datasize = 2;
		cmd.data[0] = eeprom[i];
		cmd.data[1] = getChecksum(bcmd, 6);
		if (!simulate)
			if (doCommand(t, &cmd, 7, 1) < 0)
				return -1;
		if (t->info) fprintf(t->info, "WRITE EEPROM 0x%04X = 0x%02X\n", i, eeprom[i]);
		if (!verify)
			continue;
		cmd.addru = 0;
		cmd.addrh = (i & 0x00FF00) >> 8;
		cmd.addrl = (i & 0x0000FF);
		cmd.command = COMMAND_EE_READ;
		cmd.datasize = 1;
		cmd.data[0] = getChecksum(bcmd, 5);
		if (doCommand(t, &cmd, 6, 2) < 0)
			return -1;
		if (bcmd[0] == eeprom[i]) {
			if (t->info) fprintf(t->info, " VERIFY OK\n");
		} else {
			fprintf(stderr, " VERIFY ERROR\n");
		}
	}
	return 0;
}

/*******************************************************************************
 *
 * Dump device EEPROM
 *
 ******************************************************************************/
int
dumpEEPROM(easy_t *t, uint16_t *eeprom, uint16_t eesize)
{
	struct command_packet cmd;
	uint8_t *bcmd = (uint8_t *)&cmd;
	int i, j;

	for (i = 0; i < eesize; ++i) {
		cmd.addru = 0;
		cmd.addrh = (i & 0x00FF00) >> 8;
		cmd.addrl = (i & 0x0000FF);
		cmd.command = COMMAND_EE_READ;
		cmd.datasize = 1;
		cmd.data[0] = getChecksum(bcmd, 5);
		if (doCommand(t, &cmd, 6, 2) < 0)
			return -1;
		eeprom[i] = bcmd[0];
	}
	for (i = 0; i < eesize; i += 16) {
		if (t->info) fprintf(t->info, "[%04X] ", i);
		for (j = 0; j < 16; ++j)
			if (t->info) fprintf(t->info, "%02X ", eeprom[i + j]);
		if (t->info) fputc('\n', t->info);
	}
	return 0;
}

/*******************************************************************************
 *
 * Dump device flash
 *
 ******************************************************************************/
int
dumpFlash(easy_t *t, uint8_t *flash, uint32_t startaddr, uint8_t rowsize)
{
	struct command_packet cmd;
	uint8_t *bcmd = (uint8_t *)&cmd;
	int i, j;

	for (i = 0; i < startaddr; i += rowsize) {
		cmd.addru = (i & 0xFF0000) >> 16;
		cmd.addrh = (i & 0x00FF00) >> 8;
		cmd.addrl = (i & 0x0000FF);
		cmd.command = COMMAND_FLASH_READ;
		cmd.datasize = 1;
		cmd.data[0] = getChecksum(bcmd, 5);
		if (doCommand(t, &cmd, 6, 1 + rowsize) < 0)
			return -1;
		for (j = 0; j < rowsize; ++j)
			flash[i + j] = bcmd[j];
	}
	for (i = 0; i < startaddr; i += 16) {
		if (t->info) fprintf(t->info, "[%06X] ", i);
		for (j = 0; j < 16; ++j)
			if (t->info) fprintf(t->info, "%02X ", flash[i + j]);
		if (t->info) fputc('\n', t->info);
	}
	return 0;
}

/*******************************************************************************
 *
 * HOWTO
 *
 ******************************************************************************/
void
usage(const char *msg, int err)
{
	fprintf(stderr, "USAGE: easy-loader [OPTIONS] DEVICE [HEX-FILE]\n\n");

	if (msg)
		fprintf(stderr, "%s\n\n", msg);

	fprintf(stderr, "Options:\n"
		" -e   read EEPROM\n"
		" -f   read flash\n"
		" -h   HELLO only\n"
		" -i N use CAN bus message id N\n"
		" -q   quiet\n"
		" -r   RTS toggle after serial port open\n"
		" -s   simulate erase/write\n"
		" -v   verify\n"
		
		"\n");

	exit(err);
}

/*******************************************************************************
 *
 * Take it easy, take it easy... are there any other lyrics?
 *
 ******************************************************************************/
int
main(int argc, char **argv)
{
	int opt, rc;
	int nargs = 2, eeprom_read = 0, flash_read = 0, hello_only = 0, toggle = 0, simulate = 0, verify = 0;
	char *dev, *file;
	uint8_t *flash = NULL;
	uint16_t *eeprom = NULL;

	struct hello_packet hello;
	uint8_t *bhello = (uint8_t *)&hello;
	uint8_t rowsize;
	uint16_t erasesize, eesize;
	uint32_t startaddr;

	easy_t t;
	t.info = stdout;
	t.cid = CAN_ID;

	opterr = 0;
	while ((opt = getopt(argc, argv, "efhi:rqsv")) != -1) {
		switch (opt) {
		case 'e':
			eeprom_read = 1;
			nargs = 1;
			break;
		case 'f':
			flash_read = 1;
			nargs = 1;
			break;
		case 'h':
			hello_only = 1;
			nargs = 1;
			break;
		case 'i':
			t.cid = strtol(optarg, NULL, 0);
			break;	
		case 'r':
			toggle = 1;
			break;
		case 'q':
			t.info = NULL;
			break;
		case 's':
			simulate = 1;
			break;
		case 'v':
			verify = 1;
			break;
		default:
			usage("Unknown option", EX_USAGE);
		}
	}
	argc -= optind;
	argv += optind;
	if (argc < nargs) {
		usage("Missing args", EX_USAGE);
	}

	dev = argv[0];
	if (dev[0] == '/') {
		t.fd = openDevice(dev, B115200, toggle);
		t.fdtyp = 0;
	} else {
		t.fd = openCanSock(dev);
		t.fdtyp = 1;
	}
	if (t.fd < 0) {
		fprintf(stderr, "Failed to open I/O device [%s].\n", dev);
		exit(EX_OSERR);
	}

	bhello[0] = HELLO;
	rc = fdio(&t, bhello, 1, TIMEOUT, OUT);
	if (rc != 1) {
		fprintf(stderr, "I/O timed-out in write [HELLO].\n");
		exit(EX_SOFTWARE);
	}
	
	rc = fdio(&t, bhello, sizeof(struct hello_packet), TIMEOUT, IN);
	if (rc != sizeof(struct hello_packet)) {
		fprintf(stderr, "I/O timed-out in read [HELLO].\n");
		exit(EX_SOFTWARE);
	}

	if (hello.response != RESPONSE_OK) {
		fprintf(stderr, "I/O comms error [0x%02X != '%c'].\n", hello.response, RESPONSE_OK);
		exit(EX_SOFTWARE);
	}

	rowsize = hello.row;
	erasesize = hello.erah << 8 | hello.eral;
	startaddr = hello.startu << 16 | hello.starth << 8 | hello.startl;
	eesize = hello.eeh << 8 | hello.eel;

	if (t.info) fprintf(t.info, "PIC18 BOOT LOADER START ADDRESS = 0x%06X\n", startaddr);
	if (t.info) fprintf(t.info, "PIC18 ERASE SIZE  = %d\n", erasesize);
	if (t.info) fprintf(t.info, "PIC18 ROW SIZE    = %d\n", rowsize);
	if (t.info) fprintf(t.info, "PIC18 EEPROM SIZE = %d\n", eesize);

	if (hello_only) {
		close(t.fd);
		exit(EX_OK);
	}

	eeprom = xmalloc(eesize * sizeof(uint16_t), -1);
	flash = xmalloc(startaddr * sizeof(uint8_t), -1);

	if (eeprom_read) {
		dumpEEPROM(&t, eeprom, eesize);
	} else if (flash_read) {
		dumpFlash(&t, flash, startaddr, rowsize);
	} else {
		file = argv[1];
		rc = readFile(file, flash, eeprom, startaddr, eesize);
		if (rc < 0) {
			fprintf(stderr, "Failed to open hex file [%s].\n", file);
			exit(EX_SOFTWARE);
		}
		if (rc == 0) {
			fprintf(stderr, "No data in hex file [%s].\n", file);
			exit(EX_SOFTWARE);
		}

		fixGOTO(flash, startaddr);

		if (uploadFlash(&t, simulate, flash, startaddr, erasesize, rowsize, verify) == 0) {
			uploadEEPROM(&t, simulate, eeprom, eesize, verify);
		}
	}

	xfree(flash);
	xfree(eeprom);
	close(t.fd);
	exit(EX_OK);
}
