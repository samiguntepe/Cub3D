/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:03 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/14 09:26:08 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	file_parcer(t_file *file)
{
	file->whole_lines = read_file(file);


	int a = line_counter(file->whole_lines);
	// file->lines = split_lines(file->whole_lines);
	printf("%d", a);

	// printf("%s", file->lines[0]);
	// printf("%s", file->lines[1]);
	// printf("%s", file->lines[2]);
	
	
	// file_parcer_textures(file->lines, file->textures);
	// count_wrgLine(file);
	// printf("%d", file->wrgLines_count);

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