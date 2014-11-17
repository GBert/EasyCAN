/*
 * Take it Easy Loader for the Wellington Boot Loader.
 *
 * Based on Pirate Loader version 1.0.2.
 *
 * Modifications by Agent Easy & The Duke of Welling Town.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Code, code modifications, and hardware created by Dangerous
 * Prototypes are released into the public domain under the
 * Creative Commons '0' license, as noted in the file header.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>
#include <sysexits.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>

#define EASY_LOADER_VERSION "0.0.0"

#define STR_EXPAND(tok) #tok
#define OS_NAME(tok) STR_EXPAND(tok)

#if !defined OS
#define OS UNIX
#endif


/*
 * PIC18F26K80
 */
#define PIC_FLASHSIZE		(65536)
#define PIC_NUM_PAGES		(1024)	/* 65536 / 64 */
#define PIC_NUM_ROWS_IN_PAGE	(1)
#define PIC_NUM_WORDS_IN_ROW	(32)	/* 64 bytes */
#define PIC_WORD_SIZE		(2)

#define PIC_ROW_SIZE		(PIC_NUM_WORDS_IN_ROW * PIC_WORD_SIZE)
#define PIC_PAGE_SIZE		(PIC_NUM_ROWS_IN_PAGE * PIC_ROW_SIZE)

#define PIC_ROW_ADDR(p,r)	(((p) * PIC_PAGE_SIZE) + ((r) * PIC_ROW_SIZE))
#define PIC_WORD_ADDR(p,r,w)	(PIC_ROW_ADDR(p,r) + ((w) * PIC_WORD_SIZE))
#define PIC_PAGE_ADDR(p)	(PIC_PAGE_SIZE * (p))

struct header {
	uint8_t addru, addrh, addrl;
	uint8_t command;
	uint8_t datasize;
} __attribute__((packed));

#define COMMAND_OFFSET		(3)
#define LENGTH_OFFSET		(4)
#define PAYLOAD_OFFSET		(5)
#define HEADER_LENGTH		PAYLOAD_OFFSET

#define BLSTART (0x00FE00)	// Bootloader start address

#define HELLO (0xC1)

#define COMMAND_ERASE (1)
#define COMMAND_WRITE_FLASH (2)
#define COMMAND_WRITE_EEPROM (4)
#define COMMAND_WRITE_CONFIG (8)

#define RESPONSE_OK 'K'
#define RESPONSE_ERROR_CHECKSUM   'N'
#define RESPONSE_ERROR_VERIFY     'V'
#define RESPONSE_ERROR_PROTECTION 'P'
#define RESPONSE_ERROR_UNKNOWN    'U'

#define TIMEOUT (5)
#define IN (0)
#define OUT (1)

#define BUFLEN (512)
#define BUFMAX (BUFLEN - 1)

uint8_t g_verbose = 0;
uint8_t g_hello_only = 0;
uint8_t g_simulate = 0;
uint8_t g_reset_rts = 0;
const char *g_device_path = NULL;
const char *g_hexfile_path = NULL;

/******************************************************************************/

void *
xmalloc(size_t n, int c)
{
	void *s = malloc(n);
	if (s == NULL)
		exit(EX_OSERR);
	return memset(s, c, n);
}

void *
xfree(void *s)
{
	if (s)
		free(s);
	return NULL;
}

/******************************************************************************/

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

int
fdio(int fd, uint8_t *buffer, int buflen, long timeout, int io)
{
	int rc;
	int nb = 0;
	
	while (buflen > 0) {
		rc = fdselect(fd, timeout, io);
		if (rc < 0) {
			printf("select() error: %s\n", strerror(errno));
			return rc;
		}
		if (rc == 0) {
			printf("select() timed-out\n");
			return 0;
		}
		rc = fdreadwrite(fd, buffer, buflen, io);
		if (rc < 0) {
			printf("read/write() error: %s\n", strerror(errno));
			return rc;
		}
		if (rc == 0) {
			continue;
		}
		buffer += rc;
		buflen -= rc;
		nb += rc;
	}
	return nb;
}

/******************************************************************************/

