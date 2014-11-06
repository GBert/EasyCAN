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
 * Various UNIX header files
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
#define RESPONSE_OK 'K'
#define RESPONSE_ERROR_CHECKSUM 'N'
#define RESPONSE_ERROR_UNKNOWN  'U'

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
#define IN  (0)
#define OUT (1)

/*
 * Output stream for information
 */
FILE *info;

/*******************************************************************************
 * Open serial device
 *
 * Toggle RTS if required
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
	
	memset(&options, 0, sizeof(options));

	options.c_cflag = CS8 | CLOCAL | CREAD;
	
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
int
fdselect(int fd, long timeout, int io)
{
	int rc;
	struct timeval tv;
	fd_set fdset;
	
	while (1) {
		tv.tv_sec = timeout;
		tv.tv_usec = 0;

		FD_ZERO(&fdset);
		FD_SET(fd, &fdset);

		if (io == IN)
			rc = select(fd + 1, &fdset, NULL, NULL, &tv);
		else /* OUT */
			rc = select(fd + 1, NULL, &fdset, NULL, &tv);
                if (rc < 0) {
                        if (errno == EINTR)
                                continue;
                }
                return rc;
	}
	/* Not reached */
}

/*******************************************************************************
 *
 * Read/write
 *
 ******************************************************************************/
int
fdreadwrite(int fd, uint8_t *buffer, int buflen, int io)
{
	int rc;
	
	while (1) {
		if (io == IN)
			rc = read(fd, buffer, buflen);
		else /* OUT */
			rc = write(fd, buffer, buflen);
		if (rc < 0) {
                        if (errno == EINTR || errno == EAGAIN)
                                continue;
                }
		return rc;
	}
	/* Not reached */
}

/*******************************************************************************
 *
 * Non-blocking I/O
 *
 ******************************************************************************/
