/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:51 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 15:20:41 by sguntepe         ###   ########.fr       */
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
		g->rayc.posx = j + 0.5;
		g->rayc.posy = i + 0.5;
		g->rayc.dirx = 0;
		g->rayc.diry = -1;
		g->rayc.planex = 0.66;
		g->rayc.planey = 0;
	}
	else if (fl->map[i][j] == 'S')
	{
		g->rayc.posx = j + 0.5;
		g->rayc.posy = i + 0.5;
		g->rayc.dirx = 0;
		g->rayc.diry = 1;
		g->rayc.planex = -0.66;
		g->rayc.planey = 0;
	}
}

void	playerpos_we(t_file *fl, t_game *g, int i, int j)
{
	if (fl->map[i][j] == 'W')
	{
		g->rayc.posx = j + 0.5;
		g->rayc.posy = i + 0.5;
		g->rayc.dirx = -1;
		g->rayc.diry = 0;
		g->rayc.planex = 0;
		g->rayc.planey = -0.66;
	}
	else if (fl->map[i][j] == 'E')
	{
		g->rayc.posx = j + 0.5;
		g->rayc.posy = i + 0.5;
		g->rayc.dirx = 1;
		g->rayc.diry = 0;
		g->rayc.planex = 0;
		g->rayc.planey = +0.66;
	}
}
