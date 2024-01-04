/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:51 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/04 16:43:39 by sguntepe         ###   ########.fr       */
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
		g->ray.pos_x = j + 0.5;
		g->ray.pos_y = i + 0.5;
		g->ray.dir_x = 0;
		g->ray.dir_y = -1;
		g->ray.plane_x = 0.66;
		g->ray.plane_y = 0;
	}
	else if (fl->map[i][j] == 'S')
	{
		g->ray.pos_x = j + 0.5;
		g->ray.pos_y = i + 0.5;
		g->ray.dir_x = 0;
		g->ray.dir_y = 1;
		g->ray.plane_x = -0.66;
		g->ray.plane_y = 0;
	}
}

void	playerpos_we(t_file *fl, t_game *g, int i, int j)
{
	if (fl->map[i][j] == 'W')
	{
		g->ray.pos_x = j + 0.5;
		g->ray.pos_y = i + 0.5;
		g->ray.dir_x = -1;
		g->ray.dir_y = 0;
		g->ray.plane_x = 0;
		g->ray.plane_y = -0.66;
	}
	else if (fl->map[i][j] == 'E')
	{
		g->ray.pos_x = j + 0.5;
		g->ray.pos_y = i + 0.5;
		g->ray.dir_x = 1;
		g->ray.dir_y = 0;
		g->ray.plane_x = 0;
		g->ray.plane_y = +0.66;
	}
}
