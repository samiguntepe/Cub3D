/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:27 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/22 15:55:26 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void rotate(t_game *g)
{
    double oldDirX;
    double oldPlaneX;

    if (g->left)
    {
        oldDirX = g->rayc.dirX;
        g->rayc.dirX = g->rayc.dirX * cos(g->rspeed) - g->rayc.dirY * sin(g->rspeed);
        g->rayc.dirY = oldDirX * sin(g->rspeed) + g->rayc.dirY * cos(g->rspeed);

        oldPlaneX = g->rayc.planeX;
        g->rayc.planeX = g->rayc.planeX * cos(g->rspeed) - g->rayc.planeY * sin(g->rspeed);
        g->rayc.planeY = oldPlaneX * sin(g->rspeed) + g->rayc.planeY * cos(g->rspeed);
    }
    if (g->right)
    {
        oldDirX = g->rayc.dirX;
        g->rayc.dirX = g->rayc.dirX * cos(g->rspeed) + g->rayc.dirY * sin(g->rspeed);
        g->rayc.dirY = -oldDirX * sin(g->rspeed) + g->rayc.dirY * cos(g->rspeed);

        oldPlaneX = g->rayc.planeX;
        g->rayc.planeX = g->rayc.planeX * cos(g->rspeed) + g->rayc.planeY * sin(g->rspeed);
        g->rayc.planeY = -oldPlaneX * sin(g->rspeed) + g->rayc.planeY * cos(g->rspeed);
    }
}

void movement(t_game *g, t_file *fl)
{
    if (g->w)
    {
        if (fl->map[(int)(g->rayc.posY)][(int)(g->rayc.posX + g->rayc.dirX * g->speed)] != 49)
            g->rayc.posX += g->rayc.dirX * g->speed;
        if (fl->map[(int)(g->rayc.posY + g->rayc.dirY * g->speed)][(int)(g->rayc.posX)] != 49)
            g->rayc.posY += g->rayc.dirY * g->speed;
    }
    if (g->d)
    {
        if (fl->map[(int)(g->rayc.posY)][(int)(g->rayc.posX + g->rayc.planeX * g->speed)] != 49)
            g->rayc.posX += g->rayc.planeX * g->speed;
        if (fl->map[(int)(g->rayc.posY + g->rayc.planeY * g->speed)][(int)(g->rayc.posX)] != 49)
            g->rayc.posY += g->rayc.planeY * g->speed;
    }
    if (g->s)
    {
        if (fl->map[(int)(g->rayc.posY)][(int)(g->rayc.posX - g->rayc.dirX * g->speed)] != 49)
            g->rayc.posX -= g->rayc.dirX * g->speed;
        if (fl->map[(int)(g->rayc.posY - g->rayc.dirY * g->speed)][(int)(g->rayc.posX)] != 49)
            g->rayc.posY -= g->rayc.dirY * g->speed;
    }
    if (g->a)
    {
        if (fl->map[(int)(g->rayc.posY - g->rayc.planeY * g->speed)][(int)(g->rayc.posX)] != 49)
            g->rayc.posY -= g->rayc.planeY * g->speed;
        if (fl->map[(int)(g->rayc.posY)][(int)(g->rayc.posX - g->rayc.planeX * g->speed)] != 49)
            g->rayc.posX -= g->rayc.planeX * g->speed;
    }

}