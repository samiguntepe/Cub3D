/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:24 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/23 13:21:16 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int game_loop(t_game *g)
{
    movement(g, g->file);
    rotate(g);
    raycast(g, g->file);

    return (0);
}

void init(t_game *g, int x)
{
    g->rayc.cameraX = 2 * x / (double)SW - 1;
    g->rayc.rayDirX = g->rayc.dirX + g->rayc.planeX * g->rayc.cameraX;
    g->rayc.rayDirY = g->rayc.dirY + g->rayc.planeY * g->rayc.cameraX;
    g->rayc.mapX = (int)g->rayc.posX;
    g->rayc.mapY = (int)g->rayc.posY;
}

void init2(t_game *g)
{
    if (g->rayc.rayDirX == 0)
        g->rayc.deltaDistX = 1;
    else 
        g->rayc.deltaDistX = fabs(1 / g->rayc.rayDirX);
    if (g->rayc.rayDirY == 0)
        g->rayc.deltaDistY = 1;
    else 
        g->rayc.deltaDistY = fabs(1 / g->rayc.rayDirY);
}

void calculate(t_game *g)
{
    if (g->rayc.rayDirX < 0)
    {
        g->rayc.stepX = -1;
        g->rayc.sideDistX = (g->rayc.posX - g->rayc.mapX) * g->rayc.deltaDistX;
    }
    else 
    {
        g->rayc.stepX = 1;
        g->rayc.sideDistX = (g->rayc.mapX + 1.0 - g->rayc.posX) * g->rayc.deltaDistX;
    }
    if (g->rayc.rayDirY < 0)
    {
        g->rayc.stepY = -1;
        g->rayc.sideDistY = (g->rayc.posY - g->rayc.mapY) * g->rayc.deltaDistY;
    }
    else 
    {
        g->rayc.stepY = 1;
        g->rayc.sideDistY = (g->rayc.mapY + 1.0 - g->rayc.posY) * g->rayc.deltaDistY;
    }
}

void raycast(t_game *g, t_file *fl)
{
    int x = -1;
    while (++x < SW)
    {
        init(g, x);
        init2(g);
        calculate(g);
        dda(g, fl);
        dda2(g);
        draw(g);
        draw2(g);
        draw3(g, x);
    }
    mlx_put_image_to_window(g->mlx, g->mlxWin, g->img->img, 0, 0);
}