int
sendCommandAndWaitForResponse(int fd, uint8_t *command)
{
	int rc = 0, len;
	uint8_t response;
	
	len = HEADER_LENGTH + command[LENGTH_OFFSET];
	rc = fdio(fd, command, len, TIMEOUT, OUT);
	if (rc != len) {
		puts("ERROR");
		return -1;
	}
	
	rc = fdio(fd, &response, 1, TIMEOUT, IN);
	if (rc != 1) {
		puts("ERROR");
		return -1;
	}
	if (response != RESPONSE_OK) {
		fprintf(stderr, "ERROR: response = %c\n", response);
		return -1;
	}
	return 0;
}

/******************************************************************************/

uint8_t
hexdec(const char *pc)
{
	uint8_t temp = 0;

	if (pc[0] >= 'a' && pc[0] <= 'f') {
		temp = pc[0] - 'a' + 10;
	}
	else if (pc[0] >= 'A' && pc[0] <= 'F') {
		temp = pc[0] - 'A' + 10;		
	}
	else if (pc[0] >= '0' && pc[0] <= '9') {
		temp = pc[0] - '0';
	}

	temp = temp << 4;
	
	if (pc[1] >= 'a' && pc[1] <= 'f') {
		temp |= pc[1] - 'a' + 10;
	}
	else if (pc[1] >= 'A' && pc[1] <= 'F') {
		temp |= pc[1] - 'A' + 10;		
	}
	else if (pc[1] >= '0' && pc[1] <= '9') {
		temp |= pc[1] - '0';
	}
	
	return (temp);
}

int
readHEX(const char *file, uint8_t *bout, uint8_t *pages_used)
{
	static const uint32_t HEX_DATA_OFFSET = 4;
	uint8_t linebin[256] = {0};
	uint8_t* data = (linebin + HEX_DATA_OFFSET);
	uint8_t hex_csum, hex_type, hex_len;
	uint32_t hex_addr;
	uint32_t hex_base_addr = 0;
	uint32_t hex_words = 0;
	
	uint32_t f_addr = 0;
	uint32_t o_addr = 0;
	
	uint32_t num_words = 0;
	
	char line[BUFLEN];
	char *pc;
	char *pline = line + 1;
	int res = 0;
	int binlen = 0;
	int line_no = 0;
	int i = 0;
	
	FILE *fp = fopen(file, "rb");
	if (!fp) {
		return -1;
	}
	while (fgets(line, BUFLEN, fp) != NULL) {
		line[BUFMAX] = '\0';

		line_no++;
		
		if (line[0] != ':')
			continue;
		
		res = strlen(pline);
		pc = pline + res - 1;
		
		while (pc > pline && *pc <= ' ') {
			*pc-- = 0;
			res--;
		}
		
		if (res & 1 || res < 10) {
			fprintf(stderr, "Incorrect number of characters on line %d:%d\n", line_no, res);
			return -1;
		}
		
		hex_csum = 0;
		for (pc = pline, i = 0; i < res; i += 2, pc += 2) {
			linebin[i >> 1] = hexdec(pc);
			hex_csum += linebin[i >> 1];
		}

		binlen = res / 2;
		
		if (hex_csum != 0) {
			fprintf(stderr, "Checksum does not match, line %d\n", line_no);
			return -1;
		}
		
		hex_addr = (linebin[1] << 8) | linebin[2];
		hex_len = linebin[0];
		hex_type = linebin[3];
		
		if (binlen - (1 + 2 + 1 + hex_len + 1) != 0) {
			fprintf(stderr, "Incorrect number of bytes, line %d\n", line_no);
			return -1;
		}
		
		if (hex_type == 0x00) {

			f_addr = (hex_base_addr | (hex_addr)); // PCU

			if ((hex_len % PIC_WORD_SIZE) && (f_addr < PIC_FLASHSIZE)) {
				fprintf(stderr, "Misaligned data, line %d\n", line_no);
				return -1;
			}

			if (f_addr >= PIC_FLASHSIZE) {
				printf("Current record address 0x%04X is higher than maximum allowed, line %d", f_addr, line_no);
				printf(" - ignoring data (probably CONFIG ?)\n");
			}
			
			if (f_addr < PIC_FLASHSIZE) { 

				hex_words = hex_len / PIC_WORD_SIZE;
				o_addr = (f_addr / 2) * PIC_WORD_SIZE; // BYTES

				for (i = 0; i < hex_words; ++i) {
				
					bout[o_addr + 0] = data[i * PIC_WORD_SIZE];
					bout[o_addr + 1] = data[i * PIC_WORD_SIZE + 1];

					pages_used[(o_addr / PIC_PAGE_SIZE)] = 1;
				
					o_addr += PIC_WORD_SIZE;
					num_words++;
				}
			}

		}
		else if (hex_type == 0x04 && hex_len == 2) {
			hex_base_addr = (linebin[4] << 24) | (linebin[5] << 16);
		}
		else if (hex_type == 0x01) {
			break; // EOF
		}
		else {
			fprintf(stderr, "Unsupported record type %02X, line %d\n", hex_type, line_no);
			return -1;
		}
	}
	fclose(fp);

	return num_words;
}

