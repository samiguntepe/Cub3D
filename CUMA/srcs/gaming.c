#include "../cub3D.h"

void init(t_game *g, int x)
{
    g->r.cameraX = 2 * x / (double)SW - 1;
    g->r.rayDirX = g->r.dirX + g->r.planeX * g->r.cameraX;
    g->r.rayDirY = g->r.dirY + g->r.planeY * g->r.cameraX;
    g->r.mapX = (int)g->r.posX;
    g->r.mapY = (int)g->r.posY;
}

void init2(t_game *g)
{
    if (g->r.rayDirX == 0)
        g->r.deltaDistX = 1;
    else 
        g->r.deltaDistX = fabs(1 / g->r.rayDirX);
    if (g->r.rayDirY == 0)
        g->r.deltaDistY = 1;
    else 
        g->r.deltaDistY = fabs(1 / g->r.rayDirY);
}

void calculate(t_game *g)
{
    if (g->r.rayDirX < 0)
    {
        g->r.stepX = -1;
        g->r.sideDistX = (g->r.posX - g->r.mapX) * g->r.deltaDistX;
    }
    else 
    {
        g->r.stepX = 1;
        g->r.sideDistX = (g->r.mapX + 1.0 - g->r.posX) * g->r.deltaDistX;
    }
    if (g->r.rayDirY < 0)
    {
        g->r.stepX = -1;
        g->r.sideDistY = (g->r.posY - g->r.mapY) * g->r.deltaDistY;
    }
    else 
    {
        g->r.stepY = 1;
        g->r.sideDistY = (g->r.mapY + 1.0 - g->r.posY) * g->r.deltaDistY;
    }
}

void raycast(t_game *g)
{
    int x = 0;
    while (x++ < SW)
    {
        init(g, x);
        init2(g);
        calculate(g);
        dda(g);
        dda2(g);
        draw(g);
        draw2(g);
        draw3(g, x);
    }
    mlx_put_image_to_window(g->mlx, g->mlxWin, g->img->i, 0, 0);
}

int game(t_game *g)
{
    movement(g);
    rotate(g);
    raycast(g);

    return (0);
}