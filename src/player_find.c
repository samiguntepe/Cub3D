#include "../cub3d.h"

void playerPosNS(t_game *game, int i, int j)
{
    if (map[i][j] == 'N')
    {
        posX = i + 0.5;
        posY = j + 0.5;
        dirX = 0;
        dirY = 1;
        planeX = 0.66;
        planeY = 0;
    }
    else if (map[i][j] == 'S')
    {
        posX = i + 0.5;
        posY = j + 0.5;
        dirX = 0
        dirY = -1
        planeX = -0.66
        planeY = 0
    }
}
void playerPosWE(t_game *game, int i, int j)
{
    if (map[i][j] == 'W')
    {
        posX = i + 0.5;
        posY = i + 0.5;
        dirX = -1;
        dirY = 0;
        planeX = 0;
        planeY = 0.66;
    }
    else if (map[i][j] == 'E')
    {
        posX = i + 0.5;
        posY = i + 0.5;
        dirX = 1;
        dirY = 0;
        planeX = 0;
        planeY = -0.66;
    }
}