/******************************************************************************/

static inline uint8_t
makeChecksum(uint8_t *buffer, int buflen)
{
	int i;
	uint8_t csum = 0;

	for (i = 0; i < buflen; ++i)
		csum -= buffer[i];

	return csum;
}

static inline void
dumpHex(uint8_t *buffer, int buflen)
{
	int i;
	
	for (i = 0; i < buflen; ++i)
		printf("%02X ", buffer[i]);

	putchar('\n');
}

int
sendFirmware(int fd, uint8_t *data, uint8_t *pages_used)
{
	uint32_t u_addr;
	uint32_t page = 0;
	uint32_t done = 0;
	uint32_t row = 0;
	uint8_t command[256] = {0};
	
	for (page = 0; page < PIC_NUM_PAGES; ++page) {
		
		u_addr = page * (PIC_NUM_WORDS_IN_ROW * PIC_WORD_SIZE * PIC_NUM_ROWS_IN_PAGE);
		
		if (pages_used[page] != 1) {
			continue;
		}
		
		if (u_addr >= PIC_FLASHSIZE) {
			fprintf(stderr, "Address out of flash\n");
			return -1;
		}
		
		// Erase page
		command[0] = (u_addr & 0x00FF0000) >> 16;
		command[1] = (u_addr & 0x0000FF00) >> 8;
		command[2] = (u_addr & 0x000000FF);
		command[COMMAND_OFFSET] = 0x01; // Erase command
		command[LENGTH_OFFSET ] = 0x01; // 1 byte, checksum
		command[PAYLOAD_OFFSET] = makeChecksum(command, 5);
		
		if (g_verbose) {
			dumpHex(command, HEADER_LENGTH + command[LENGTH_OFFSET]);
		}
		
		printf("Erasing page %u, %04X...", page, u_addr);
		if (g_simulate == 0 && sendCommandAndWaitForResponse(fd, command) < 0) {
			return -1;
		}
		
		puts("OK");
		
		// Write n rows
		for (row = 0; row < PIC_NUM_ROWS_IN_PAGE; row ++, u_addr += (PIC_NUM_WORDS_IN_ROW * 2)) {

			command[0] = (u_addr & 0x00FF0000) >> 16;
			command[1] = (u_addr & 0x0000FF00) >> 8;
			command[2] = (u_addr & 0x000000FF);
			command[COMMAND_OFFSET] = 0x02; // Write command
			command[LENGTH_OFFSET ] = PIC_ROW_SIZE + 0x01; // Data length + checksum
			
			memcpy(&command[PAYLOAD_OFFSET], &data[PIC_ROW_ADDR(page, row)], PIC_ROW_SIZE);
			
			command[PAYLOAD_OFFSET + PIC_ROW_SIZE] = makeChecksum(command, HEADER_LENGTH + PIC_ROW_SIZE);
			
			printf("Writing page %u row %u, %04X...", page, row + page * PIC_NUM_ROWS_IN_PAGE, u_addr);
			
			if (g_simulate == 0 && sendCommandAndWaitForResponse(fd, command) < 0) {
				return -1;
			}
			
			puts("OK");
			
			sleep(0);
			
			if (g_verbose) {
				dumpHex(command, HEADER_LENGTH + command[LENGTH_OFFSET]);
			}
			done += PIC_ROW_SIZE;
		}
	}
	return done;
}

