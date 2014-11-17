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
#define BUFLEN (8192)

/*
 * I/O time out in seconds
 */
#define TIMEOUT (1)

/*
 * Can-can session
 */
typedef struct {
	int dir;	/* Direction 0=can->tty, 1=tty->can */
	int fdtty;	/* TTY descriptor                   */
	int csock;	/* CAN socket                       */
	int cid;        /* CAN bus id                       */ 
} session_t;

/*******************************************************************************
 *
 * Open serial device
 *
 ******************************************************************************/
int
openDevice(const char *dev, speed_t baudrate)
{
	int fd;
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
 * Write message to Linux CAN socket
 *
 *  If this fails with ENOBUFS, then increase the TX queue with:
 *
 *	ip link set can0 txqueuelen 1024
 *
 ******************************************************************************/
int
canWrite(session_t *c, uint8_t *buffer, int buflen)
{
#ifdef __linux
	struct can_frame frame;
	int rc;

	if (buflen == 0)
		return 0;

	bzero(&frame, sizeof(frame));

	frame.can_id = c->cid;
	frame.can_dlc = buflen;
	memcpy(frame.data, buffer, buflen);

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
canRead(session_t *c, uint8_t *buffer, int buflen)
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

	memcpy(buffer, frame.data, frame.can_dlc);

	return frame.can_dlc;
#else
	errno = EBADF;

	return -1;
#endif
}

/*******************************************************************************
 *
 * Detect string and output
 *
 ******************************************************************************/
static inline char *
print_str(char *buffer, int *nb)
{
	char *cp;
	int i;

	if ((cp = strchr(buffer, '\r')) != NULL) {
		i = cp - buffer;
		buffer[i++] = '\0';
				
		if (buffer[0] == 't')
			printf("%04X %s\n", *nb, buffer);
		// else missing header

		(*nb) -= i;
		memmove(buffer, &buffer[i], *nb);
		buffer[*nb] = '\0';
	}
	return cp;
}

/*******************************************************************************
 *
 * Detect overrun and remove
 *
 ******************************************************************************/
static inline char *
remove_null(char *buffer, int *nb)
{
	char *cp;
	int i;

	if ((cp = memchr(buffer, 0, *nb)) != NULL) {
		i = cp - buffer + 1;
		(*nb) -= i;
		memmove(buffer, &buffer[i], *nb);
		buffer[*nb] = '\0';
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
	int rc, nb = 0;
	char buffer[BUFLEN + 1];
	struct timeval tv;
	fd_set fdread, fdwrite;
	int fd = (c->csock > c->fdtty) ? c->csock : c->fdtty;
	uint64_t seq = 0;

	bzero(buffer, BUFLEN + 1);

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

		if (rc == 0) {
			fprintf(stderr, "select() TIMED-OUT\n");
			return;
		}

		if (FD_ISSET(c->fdtty, &fdread)) {
			rc = read(c->fdtty, &buffer[nb], BUFLEN - nb);
			if (rc < 0) {
				if (errno == EINTR || errno == EAGAIN)
                                	continue;
				fprintf(stderr, "read() FAILED\n");
				return;
			}
			if (rc == 0) {
				fprintf(stderr, "EOF\n");
				return;
			}
			nb += rc;
			while (1) {
				if ((print_str(buffer, &nb) == NULL) &&
					(remove_null(buffer, &nb) == NULL))
					break;
			}
		}

		if (FD_ISSET(c->csock, &fdwrite)) {
			rc = canWrite(c, (uint8_t *)&seq, 8);
			if (rc < 0) {
				if (errno == EINTR || errno == EAGAIN)
                                	continue;
				fprintf(stderr, "canWrite() FAILED\n");
				return;
			}
			seq++;
		}

		usleep(500);
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
	session_t c;

	c.dir = 0;
	c.cid = 0;

	c.csock = openCanSock("can0");
	if (c.csock < 0) {
		fprintf(stderr, "Failed to open can socket [%s].\n", "can0");
		exit(EX_OSERR);
	}

	c.fdtty = openDevice("/dev/ttyPL2303", B460800);
	if (c.fdtty < 0) {
		fprintf(stderr, "Failed to open tty device [%s].\n", "/dev/ttyPL2303");
		exit(EX_OSERR);
	}

	if (c.dir == 0)
		can2tty(&c);

	close(c.fdtty);
	close(c.csock);

	exit(EX_OK);
}
