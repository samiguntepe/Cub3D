#include "../cub3D.h"

void dda(t_game *g)
{
    g->r.hit = 0;
    while (g->r.hit == 0)
    {
        if (g->r.sideDistX < g->r.sideDistY)
        {
            g->r.sideDistX += g->r.deltaDistX;
            g->r.mapX += g->r.stepX;
            g->r.side = 0;
        }
        else 
        {
            g->r.sideDistY += g->r.deltaDistY;
            g->r.mapY += g->r.stepY;
            g->r.side = 1;
        }
        if (g->map[g->r.mapY][g->r.mapX] == '1')
            g->r.hit = 1;
    }
}

void dda2(t_game *g)
{
    if (g->r.side == 0)
        g->r.perpwalldist = g->r.sideDistX - g->r.deltaDistX;
    else 
        g->r.perpwalldist = g->r.sideDistY - g->r.deltaDistY;
    g->t.lineH = (int)(SH / g->r.perpwalldist);
}

void draw(t_game *g)
{
    g->t.drawStart = -g->t.lineH / 2 + SH / 2;
    if (g->t.drawStart < 0)
        g->t.drawStart = 0;
    g->t.drawEnd = g->t.lineH / 2 + SH / 2;
    if (g->t.drawEnd >= SH)
        g->t.drawEnd = SH - 1;
    
    if (g->r.side == 0)
        g->r.wallX = g->r.posY + g->r.perpwalldist * g->r.rayDirY;
    else 
        g->r.wallX = g->r.posX + g->r.perpwalldist * g->r.rayDirX;
    g->r.wallX = g->r.wallX - (int)g->r.wallX;
}

void draw2(t_game *g)
{
    g->t.texX = (int)(g->r.wallX * (double)g->t.texWidth);
    if (g->r.side == 0 && g->r.rayDirX > 0)
        g->t.texX = g->t.texWidth - g->t.texX - 1;
    if (g->r.side == 1 && g->r.rayDirY < 0)
        g->t.texX = g->t.texWidth - g->t.texX - 1;

    g->t.step = 1.0 * g->t.texHeight / g->t.lineH;
    g->t.texPos = (g->t.drawStart - SH / 2 + g->t.lineH / 2) * g->t.step;
}

void draw3(t_game *g, int x)
{
    int y = 0;
    while (y++ < SH)
    {
        g->t.texY = (int)g->t.texPos;
        if (y < g->t.drawStart)
            g->img->addr[y * SW + x] = g->t.floor;
        else if (y > g->t.drawEnd)
            g->img->addr[y * SW + x] = g->t.ceiling; 
        else 
        {
            if (g->r.side == 1 && g->r.rayDirY < 0)
                g->img->addr[y * SW + x] = g->t.NO->addr[g->t.texHeight * g->t.texY + g->t.texX];
            else if (g->r.side == 1 && g->r.rayDirY > 0)
                g->img->addr[y * SW + x] = g->t.NO->addr[g->t.texHeight * g->t.texY + g->t.texX];
            if (g->r.side == 0 && g->r.rayDirX < 0)
                g->img->addr[y * SW + x] = g->t.NO->addr[g->t.texHeight * g->t.texY + g->t.texX];
            else if (g->r.side == 0 && g->r.rayDirX > 0)
                g->img->addr[y * SW + x] = g->t.NO->addr[g->t.texHeight * g->t.texY + g->t.texX];   
            g->t.texPos += g->t.step;
        }
    }
}