/******************************************************************************/

void
fixJumps(uint8_t *bin_buff, uint8_t *pages_used)
{
	uint32_t loadusr;
	
	loadusr = BLSTART - 4; 

	if (g_verbose) {
		printf("loadusr = 0x%04X, page = %u\n", loadusr, loadusr / PIC_PAGE_SIZE);
		printf("blstart = 0x%04X, page = %u\n", BLSTART, BLSTART / PIC_PAGE_SIZE);
	}
	
	bin_buff[loadusr + 0] = bin_buff[0];		// GOTO application
	bin_buff[loadusr + 1] = bin_buff[1];
	bin_buff[loadusr + 2] = bin_buff[2];
	bin_buff[loadusr + 3] = bin_buff[3];

	pages_used[loadusr / PIC_PAGE_SIZE] = 1;	// loadusr page used
	
	/*
	 * The following is redundant when PROT_GOTO is defined in the boot loader
	 */

	bin_buff[0] = ((BLSTART & 0x00001FE ) >> 1);	// GOTO bootloader
	bin_buff[1] = 0xEF;
	bin_buff[2] = ((BLSTART & 0x001FE00 ) >> 9);
	bin_buff[3] = ((BLSTART & 0x01E0000 ) >> 17) | 0xF0;
}

/******************************************************************************/

