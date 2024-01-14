/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sur_control_next_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:29:52 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/14 23:38:21 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	loc_around_space(t_file *fl, int i)
{
	int	len;

	len = 0;
	fl->spc_map = malloc((fl->map_h + 3) * sizeof(char *));
	len = fl->map_h + 2;
	while (i < len)
	{
		fl->spc_map[i] = malloc((fl->max_len + 3) * sizeof(char));
		i++;
	}
	fl->spc_map[i] = NULL;
}

void	test(t_file *fl, int map_h)
{
	if (is_map_valid(fl, map_h))
	{
		free_space_map(fl->spc_map);
	}
	else
	{
		free_space_map(fl->spc_map);
		exit_game(fl->game, "Map is not closed!");
	}
}

int	space_diagon(t_file *fl, int row, int col, int rows)
{
	if (row > 0 && col > 0 && fl->spc_map[row - 1][col - 1] == ' ')
		return (1);
	if (row > 0 && col < fl->rowlen[row - 1] - 1
		&& fl->spc_map[row - 1][col + 1] == ' ')
		return (1);
	if (row < rows - 1 && col > 0 && fl->spc_map[row + 1][col - 1] == ' ')
		return (1);
	if (row < rows - 1 && col < fl->rowlen[row + 1] - 1
		&& fl->spc_map[row + 1][col + 1] == ' ')
		return (1);
	return (0);
}

void	free_space_map(char **spc_map)
{
	int	i;

	i = 0;
	if (spc_map == NULL)
		return ;
	while (spc_map[i])
	{
		free(spc_map[i]);
		spc_map[i] = NULL;
		i++;
	}
	free(spc_map);
	spc_map = NULL;
}
