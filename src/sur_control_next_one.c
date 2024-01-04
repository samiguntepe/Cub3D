/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sur_control_next_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:29:52 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/04 12:47:27 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**loc_around_space(t_file *fl, char **spc_map, int i)
{
	int	len;

	len = 0;
	spc_map = malloc((fl->map_h + 3) * sizeof(char *));
	len = fl->map_h + 3;
	while (i < len)
	{
		spc_map[i] = malloc((fl->max_len + 3) * sizeof(char));
		if (i == len - 1)
			spc_map[i] = NULL;
		i++;
	}
	return (spc_map);
}

void	test(t_file *fl, int map_h)
{
	if (is_map_valid(fl, map_h))
		printf("okey");
	else
		exit(printf("not okey"));
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
