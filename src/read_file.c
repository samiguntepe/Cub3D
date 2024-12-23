/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:12 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/15 11:55:35 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>
#include <unistd.h>

char	*read_file(t_file *fl)
{
	int		bytes;
	char	buffer[BUFFER_SIZE + 1];
	char	*file;
	char	*temp_str;

	file = NULL;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fl->fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		temp_str = ft_strjoin(file, buffer, 0, 0);
		free(file);
		file = temp_str;
	}
	if (bytes < 0)
		exit_game(fl->game, "Read is failed.");
	return (file);
}
