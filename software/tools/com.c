/*
 * Building: cc -o com com.c
 * Usage   : ./com /dev/device [speed]
 * Example : ./com /dev/ttyS0 [115200]
 * Keys    : Ctrl-A - exit, Ctrl-X - display control lines status
 * Darcs   : darcs get http://tinyserial.sf.net/
 * Homepage: http://tinyserial.sourceforge.net
 * Version : 2009-03-05
 *
 * Ivan Tikhonov, http://www.brokestream.com, kefeer@brokestream.com
 * Patches by Jim Kou, Henry Nestler, Jon Miner, Alan Horstmann
 *
 */

/* Copyright (C) 2007 Ivan Tikhonov

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Ivan Tikhonov, kefeer@brokestream.com
*/

#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>

typedef struct {
	char *name;
	int flag;
} speed_spec;

speed_spec speeds[] = {
	{"1200", B1200},
	{"2400", B2400},
	{"4800", B4800},
	{"9600", B9600},
	{"19200", B19200},
	{"38400", B38400},
	{"57600", B57600},
	{"115200", B115200},
	{"460800", B460800},
	{"500000", B500000},
	{"576000", B576000},
	{"921600", B921600},
	{"2000000", B2000000},
	{NULL, 0}
};

void
print_status(int fd)
{
	int status;
	unsigned int arg;

	status = ioctl(fd, TIOCMGET, &arg);

        /* modify RTS for EasyCAN */
	arg &= ~TIOCM_RTS;
	ioctl(fd, TIOCMSET, &arg);

	fprintf(stderr, "[STATUS]: ");
	if (arg & TIOCM_RTS) fprintf(stderr, "RTS ");
	if (arg & TIOCM_CTS) fprintf(stderr, "CTS ");
	if (arg & TIOCM_DSR) fprintf(stderr, "DSR ");
	if (arg & TIOCM_CAR) fprintf(stderr, "DCD ");
	if (arg & TIOCM_DTR) fprintf(stderr, "DTR ");
	if (arg & TIOCM_RNG) fprintf(stderr, "RI ");
	fprintf(stderr, "\r\n");
}

void
options(int fd, struct termios *old, struct termios *new, speed_t speed)
{
	fcntl(fd, F_SETFL, O_NONBLOCK | fcntl(fd, F_GETFL));

	tcgetattr(fd, old);
	tcgetattr(fd, new);

        new->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
        new->c_oflag &= ~(OPOST);
        new->c_cflag &= ~(CSIZE | PARENB);
        new->c_cflag |= (CS8);
        new->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
        new->c_cc[VMIN] = 1;
        new->c_cc[VTIME] = 0;

        cfsetispeed(new, speed);
        cfsetospeed(new, speed);

        tcflush(fd, TCIOFLUSH);
        tcsetattr(fd, TCSANOW, new);
}

int
fdread(int fd, char *buf, int buflen)
{
	int rc;

	while (1) {
		rc = read(fd, buf, buflen - 1);
		if (rc < 0) {
			if (errno == EINTR || errno == EAGAIN)
				continue;
			perror("read()");
			exit(1);
		}
		buf[rc] = '\0';
		return rc;
	}
}

int
fdwrite(int fd, char *buf, int buflen)
{
	int rc, nb = 0;

	while (nb < buflen) {
		rc = write(fd, buf, buflen);
		if (rc < 0) {
			if (errno == EINTR || errno == EAGAIN)
				continue;
			perror("write()");
			exit(1);
		}
		if (rc == 0)
			return nb;
		nb += rc;
	}
	return nb;
}

int
main(int argc, char *argv[])
{
	int fdcons = STDIN_FILENO, fduart;
	speed_spec *s;
	int speed = B460800;
	struct termios oldfdcons, newfdcons, oldfduart, newfduart;
	fd_set fds;
	int rc;
	char buf[1024];

	if (argc < 2) {
		fprintf(stderr, "Try: %s /dev/ttyS0 [460800]\n", argv[0]);
		exit(1);
	}

	fduart = open(argv[1], O_RDWR | O_NOCTTY | O_NONBLOCK);
	if (fduart < 0) {
		perror("open()");
		exit(1);
	}

	if (argc > 2) {	
		for (s = speeds; s->name; s++) {
			if (strcmp(s->name, argv[2]) == 0) {
				speed = s->flag;
				fprintf(stderr, "Setting speed %s\n", s->name);
				break;
			}
		}
	}

	fprintf(stderr, "CTRL-A exit, CTRL-X modem status\n");

	options(fdcons, &oldfdcons, &newfdcons, speed);
	options(fduart, &oldfduart, &newfduart, speed);

	print_status(fduart);

	while (1) {
		FD_ZERO(&fds);
		FD_SET(fdcons, &fds);
		FD_SET(fduart, &fds);
		rc = select(fduart + 1, &fds, NULL, NULL, NULL);
		if (rc < 0) {
			if (errno == EINTR)
				continue;
			perror("select()");
			exit(1);
		}
		if (FD_ISSET(fdcons, &fds)) {
			rc = fdread(fdcons, buf, 1024);
			if (rc == 0)
				break;
			if (buf[0] == '\x01')	/* CTRL-A */
				break;
			if (buf[0] == '\x18')	/* CTRL-X */
				print_status(fduart);
			else
				fdwrite(fduart, buf, rc);
		}
		if (FD_ISSET(fduart, &fds)) {
			rc = fdread(fduart, buf, 1024);
			if (rc == 0)
				break;
			fdwrite(fdcons, buf, rc);
		}
	}

	tcflush(fduart, TCIFLUSH);
	tcsetattr(fduart, TCSANOW, &oldfduart);
	close(fduart);

	tcflush(fdcons, TCIFLUSH);
	tcsetattr(fdcons, TCSANOW, &oldfdcons);
	close(fdcons);

	return 0;
}
