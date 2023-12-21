#include "../cub3D.h"

void rotate(t_game *g)
{
    double oldDirX;
    double oldPlaneX;

    if (g->left)
    {
        oldDirX = g->r.dirX;
        g->r.dirX = g->r.dirX * cos(g->rspeed) - g->r.dirY * sin(g->rspeed);
        g->r.dirY = oldDirX * sin(g->rspeed) + g->r.dirY * cos(g->rspeed);

        oldPlaneX = g->r.planeX;
        g->r.planeX = g->r.planeX * cos(g->rspeed) - g->r.planeY * sin(g->rspeed);
        g->r.planeY = oldPlaneX * sin(g->rspeed) + g->r.planeY * cos(g->rspeed);
    }
    if (g->right)
    {
        oldDirX = g->r.dirX;
        g->r.dirX = g->r.dirX * cos(g->rspeed) + g->r.dirY * sin(g->rspeed);
        g->r.dirY = -oldDirX * sin(g->rspeed) + g->r.dirY * cos(g->rspeed);

        oldPlaneX = g->r.planeX;
        g->r.planeX = g->r.planeX * cos(g->rspeed) + g->r.planeY * sin(g->rspeed);
        g->r.planeY = -oldPlaneX * sin(g->rspeed) + g->r.planeY * cos(g->rspeed);
    }
}

void movement(t_game *g)
{
    // kod gelicek 
}