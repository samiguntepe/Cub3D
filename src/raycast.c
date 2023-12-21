#include "../cub3d.h"

void raycast(g *g)
{
    int x = 0;
    while (x < SW)
    {
        g->cameraX = 2 * x / (double)SW - 1;
        g->rayDirX = g->dirX + g->planeX * g->cameraX;
        g->rayDirY = g->dirY + g->planeY * g->cameraX;
        g->mapX = (int)g->posX;
        g->mapY = (int)g->posY;

	    if (g->rayDirX == 0)
		    g->deltaDistX = 1;
	    else
		    g->deltaDistX = fabs(1 / g->rayDirX);
	    if (g->rayDirY == 0)
		    g->deltaDistY = 1;
	    else
		    g->deltaDistY = fabs(1 / g->rayDirY);
        

        if (g->rayDirX < 0)
        {
            g->stepX = -1;
            g->sideDistX = (g->posX - g->mapX) * g->deltaDistX;
        }
        else 
        {
            g->stepX = 1;
            g->sideDistX = (g->mapX + 1.0 - g->posX) * g->deltaDistX;
        }
        if (g->rayDirY < 0)
        {
            g->stepY = -1;
            g->sideDistY = (g->posY - g->mapY) * g->deltaDistY;
        }
        else 
        {
            g->stepY = 1;
            g->sideDistY = (g->mapY + 1.0 - g->posY) * g->deltaDistY;
        }

        g->hit = 0;
        while (g->hit == 0)
        {
            if (g->sideDistX < g->sideDistY)
            {
                g->sideDistX += g->deltaDistX;
                g->mapX += g->stepX;
                g->side = 0;
            }
            else 
            {
                g->sideDistY += g->deltaDistY;
                g->mapY += g->stepY;
                g->side = 1;
            }
            if (g->map[g->mapY][g->mapX] == '1')
                g->hit = 1;
        }
        
        if (g->side == 0)
            g->perpWallDist = g->sideDistX - g->deltaDistX;
        else 
            g->perpWallDist = g->sideDistY - g->deltaDistY;
        g->lineH = (int)(SH / g->perpWallDist);

        g->drawStart = -g->lineH / 2 + SH / 2;
        if (g->drawStart < 0)
            g->drawStart = 0;
        g->drawEnd = g->lineH / 2 + SH / 2;
        if (g->drawEnd >= SH)
            g->drawEnd = SH - 1;
        
        if (g->side == 0)
            g->wallX = g->posY + g->perpWallDist * g->rayDirY;
        else 
            g->wallX = g->posX + g->perpWallDist * g->rayDirX;
        g->wallX = g->wallX - (int)g->wallX;

        
        g->texX = (int)(g->wallX * (double)texWidth);
        if (g->side == 0 && g->rayDirX > 0)
            g->texX = texWidth - g->texX - 1;
        if (g->side == 1 && g->rayDirY < 0)
            g->texX = texWidth - g->texX - 1;
 

        g->step = 1.0 * texHeight / g->lineH;
        g->texPos = (g->drawStart - SH / 2 + g->lineH / 2) * g->step;

        
        int y = 0;
        while (y < SH)
        {
            g->texY = (int)g->texPos;
            if (y < g->drawStart)
                g->image->addr[y * SW + x] = g->floor;
            else if (y > g->drawEnd)
                g->image->addr[y * SW + x] = g->ceiling;
            else 
            {
                if (g->side == 1 && g->rayDirY < 0)
                    g->image->addr[y * SW + x] = g->NO->addr[texHeight * g->texY + g->texX];
                else if (g->side == 1 && g->rayDirY > 0)
                    g->image->addr[y * SW + x] = g->NO->addr[texHeight * g->texY + g->texX];
                if (g->side == 0 && g->rayDirX < 0)
                    g->image->addr[y * SW + x] = g->NO->addr[texHeight * g->texY + g->texX];
                else if (g->side == 0 && g->rayDirX > 0)
                    g->image->addr[y * SW + x] = g->NO->addr[texHeight * g->texY + g->texX];
                g->texPos += g->step;
            }
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(g->mlx, g->mlxWin, g->image->image, 0, 0);
}