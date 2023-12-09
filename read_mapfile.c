#include "./include/libft/libft.h"
#include <stdlib.h>
#include "cub3d.h"
#include <stdio.h>

char *read_mapfile(int fd, int file_size)
{
    char *map_file = malloc(sizeof(char) * file_size + 1);
    char c;
    int read_bytes = 0;
    int index = 0;

    while ((read_bytes = read(fd, &c, 1)) > 0 && index < file_size)
    {
        map_file[index++] = c;
    }

    map_file[index] = '\0'; // Null-terminate the string

    return map_file;
}