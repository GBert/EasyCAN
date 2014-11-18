/*------------------------------------------------------------------------------
;
; Title:	Can-Can Act 1
;
; Copyright:	Copyright (c) 2014 The Duke of Welling Town
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
 * This program has no relation to a 19th century French dance-hall dance.
 * This is purely co-incidental. You are not discouraged, however, from dancing
 * along when using this program.
 */

/*
 * Various UNIX and Linux header files
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
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
#include <sys/resource.h>
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
 * Input buffer
 */
#define BUFLEN (128)

/*
 * I/O time out in seconds
 */
#define TIMEOUT (2)

/*
 * Baud rate lookup
 */
typedef struct {
	uint32_t baud;
	speed_t speed;
} baudrate_t;

/*
 * Can-can session
 */
typedef struct {
	int dir;	/* Direction 0=can->tty, 1=tty->can */
	int fdtty;	/* TTY descriptor                   */
	int csock;	/* CAN socket                       */
	int cid;        /* CAN bus id                       */ 
	uint32_t delay; /* Rate delay in microseconds       */
} session_t;

/*******************************************************************************
 *
 * Open serial device
 *
 ******************************************************************************/
int
openDevice(const char *dev, speed_t speed)
{
	int fd;
	struct termios options;
	unsigned int arg, status;

	fd = open(dev, O_RDWR | O_NOCTTY | O_NONBLOCK);
	if (fd < 0) {
		return fd;
	}
	if (fcntl(fd, F_SETFL, O_NONBLOCK | fcntl(fd, F_GETFL)) < 0) {
		close(fd);
		return -1;
	}
	if (tcgetattr(fd, &options) < 0) {
		close(fd);
		return -1;
	}

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

	if (cfsetispeed(&options, speed) < 0) {
		close(fd);
		return -1;
	}
	if (cfsetospeed(&options, speed) < 0) {
		close(fd);
		return -1;
	}
	if (tcsetattr(fd, TCSANOW, &options) < 0) {
		close(fd);
		return -1;
	}
	if (tcflush(fd, TCIOFLUSH) < 0) {
		close(fd);
		return -1;
	}

	/* modify RTS for EasyCAN */
	status = ioctl(fd, TIOCMGET, &arg);
	arg &= ~TIOCM_RTS;
	ioctl(fd, TIOCMSET, &arg);

	return fd;
}

/*******************************************************************************
 *
 * Return `speed_t' for Given Baud Rate
 *
 ******************************************************************************/
