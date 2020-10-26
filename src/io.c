#include <unistd.h>
#include <stdlib.h>
#include <io.h>
#include <stdio.h>

int read_word(int fd) {
	
	char buf[32];

	read(fd, buf, 4);
	
	return atoi(buf);	
}

short read_half(int fd) {
	char buf[16];

	read(fd, buf, 2);

	return (short) atoi(buf);
}

void write_word(int fd, int word) {
	char buf[32];
	sprintf(buf, "%d", word);
	
	write(fd, buf, 4);
}

void write_half(int fd, short word) {

	char buf[16];
	sprintf(buf, "%d", (int) word);

	write(fd, buf, 2);
}
