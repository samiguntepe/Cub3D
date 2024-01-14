/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sur_control_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:30:33 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/14 23:39:43 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	space_around(t_file *fl, int row, int col, int rows)
{
	if (row > 0 && fl->spc_map[row - 1][col] == ' ')
		return (1);
	if (row < rows - 1 && fl->spc_map[row + 1][col] == ' ')
		return (1);
	if (col > 0 && fl->spc_map[row][col - 1] == ' ')
		return (1);
	if (col < fl->rowlen[row] - 1 && fl->spc_map[row][col + 1] == ' ')
		return (1);
	else if (col == fl->rowlen[row] - 1 && fl->spc_map[row][col + 1] == '\0')
		return (1);
	return (0);
}

void	loc_row_len(t_file *fl, int rows)
{
	fl->rowlen = malloc((rows + 1) * sizeof(int));
	if (fl->rowlen == NULL)
		exit_game(fl->game, "Allocation is failed!");
}

void	fill_row_len(t_file *fl, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		fl->rowlen[i] = ft_strlen(fl->spc_map[i]);
		i++;
	}
	fl->rowlen[i] = 0;
}

int	check_map_char(t_file *fl, int rows)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < fl->rowlen[i])
		{
			c = fl->spc_map[i][j];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (space_around(fl, i, j, rows)
					|| space_diagon(fl, i, j, rows))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	fill_row_map_data(char *row, const char *map_row, size_t max_length)
{
	size_t	l;

	l = 1;
	row[0] = ' ';
	while (l <= max_length)
	{
		if (l <= ft_strlen(map_row))
			row[l] = map_row[l - 1];
		else
			row[l] = ' ';
		l++;
	}
	row[l] = ' ';
	row[l + 1] = '\0';
}
