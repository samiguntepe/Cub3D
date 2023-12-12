/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:03 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/12 20:29:38 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	file_parcer(t_file *file)
{
	char	*all_lines;

	all_lines = read_file(file->fd);

	file->lines = ft_split(all_lines, '\n');
	// file_parcer_textures(file->lines, file->textures);

	file->wrgLines = point_ignore_line(file);
	printf("%d\n",file->wrgLines[0]);
	printf("%d\n",file->wrgLines[1]);
	printf("%d\n",file->wrgLines[2]);
	
	
	
	// printf("%s\n", file->lines[0]);
	// printf("%s\n", file->lines[1]);
	// printf("%s\n", file->lines[2]);
	// printf("%s\n", file->lines[3]);
	// printf("%s\n", file->lines[4]);
}

char	**file_parcer_textures(char **lines, char **textures)
{
	(void)textures;
	(void)lines;
	// int	i;
	// int	j;
	// int boolen;
	// boolen = 1;
	// i = 0;
					// printf("2/%s\n", *lines[3]);
	// while (lines[i] != NULL)
	// {
	// 	j = 0;
	// 	while (lines[i][j] > 32)
	// 	{
			
	// 		if (lines[i][0] == 'N' && lines[i][1] == 'O')
	// 		{
	// 			if (boolen)
	// 			{
	// 				// textures[0] = malloc(ft_strlen(lines[i]) + 1);
	// 				// textures[1] = NULL;
	// 				boolen = 0;
	// 			}
	// 			// textures[0][j] = lines[i][j];
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	return (NULL);
}