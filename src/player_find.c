/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:51 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/25 09:26:30 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_player(t_file *fl, t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (fl->map[i])
	{
		j = 0;
		while (fl->map[i][j])
		{
			playerpos_ns(fl, g, i, j);
			playerpos_we(fl, g, i, j);
			j++;
		}
		i++;
	}
}

void	playerpos_ns(t_file *fl, t_game *g, int i, int j)
{
	if (fl->map[i][j] == 'N')
	{
		g->rayc.posX = j + 0.5;
		g->rayc.posY = i + 0.5;
		g->rayc.dirX = 0;
		g->rayc.dirY = -1;
		g->rayc.planeX = 0.66;
		g->rayc.planeY = 0;
	}
	else if (fl->map[i][j] == 'S')
	{
		g->rayc.posX = j + 0.5;
		g->rayc.posY = i + 0.5;
		g->rayc.dirX = 0;
		g->rayc.dirY = 1;
		g->rayc.planeX = -0.66;
		g->rayc.planeY = 0;
	}
}

void	playerpos_we(t_file *fl, t_game *g, int i, int j)
{
	if (fl->map[i][j] == 'W')
	{
		g->rayc.posX = j + 0.5;
		g->rayc.posY = i + 0.5;
		g->rayc.dirX = -1;
		g->rayc.dirY = 0;
		g->rayc.planeX = 0;
		g->rayc.planeY = -0.66;
	}
	else if (fl->map[i][j] == 'E')
	{
		g->rayc.posX = j + 0.5;
		g->rayc.posY = i + 0.5;
		g->rayc.dirX = 1;
		g->rayc.dirY = 0;
		g->rayc.planeX = 0;
		g->rayc.planeY = +0.66;
	}
}
