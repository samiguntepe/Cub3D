/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sur_control_next_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:29:52 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 14:35:24 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**loc_around_space(t_file *fl, char **spc_map, int i, int j)
{
	int	len;

	len = 0;
	spc_map = malloc((fl->map_h + 3) * sizeof(char *));
	len = fl->map_h +1;
	len++;
	while (i < len)
	{
		spc_map[i] = malloc((ft_strlen(fl->map[j]) + 3) * sizeof(char));
		i++;
	}
	spc_map[i] = NULL;
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
