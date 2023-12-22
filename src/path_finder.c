#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../cub3d.h"

int floodFill(t_file *fl, int i, int j, int size) {

    if (i < 0 || i >= size || j < 0 || j >= size || fl->map[i][j] == '1' || fl->mapInt[i][j] == 1) {
        return 1;
    }
    if (g->map[i][j] == ' ') {
        printf("Harita bozuk\n");
        return 0;
    }

    g->mapInt[i][j] = 1; 

    
    if (!floodFill(g, i+1, j, size) || !floodFill(g, i-1, j, size) || !floodFill(g, i, j+1, size) || !floodFill(g, i, j-1, size)) {
        return 0;
    }

    return 1;
}



void testMap(t_file *fl, int )
{
    int i = 0;
    int size = 10;
    int result;

    while (i < fl->map_h) {
        int j = 0;
        while (j < ft_strlen(fl->map[i])) 
        {
            if (x->map[i][j] == ' ') {
                j++;
                continue;
            }
            else if (x->map[i][j] == '1')
            {
                x->mapInt[i][j] = 1;
            }
            if (x->map[i][j] == '0') 
            {
                result = floodFill(x, i, j, size);
                if (result == 0)
                    return ;
            }
            j++;
        }
        i++;
    }
}