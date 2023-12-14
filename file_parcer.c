/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:03 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/14 13:58:39 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>

void	file_parcer(t_file *file)
{
	file->whole_lines = read_file(file);
	file->lines = split_lines(file->whole_lines);
	
	
	// file_parcer_textures(file->lines, file->textures);
	// count_wrgLine(file);
	// printf("%d", file->wrgLines_count);

}