speed_t
serial_speed(uint32_t baudrate)
{
	static baudrate_t rates[] = {
	{0, B0},
	{50, B50},
	{75, B75},
	{110, B110},
	{134, B134},
	{150, B150},
	{200, B200},
	{300, B300},
	{600, B600},
	{1200, B1200},
	{1800, B1800},
	{2400, B2400},
	{4800, B4800},
#ifdef B7200
	{7200, B7200},
#endif
	{9600, B9600},
#ifdef B14400
	{14400, B14400},
#endif
#ifdef B19200
	{19200, B19200},
#else
	{19200, EXTA},
#endif
#ifdef B28800
	{28800, B28800},
#endif
#ifdef B38400
	{38400, B38400},
#else
	{38400, EXTB},
#endif
#ifdef B57600
	{57600, B57600},
#endif
#ifdef B76800
	{76800, B76800},
#endif
#ifdef B115200
	{115200, B115200},
#endif
#ifdef B230400
	{230400, B230400},
#endif
#ifdef B460800
	{460800, B460800},
#endif
#ifdef B500000
	{500000, B500000},
#endif
#ifdef B576000
	{576000, B576000},
#endif
#ifdef B921600
	{921600, B921600},
#endif
#ifdef B1000000
	{1000000, B1000000},
#endif
#ifdef B1152000
	{1152000, B1152000},
#endif
#ifdef B1500000
	{1500000, B1500000},
#endif
#ifdef B2000000
	{2000000, B2000000},
#endif
#ifdef B2500000
	{2500000, B2500000},
#endif
#ifdef B3000000
	{3000000, B3000000},
#endif
#ifdef B3500000
	{3500000, B3500000},
#endif
#ifdef B4000000
	{4000000, B4000000},
#endif
	{UINT32_MAX, B9600},
	};
	int i = 0;

	while (baudrate > rates[i++].baud)
		;

	return rates[--i].speed;
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
 * Write message to Linux CAN socket
 *
 *  If this fails with ENOBUFS, then increase the TX queue with:
 *
 *	ip link set can0 txqueuelen 1024
 *
 ******************************************************************************/
int
canWrite(session_t *c, uint8_t *inbuf, int buflen)
{
#ifdef __linux
	struct can_frame frame;
	int rc;

	if (buflen == 0)
		return 0;

	bzero(&frame, sizeof(frame));

	frame.can_id = c->cid;
	frame.can_dlc = buflen;
	memcpy(frame.data, inbuf, buflen);

	rc = write(c->csock, &frame, sizeof(frame));
	if (rc <= 0)
		return rc;
	if (rc != sizeof(frame))
		return -1;

	return buflen;
#else
	errno = EBADF;

	return -1;
#endif
}

/*******************************************************************************
 *
 * Read message from Linux CAN socket
 *
 ******************************************************************************/
int
canRead(session_t *c, uint8_t *inbuf, int buflen)
{
#ifdef __linux
	struct can_frame frame;
	int rc;

	if (buflen == 0)
		return 0;

	bzero(&frame, sizeof(frame));

	rc = read(c->csock, &frame, sizeof(frame));
	if (rc <= 0)
		return rc;
	if (rc != sizeof(frame))
		return -1;

	memcpy(inbuf, frame.data, frame.can_dlc);

	return frame.can_dlc;
#else
	errno = EBADF;

	return -1;
#endif
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
 * Count Strings
 *
 *  Display packets per second.
 *
 ******************************************************************************/
static inline void
count_str(void)
{
	static struct timeval tv1 = {0};
	static uint32_t count = 0;
	struct timeval tv2, tv3;
	double pps;

	if (count == 0) {
		gettimeofday(&tv1, NULL);
		count = 1;
	} else {
		gettimeofday(&tv2, NULL);
		timersub(&tv2, &tv1, &tv3);
		if (tv3.tv_sec >= 1) {
			pps = (double)count /
				((double)tv3.tv_sec + tv3.tv_usec / 1000000.);
			printf("%.2f pps\n", pps);
			count = 0;
		} else {
			count++;
		}
	}
}

/*******************************************************************************
 *
 * Process String t0008B905000000000000
 *
 *  FIXME Only works on Little-Endian
 *
 ******************************************************************************/
static inline void
process_str(char *s)
{
	static int64_t prev = -1;
	int64_t this = 0;

	int i = 5, j = 0;
	uint8_t *p = (uint8_t *)&this;

	while (j < 8) {
		p[j++] = hex2byt(&s[i]);
		i += 2;
	}

	if (this != (prev + 1))
		printf("[%s] %jd != %jd + 1\n", s, this, prev);

	prev = this;

	count_str();
}

/*******************************************************************************
 *
 * Detect String and Process
 *
 ******************************************************************************/
static inline char *
detect_str(char *inbuf, uint32_t *nb)
{
	char *cp;
	uint32_t i;

	if ((cp = strchr(inbuf, '\r')) != NULL) {
		i = cp - inbuf;
		assert(i < BUFLEN);

		inbuf[i++] = '\0';
		(*nb) -= i;
				
		if (inbuf[0] == 't' && i == 22)
			process_str(inbuf);

		assert(*nb >= 0);
		memmove(inbuf, &inbuf[i], *nb);

		assert(*nb < BUFLEN);
		inbuf[*nb] = '\0';
	}
	return cp;
}

/*******************************************************************************
 *
 * Detect Overrun and Remove
 *
 *  Linux will insert a null byte when an overrun is detected.
 *
 ******************************************************************************/
static inline char *
remove_null(char *inbuf, uint32_t *nb)
{
	char *cp;
	uint32_t i;

	if ((cp = memchr(inbuf, 0, *nb)) != NULL) {
		i = cp - inbuf;
		assert(i < BUFLEN);

		i++;
		(*nb) -= i;

		assert(*nb >= 0);
		memmove(inbuf, &inbuf[i], *nb);

		assert(*nb < BUFLEN);
		inbuf[*nb] = '\0';
	}
	return cp;
}

/*******************************************************************************
 *
 * CAN -> TTY
 *
 ******************************************************************************/
void
can2tty(session_t *c)
{
	int fd = (c->csock > c->fdtty) ? c->csock : c->fdtty;
	fd_set fdread, fdwrite;
	struct timeval tv;
	int rc;
	uint32_t nb = 0;
	uint64_t seq = 0;

	char inbuf[BUFLEN + 1];
	memset(inbuf, 0, BUFLEN);
	inbuf[BUFLEN] = -1;

	while (1) {
		tv.tv_sec = TIMEOUT;
		tv.tv_usec = 0;

		FD_ZERO(&fdread);
		FD_ZERO(&fdwrite);

		FD_SET(c->fdtty, &fdread);
		FD_SET(c->csock, &fdwrite);

		rc = select(fd + 1, &fdread, &fdwrite, NULL, &tv);
		if (rc < 0) {
			if (errno == EINTR)
				continue;
		}

		/* CAN Bus is down? */
		if (rc == 0) {
			fprintf(stderr, "select() TIMED-OUT\n");
			return;
		}

		/* Send on CAN Bus */
		if (FD_ISSET(c->csock, &fdwrite)) {
			rc = canWrite(c, (uint8_t *)&seq, 8);
			if (rc < 0) {
				if (errno != EINTR && errno != EAGAIN) {
					fprintf(stderr, "canWrite() FAILED [%s]\n",
						strerror(errno));
					return;
				}
			} else if (rc == 0) {
				fprintf(stderr, "EOF in canWrite()\n");
				return;
			} else {
				seq++;
			}
		}

		/* Receive on Serial UART */
		if (FD_ISSET(c->fdtty, &fdread)) {
			rc = read(c->fdtty, &inbuf[nb], BUFLEN - nb);
			if (rc < 0) {
				if (errno != EINTR && errno != EAGAIN) {
					fprintf(stderr, "read() FAILED [%s]\n",
						strerror(errno));
					return;
				}
			} else if (rc == 0) {
				fprintf(stderr, "EOF in read()\n");
				return;
			} else {
				nb += rc;
				while (detect_str(inbuf, &nb) || remove_null(inbuf, &nb))
					;
			}
		}

		/* Wait a while... */
		if (c->delay)
			usleep(c->delay);
	}
}

/*******************************************************************************
 *
 * HOWTO
 *
 ******************************************************************************/
void
usage(const char *msg, int err)
{
	fprintf(stderr, "USAGE: can-can can tty | tty can\n\n");

	if (msg)
		fprintf(stderr, "%s\n\n", msg);

	fprintf(stderr, "Options:\n"
		" -b N use TTY baud rate N\n"
		" -d N use microsecond rate delay N\n"
		" -i N use CAN bus message id N\n"

		"\n");

	exit(err);
}

/*******************************************************************************
 *
 * Can Everybody Can-Can?
 *
 ******************************************************************************/
int
main(int argc, char **argv)
{
	int opt;
	int nargs = 2;
	char *candev, *ttydev;
	uint32_t baudrate = 500000;

	session_t c;
	c.dir = 0;
	c.cid = 0;
	c.delay = 0;

	opterr = 0;
	while ((opt = getopt(argc, argv, "b:d:i:")) != -1) {
		switch (opt) {
		case 'b':
			baudrate = strtoul(optarg, NULL, 0);
			break;
		case 'd':
			c.delay = strtoul(optarg, NULL, 0);
			break;
		case 'i':
			c.cid = strtol(optarg, NULL, 0);
			break;
		}
	}
	argc -= optind;
	argv += optind;
	if (argc < nargs) {
		usage("Missing args", EX_USAGE);
	}

	if (argv[0][0] == '/') {
		ttydev = argv[0];
		candev = argv[1];
		c.dir = 1;
	} else {
		candev = argv[0];
		ttydev = argv[1];
		c.dir = 0;
	}

	c.csock = openCanSock(candev);
	if (c.csock < 0) {
		fprintf(stderr, "Failed to open can socket [%s].\n", candev);
		exit(EX_OSERR);
	}

	c.fdtty = openDevice(ttydev, serial_speed(baudrate));
	if (c.fdtty < 0) {
		fprintf(stderr, "Failed to open tty device [%s].\n", ttydev);
		exit(EX_OSERR);
	}

	setpriority(PRIO_PROCESS, 0, -20); /* Needs permission to succeed */

	sleep(1);
	if (c.dir == 0)
		can2tty(&c);
	else
		fprintf(stderr, "Unimplemented\n");

	close(c.fdtty);
	close(c.csock);

	exit(EX_OK);
}
