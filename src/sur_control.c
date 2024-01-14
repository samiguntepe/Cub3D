/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sur_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:46 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/14 17:56:37 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../cub3d.h"

void	sur_control(t_file *fl)
{
	int		len;

	fl->max_len = find_max_len(fl);
	loc_around_space(fl, 0);
	around_space(fl);
	len = fl->map_h + 2;
	test(fl, len);
}

size_t	find_max_len(t_file *fl)
{
	size_t	current_length;
	size_t	max_length;
	int		i;

	max_length = 0;
	i = 0;
	while (fl->lines[i])
	{
		current_length = ft_strlen(fl->lines[i]);
		if (max_length < current_length)
			max_length = current_length;
		i++;
	}
	return (max_length);
}

void	init_row_spaces(char *row, size_t length)
{
	size_t	l;

	l = 0;
	while (l < length)
	{
		row[l] = ' ';
		l++;
	}
	row[length] = '\0';
}

int	is_map_valid(t_file *fl, int rows)
{
	int	isvalid;

	loc_row_len(fl, rows);
	fill_row_len(fl, rows);
	isvalid = check_map_char(fl, rows);
	if (fl != NULL && fl->rowlen != 0)
	{
		free(fl->rowlen);
		fl->rowlen = 0;
	}
	return (isvalid);
}

void	around_space(t_file *fl)
{
	int		i;
	int		k;

	init_row_spaces(fl->spc_map[0], fl->max_len + 2);
	i = 0;
	k = 1;
	while (i < fl->map_h)
	{
		fill_row_map_data(fl->spc_map[k], fl->map[i], fl->max_len);
		i++;
		k++;
	}
	init_row_spaces(fl->spc_map[fl->map_h + 1], fl->max_len + 2);
	fl->spc_map[fl->map_h + 2] = NULL;
}
