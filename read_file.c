/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:12 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/14 13:58:43 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <unistd.h>

char 	*read_file(t_file *file)
{
	char	**leak;
	char	*types;
	int		read_bytes;
	char	c;

	leak = NULL;
	read_bytes = 1;
	types = malloc(sizeof(char) * 2);
	types[1] = '\0';
	while (read_bytes > 0)
	{
		read_bytes = read(file->fd, &c, 1);
		leak = &types;	
		types = ft_strjoin_(types, &c, leak);
	}
	return (types);
}