int
fdio(int fd, uint8_t *buffer, int buflen, long timeout, int io)
{
	int rc;
	int nb = 0;
	
	while (buflen > 0) {
		rc = fdselect(fd, timeout, io);
		if (rc < 0) {
			return rc;
		}
		if (rc == 0) {
			return 0;
		}
		rc = fdreadwrite(fd, buffer, buflen, io);
		if (rc < 0) {
			return rc;
		}
		if (rc == 0) {
			return nb; /* EOF */
		}
		buffer += rc;
		buflen -= rc;
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
	flash[0] = ((startaddr & 0x00001FE ) >> 1);
	flash[1] = 0xEF;
	flash[2] = ((startaddr & 0x001FE00 ) >> 9);
	flash[3] = ((startaddr & 0x01E0000 ) >> 17) | 0xF0;
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
doCommand(int fd, uint8_t *buffer, int blen, int rlen)
{
	int rc;
	
	rc = fdio(fd, buffer, blen, TIMEOUT, OUT);
	if (rc != blen) {
		fprintf(stderr, "Serial timed-out [%d].\n", rc);
		return -1;
	}
	
	assert(rlen < BUFLEN);

	rc = fdio(fd, buffer, rlen, TIMEOUT, IN);
	if (rc != rlen) {
		fprintf(stderr, "Serial timed-out [%d].\n", rc);
		return -1;
	}

	if (buffer[rlen - 1] != RESPONSE_OK) {
		fprintf(stderr, "Serial comms error [0x%02X != '%c'].\n",
			buffer[rlen - 1], RESPONSE_OK);
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
uploadFlash(int fd, int simulate, uint8_t *flash, uint32_t startaddr, uint16_t erasesize, uint8_t rowsize, int verify)
{
	struct command_packet p;
	uint8_t *buffer = (uint8_t *)&p;
	int eaddress, raddress, i;

	/* For each erase row */
	for (eaddress = 0; eaddress < startaddr; eaddress += erasesize) {
		if (isBlank(&flash[eaddress], erasesize))
			continue;
		/* Erase then write first row */
		p.addru = (eaddress & 0xFF0000) >> 16;
		p.addrh = (eaddress & 0x00FF00) >> 8;
		p.addrl = (eaddress & 0x0000FF);
		p.command = COMMAND_FLASH_ERASE;
		if (isBlank(&flash[eaddress], rowsize)) {
			p.datasize = 1;
			p.data[0] = getChecksum(buffer, 5);
			if (!simulate)
				if (doCommand(fd, buffer, 6, 1) < 0)
					return -1;
			if (info) fprintf(info, "ERASE FLASH ROW 0x%06X %4d BYTES PAYLOAD\n",
				eaddress, p.datasize - 1);
		} else { /* Erase then write */
			p.datasize = 1 + rowsize;
			memcpy(p.data, &flash[eaddress], rowsize);
			p.data[rowsize] = getChecksum(buffer, 5 + rowsize);
			if (!simulate)
				if (doCommand(fd, buffer, 6 + rowsize, 1) < 0)
					return -1;
			if (info) fprintf(info, "ERASE FLASH ROW 0x%06X %4d BYTES PAYLOAD\n",
				eaddress, p.datasize - 1);
			if (verify) {
				p.addru = (eaddress & 0xFF0000) >> 16;
				p.addrh = (eaddress & 0x00FF00) >> 8;
				p.addrl = (eaddress & 0x0000FF);
				p.command = COMMAND_FLASH_READ;
				p.datasize = 1;
				p.data[0] = getChecksum(buffer, 5);
				if (doCommand(fd, buffer, 6, 1 + rowsize) < 0)
					return -1;
				if (memcmp(&flash[eaddress], buffer, rowsize) == 0) {
					if (info) fprintf(info, " VERIFY OK\n");
				} else {
					if (info) fprintf(info, " VERIFY FAILED\n");
				}
			}
		}
		/* For each other write row */
		for (i = rowsize; i < erasesize; i += rowsize) {
			raddress = eaddress + i;
			if (isBlank(&flash[raddress], rowsize))
				continue;
			/* Write other rows */
			p.addru = (raddress & 0xFF0000) >> 16;
			p.addrh = (raddress & 0x00FF00) >> 8;
			p.addrl = (raddress & 0x0000FF);
			p.command = COMMAND_FLASH_WRITE;
			p.datasize = 1 + rowsize;
			memcpy(p.data, &flash[raddress], rowsize);
			p.data[rowsize] = getChecksum(buffer, 5 + rowsize);
			if (!simulate)
				if (doCommand(fd, buffer, 6 + rowsize, 1) < 0)
					return -1;
			if (info) fprintf(info, "WRITE FLASH ROW 0x%06X %4d BYTES PAYLOAD\n",
				raddress, p.datasize - 1);
			if (verify) {
				p.addru = (raddress & 0xFF0000) >> 16;
				p.addrh = (raddress & 0x00FF00) >> 8;
				p.addrl = (raddress & 0x0000FF);
				p.command = COMMAND_FLASH_READ;
				p.datasize = 1;
				p.data[0] = getChecksum(buffer, 5);
				if (doCommand(fd, buffer, 6, 1 + rowsize) < 0)
					return -1;
				if (memcmp(&flash[raddress], buffer, rowsize) == 0) {
					if (info) fprintf(info, " VERIFY OK\n");
				} else {
					if (info) fprintf(info, " VERIFY FAILED\n");
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
uploadEEPROM(int fd, int simulate, uint16_t *eeprom, uint16_t eesize, int verify)
{
	struct command_packet p;
	uint8_t *buffer = (uint8_t *)&p;
	int i;

	for (i = 0; i < eesize; ++i) {
		if (eeprom[i] == 0xFFFF)
			continue;
		p.addru = 0;
		p.addrh = (i & 0x00FF00) >> 8;
		p.addrl = (i & 0x0000FF);
		p.command = COMMAND_EE_WRITE;
		p.datasize = 2;
		p.data[0] = eeprom[i];
		p.data[1] = getChecksum(buffer, 6);
		if (!simulate)
			if (doCommand(fd, buffer, 7, 1) < 0)
				return -1;
		if (info) fprintf(info, "WRITE EEPROM 0x%04X = 0x%02X\n", i, eeprom[i]);
		if (!verify)
			continue;
		p.addru = 0;
		p.addrh = (i & 0x00FF00) >> 8;
		p.addrl = (i & 0x0000FF);
		p.command = COMMAND_EE_READ;
		p.datasize = 1;
		p.data[0] = getChecksum(buffer, 5);
		if (doCommand(fd, buffer, 6, 2) < 0)
			return -1;
		if (buffer[0] != eeprom[i]) {
			if (info) fprintf(info, " VERIFY ERROR\n");
		} else {
			if (info) fprintf(info, " VERIFY OK\n");
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
dumpEEPROM(int fd, uint16_t *eeprom, uint16_t eesize)
{
	struct command_packet p;
	uint8_t *buffer = (uint8_t *)&p;
	int i, j;

	for (i = 0; i < eesize; ++i) {
		p.addru = 0;
		p.addrh = (i & 0x00FF00) >> 8;
		p.addrl = (i & 0x0000FF);
		p.command = COMMAND_EE_READ;
		p.datasize = 1;
		p.data[0] = getChecksum(buffer, 5);
		if (doCommand(fd, buffer, 6, 2) < 0)
			return -1;
		eeprom[i] = buffer[0];
	}
	for (i = 0; i < eesize; i += 16) {
		if (info) fprintf(info, "[%04X] ", i);
		for (j = 0; j < 16; ++j)
			if (info) fprintf(info, "%02X ", eeprom[i + j]);
		fputc('\n', info);
	}
	return 0;
}

/*******************************************************************************
 *
 * Dump device flash
 *
 ******************************************************************************/
int
dumpFlash(int fd, uint8_t *flash, uint32_t startaddr, uint8_t rowsize)
{
	struct command_packet p;
	uint8_t *buffer = (uint8_t *)&p;
	int i, j;

	for (i = 0; i < startaddr; i += rowsize) {
		p.addru = (i & 0xFF0000) >> 16;
		p.addrh = (i & 0x00FF00) >> 8;
		p.addrl = (i & 0x0000FF);
		p.command = COMMAND_FLASH_READ;
		p.datasize = 1;
		p.data[0] = getChecksum(buffer, 5);
		if (doCommand(fd, buffer, 6, 1 + rowsize) < 0)
			return -1;
		for (j = 0; j < rowsize; ++j)
			flash[i + j] = buffer[j];
	}
	for (i = 0; i < startaddr; i += 16) {
		if (info) fprintf(info, "[%06X] ", i);
		for (j = 0; j < 16; ++j)
			if (info) fprintf(info, "%02X ", flash[i + j]);
		fputc('\n', info);
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
	fprintf(stderr, "USAGE: easy-loader [OPTIONS] TTY-DEVICE [HEX-FILE]\n\n");

	if (msg)
		fprintf(stderr, "%s\n\n", msg);

	fprintf(stderr, "Options:\n"
		" -e read EEPROM\n"
		" -f read flash\n"
		" -h HELLO only\n"
		" -q quiet\n"
		" -r RTS toggle after serial port open\n"
		" -s simulate erase/write\n"
		" -v verify\n"
		
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
        int opt, fd, rc;
	int nargs = 2, eeprom_read = 0, flash_read = 0, hello_only = 0, toggle = 0, simulate = 0, verify = 0;
	char *dev, *file;
	uint8_t *flash = NULL, hello;
	uint16_t *eeprom = NULL;

	struct hello_packet p;
	uint8_t rowsize;
	uint16_t erasesize, eesize;
	uint32_t startaddr;

	info = stdout;
        opterr = 0;
        while ((opt = getopt(argc, argv, "efhrqsv")) != -1) {
		switch (opt) {
		case 'e':
			eeprom_read = 1;
			nargs--;
			break;
		case 'f':
			flash_read = 1;
			nargs--;
			break;
		case 'h':
			hello_only = 1;
			nargs--;
			break;
		case 'r':
			toggle = 1;
			break;
		case 'q':
			info = NULL;
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
	fd = openDevice(dev, B115200, toggle);
	if (fd < 0) {
		fprintf(stderr, "Failed to open serial device [%s].\n", dev);
		exit(EX_OSERR);
	}

	hello = HELLO;
	rc = fdio(fd, &hello, 1, TIMEOUT, OUT);
	if (rc != 1) {
		fprintf(stderr, "Serial timed-out [%d].\n", rc);
		exit(EX_SOFTWARE);
	}
	
	rc = fdio(fd, (uint8_t *)&p, sizeof(struct hello_packet), TIMEOUT, IN);
	if (rc != sizeof(struct hello_packet)) {
		fprintf(stderr, "Serial timed-out [%d].\n", rc);
		exit(EX_SOFTWARE);
	}

	if (p.response != RESPONSE_OK) {
		fprintf(stderr, "Serial comms error [0x%02X != '%c'].\n", p.response, RESPONSE_OK);
		exit(EX_SOFTWARE);
	}

	rowsize = p.row;
	erasesize = p.erah << 8 | p.eral;
	startaddr = p.startu << 16 | p.starth << 8 | p.startl;
	eesize = p.eeh << 8 | p.eel;

	if (info) fprintf(info, " PIC18 BOOT LOADER START ADDRESS = 0x%06X\n", startaddr);
	if (info) fprintf(info, " PIC18 ERASE SIZE  = %d\n", erasesize);
	if (info) fprintf(info, " PIC18 ROW SIZE    = %d\n", rowsize);
	if (info) fprintf(info, " PIC18 EEPROM SIZE = %d\n", eesize);

	if (hello_only) {
		close(fd);
		exit(EX_OK);
	}

	eeprom = xmalloc(eesize * sizeof(uint16_t), -1);
	flash = xmalloc(startaddr * sizeof(uint8_t), -1);

	if (eeprom_read) {
		dumpEEPROM(fd, eeprom, eesize);
	} else if (flash_read) {
		dumpFlash(fd, flash, startaddr, rowsize);
	} else {
		file = argv[1];
		rc = readFile(file, flash, eeprom, startaddr, eesize);
		if (rc < 0) {
			fprintf(stderr, "Failed to open hex file [%s].\n", file);
			exit(EX_SOFTWARE);
		}
		if (rc == 0) {
			fprintf(stderr, "No data in file [%s].\n", file);
			exit(EX_SOFTWARE);
		}
	
		fixGOTO(flash, startaddr);

		if (uploadFlash(fd, simulate, flash, startaddr, erasesize, rowsize, verify) == 0) {
			uploadEEPROM(fd, simulate, eeprom, eesize, verify);
		}
	}

	xfree(flash);
	xfree(eeprom);
	close(fd);
	exit(EX_OK);
}
