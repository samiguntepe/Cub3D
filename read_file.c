/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:12 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/16 15:55:27 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <unistd.h>

char	*read_file(t_file *fl)
{
	int		bytes;
	char	map[2];
	char	*file;

	file = NULL;
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fl->fd, map, 1);
		map[bytes] = '\0';
		file = ft_strjoin(file, map);
	}
	return (file);
}