/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sur_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:46 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/25 20:16:35 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../cub3d.h"

void	sur_control(t_file *fl)
{
	char **spc_map = NULL;
	spc_map = loc_around_space(fl, spc_map, 0, 1);
	spc_map = around_space(fl, spc_map, 0, 0);
	// int len = fl->map_h + 2;
	// test(spc_map, len);
	printf("%s\n",spc_map[0]);
	printf("%s\n",spc_map[1]);
	printf("%s\n",spc_map[2]);
	printf("%s\n",spc_map[3]);
	printf("%s\n",spc_map[4]);
	printf("%s\n",spc_map[5]);
	printf("%s\n",spc_map[6]);
	
}

char	**loc_around_space(t_file *fl,char	**spc_map, int i, int j)
{
	int len = 0;
	spc_map = malloc((fl->map_h + 3) * sizeof(char *));
	len = fl->map_h +1;
	len++;
	while (i < len)
	{
		spc_map[i] = malloc((ft_strlen(fl->map[j]) + 2) * sizeof(char));
		i++;
	}
	spc_map[i] = NULL;
	return (spc_map);
}

char	**around_space(t_file *fl,char **spc_map, int i, size_t j)
{
	int k;
	int l;

	k = 0;
	while (fl->map[i])
	{
		j = 0;
		l = 0;
		while (fl->map[i][j])
		{
			spc_map[k][l] = fl->map[i][j];

			if (l == 0 || k == 0)
			{
				spc_map[k][l] = 'B';
			}
				j++;
				l++;
		}
		spc_map[k][l] = '\0';
		i++;
		k++;
	}
	j = 0;
	l = 0;
	i--;
	while (j < ft_strlen(fl->map[i]))
	{
		spc_map[k][l] = 'B';
		j++;
		l++;
	}
	k++;
	spc_map[k] = NULL;
	return spc_map;
}

bool hasSpaceAround(char **map, int row, int col, int rows, int *rowLengths)
{
    // Üst kontrolü
    if (row > 0 && map[row - 1][col] == ' ') {
        return true;
    }
    // Alt kontrolü
    if (row < rows - 1 && map[row + 1][col] == ' ') {
        return true;
    }
    // Sol kontrolü
    if (col > 0 && map[row][col - 1] == ' ') {
        return true;
    }
    // Sağ kontrolü
    if (col < rowLengths[row] - 1 && map[row][col + 1] == ' ')
    {
        return true;
    }
    else if (col == rowLengths[row] - 1 && map[row][col + 1] == '\0')
    {
        return true;
    }
    return false;
}
bool hasSpaceDiagonally(char **map, int row, int col, int rows, int *rowLengths) {
    // Sol Üst kontrolü
    if (row > 0 && col > 0 && map[row - 1][col - 1] == ' ') {
        return true;
    }
    // Sağ Üst kontrolü
    if (row > 0 && col < rowLengths[row - 1] - 1 && map[row - 1][col + 1] == ' ') {
        return true;
    }
    // Sol Alt kontrolü
    if (row < rows - 1 && col > 0 && map[row + 1][col - 1] == ' ') {
        return true;
    }
    // Sağ Alt kontrolü
    if (row < rows - 1 && col < rowLengths[row + 1] - 1 && map[row + 1][col + 1] == ' ') {
        return true;
    }
    return false;
}
bool isMapValid(char **map, int rows) {
    int rowLengths[rows];
    for (int i = 0; i < rows; i++) {
        rowLengths[i] = ft_strlen(map[i]);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rowLengths[i]; j++) {
            if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'E' || map[i][j] == 'W')
            {
                if (hasSpaceAround(map, i, j, rows, rowLengths))
                {
                    return false;
                }
                if (hasSpaceDiagonally(map, i, j, rows, rowLengths))
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void test(char **spc_map, int map_h)
{
    if (isMapValid(spc_map, map_h))
        printf("okey");
    else
        exit(printf("not okey"));
}