int
openSerial(speed_t baudrate)
{
	int fd, status;
	struct termios options;

	fd = open(g_device_path, O_RDWR | O_NOCTTY | O_NONBLOCK);
	if (fd < 0)
		return fd;

	fcntl(fd, F_SETFL, O_NONBLOCK | fcntl(fd, F_GETFL));
	
	memset(&options, 0, sizeof(options));

	options.c_cflag = CS8 | CLOCAL | CREAD;
	
	cfsetispeed(&options, baudrate);
	cfsetospeed(&options, baudrate);
	
	tcsetattr(fd, TCSANOW, &options);

	tcflush(fd, TCIOFLUSH);

        if (g_reset_rts) {
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

/******************************************************************************/

int
parseCommandLine(int argc, const char **argv)
{
	int i;
	
	for (i = 1; i < argc; ++i) {
		if (!strncmp(argv[i], "--hex=", 6)) {
			g_hexfile_path = argv[i] + 6;
		}
		else if (!strncmp(argv[i], "--dev=", 6)) {
			g_device_path = argv[i] + 6;
                }
		else if (!strcmp(argv[i], "--reset_rts")) {
                        g_reset_rts = 1;
		}
		else if (!strcmp(argv[i], "--verbose")) {
			g_verbose = 1;
		}
		else if (!strcmp(argv[i], "--hello")) {
			g_hello_only = 1;
		}
		else if (!strcmp(argv[i], "--simulate")) {
			g_simulate = 1;
		}
		else if (!strcmp(argv[i], "--help")) {
			argc = 1;
			break;
		}
		else {
			fprintf(stderr, "Unknown arg %s, please use %s --help for usage\n", argv[i], argv[0]);
			return -1;
		}
	}
	if (argc == 1) {
		printf("Usage:\n\n");
		printf("%s --dev=/dev/ttyXXX --hello [--reset_rts]\n", argv[0]);
		printf("%s --dev=/dev/ttyXXX --hex=file.hex [--reset_rts] [--verbose]\n", argv[0]);
		printf("%s --simulate --hex=file.hex [--verbose]\n\n", argv[0]);
		return 0;
	}
	return 1;
}

/******************************************************************************/

int
main(int argc, const char **argv)
{
	int dev_fd = -1, res = -1;
	uint8_t	buffer[256] = {0};
	uint8_t	pages_used[PIC_NUM_PAGES] = {0};
	uint8_t *bin_buff = NULL;
	uint16_t deviceid;
	uint8_t vermaj, vermin, verrev;

	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	puts(" Take it Easy Loader for the Wellington Boot Loader\n");
	puts(" Loader version: " EASY_LOADER_VERSION);
	puts(" Operating system: " OS_NAME(OS));
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	if ((res = parseCommandLine(argc, argv)) < 0) {
		exit(EX_USAGE);
	}
	else if (res == 0) {
		exit(EX_OK);
	}

	if (!g_hello_only) {
		
		if (!g_hexfile_path) {
			fprintf(stderr, "Please specify hexfile path --hex=file.hex\n");
			exit(EX_USAGE);
		}
	
		bin_buff = (uint8_t *)xmalloc(256 << 10, -1); // 256KB
		
		printf("Parsing HEX file [%s]\n", g_hexfile_path);
		
		res = readHEX(g_hexfile_path, bin_buff, pages_used);
		if (res <= 0 || res > PIC_FLASHSIZE) {
			fprintf(stderr, "Could not load HEX file, result = %d\n", res);
			xfree(bin_buff);
			exit(EX_SOFTWARE);
		}
		
		printf("Found %d words (%d bytes)\n", res, res * PIC_WORD_SIZE);
		
		printf("Fixing bootloader/userprogram jumps\n");
		fixJumps(bin_buff, pages_used);
	}
	
	if (g_simulate) {
		sendFirmware(dev_fd, bin_buff, pages_used);
		xfree(bin_buff);
		exit(EX_OK);
	}
		
	if (!g_device_path) {
		fprintf(stderr, "Please specify serial device path --dev=/dev/ttyXXX\n");
		xfree(bin_buff);
		exit(EX_USAGE);
	}
	
	printf("Opening serial device %s...", g_device_path);
	
	dev_fd = openSerial(B115200);
	if (dev_fd < 0) {
		fprintf(stderr, "ERROR: Could not open %s\n", g_device_path);
		xfree(bin_buff);
		exit(EX_OSERR);
	}

	puts("OK");
	
	printf("Sending Hello to the Bootloader...");
	
	buffer[0] = HELLO;
	res = fdio(dev_fd, buffer, 1, TIMEOUT, OUT);
	if (res != 1) {
		fprintf(stderr, "ERROR: write timed-out: %d\n", res);
		close(dev_fd);
		xfree(bin_buff);
		exit(EX_SOFTWARE);
	}
	
	res = fdio(dev_fd, buffer, 4, TIMEOUT, IN);
	if (res != 4 || buffer[3] != RESPONSE_OK) {
		fprintf(stderr, "ERROR: No reply from the bootloader, or invalid reply received: %d\n", res);
		fprintf(stderr, "Please make sure that GND and TX/RX are connected, re-plug the device and try again\n");
		close(dev_fd);
		xfree(bin_buff);
		exit(EX_SOFTWARE);
	}

	puts("OK\n");
	
	deviceid = ((0x80 & buffer[2]) << 2) | ((0x80 & buffer[1]) << 1) | buffer[0];
	vermaj = buffer[1] & 0x7F;
	vermin = (buffer[2] & 0x7F) >> 4;
	verrev = buffer[2] & 0x0F;

	printf("Device ID: %s 0x%04X\n", (deviceid == 436) ? "PIC18F26K80" : "UNKNOWN", deviceid);
	printf("Bootloader version: %d.%d.%d\n", vermaj, vermin, verrev);

	if (deviceid != 436) {
		fprintf(stderr, "ERROR: Unsupported device only PIC18F26K80 is supported\n");
		close(dev_fd);
		xfree(bin_buff);
		exit(EX_SOFTWARE);
	}
	
	if (!g_hello_only) {
		res = sendFirmware(dev_fd, bin_buff, pages_used);
		if (res > 0) {
			puts("\nFirmware updated successfully! :)");
		} else {
			puts("\nError updating firmware! :(");
			close(dev_fd);
			xfree(bin_buff);
			exit(EX_SOFTWARE);
		}
		
	}

	close(dev_fd);
	xfree(bin_buff);
	exit(EX_OK);
}
