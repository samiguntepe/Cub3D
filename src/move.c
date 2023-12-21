#include "cub3d.h"


int movePress(int keyCode, g *g)
{
	if (keyCode == 53)
	{
		// all free
		exit(0);
	}
    if (keyCode == 13)
        g->w = true;
    if (keyCode == 1)
        g->s = true;
    if (keyCode == 0)
        g->a = true;
    if (keyCode == 2)
        g->d = true;
    if (keyCode == 124)
        g->right = true;
    if (keyCode == 123)
        g->left = true;
    return (0);
}
int moveRelease(int keyCode, g *g)
{
    if (keyCode == 13)
        g->w = false;
    if (keyCode == 1)
        g->s = false;
    if (keyCode == 0)
        g->a = false;
    if (keyCode == 2)
        g->d = false;
    if (keyCode == 124)
        g->right = false;
    if (keyCode == 123)
        g->left = false;
    return (0);
}

void movement(g *g)
{
    if (g->w)
    {
        if (g->map[(int)(g->posY)][(int)(g->posX + g->dirX * g->speed)] != '1')
            g->posX += g->dirX * g->speed;
        if (g->map[(int)(g->posY + g->dirY * g->speed)][(int)(g->posX)] != '1')
            g->posY += g->dirY * g->speed;
    }
    if (g->d)
    {
        if (g->map[(int)(g->posY)][(int)(g->posX + g->planeX * g->speed)] != '1')
            g->posX += g->planeX * g->speed;
        if (g->map[(int)(g->posY + g->planeY * g->speed)][(int)(g->posX)] != '1')
            g->posY += g->planeY * g->speed;
    }
    if (g->s)
    {
        if (g->map[(int)(g->posY)][(int)(g->posX - g->dirX * g->speed)] != '1')
            g->posX -= g->dirX * g->speed;
        if (g->map[(int)(g->posY - g->dirY * g->speed)][(int)(g->posX)] != '1')
            g->posY -= g->dirY * g->speed;
    }
    if (g->a)
    {
        if (g->map[(int)(g->posY)][(int)(g->posX - g->planeX * g->speed)] != '1')
            g->posX -= g->planeX * g->speed;
        if (g->map[(int)(g->posY - g->planeY * g->speed)][(int)(g->posX)] != '1')
            g->posY -= g->planeY * g->speed;
    }
}