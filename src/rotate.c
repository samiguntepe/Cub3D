#include "cub3d.h"

void rotate(g *g)
{
    double oldDirX;
    double oldPlaneX;


    if (g->left)
    {
        oldDirX = g->dirX;
        g->dirX = g->dirX * cos(g->rspeed) - g->dirY * sin(g->rspeed);
        g->dirY = oldDirX * sin(g->rspeed) + g->dirY * cos(g->rspeed);


        oldPlaneX = g->planeX;
        g->planeX = g->planeX * cos(g->rspeed) - g->planeY * sin(g->rspeed);
        g->planeY = oldPlaneX * sin(g->rspeed) + g->planeY * cos(g->rspeed);
    }   
    if (g->right)
    {
	    oldPlaneX = g->dirX;
	    g->dirX = g->dirX * cos(g->rspeed) + g->dirY * sin(g->rspeed);
	    g->dirY = -oldPlaneX * sin(g->rspeed) + g->dirY * cos(g->rspeed);
	
	    oldPlaneX = g->planeX;
	    g->planeX = g->planeX * cos(g->rspeed) + g->planeY * sin(g->rspeed);
	    g->planeY = -oldPlaneX * sin(g->rspeed) + g->planeY * cos(g->rspeed);
    }
}