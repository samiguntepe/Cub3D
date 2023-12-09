#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
	int j;
	int i;
	int ncount = 0;
    ssize_t bytes_read;
    char buffer;

    fd = open("map.cub", O_RDONLY);
    while ((bytes_read = read(fd, &buffer, 1)) > 0) {
		
	}
}