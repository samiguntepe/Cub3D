#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "cub3d.h"

int main() {
    int fd;
	
	fd = open("mapfile.cub", O_RDONLY);
	char *mapfile = read_mapfile(fd);
	printf("%s", mapfile);
}