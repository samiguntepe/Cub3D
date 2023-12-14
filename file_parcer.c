/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:03 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/14 17:31:17 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>

void	file_parcer(t_file *file)
{
	file->whole_lines = read_file(file);
	file->lines = split_lines(file->whole_lines);
	ft_strcpy(file->verify, "NO SO WE EA ");
	find_textures(file, 0);
	// find_textures(file, 1);
	// find_textures(file, 2);
	// find_textures(file, 3);
	
	printf("%s\n", file->NO);
	// printf("%s\n", file->SO);
	// printf("%s\n", file->WE);
	// printf("%s\n", file->EA);

}