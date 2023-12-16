/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:52 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/16 14:44:41 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "cub3d.h"

int	main(void)
{
	t_cub cub3d;

	cub3d.file.fd = open("mapfile.cub", O_RDONLY);
    if (cub3d.file.fd == -1) {
        perror("Dosya açılamadı");
        return 0;
    }
	inits(&cub3d);
	file_parcer(&cub3d.file);
	// inits(&cub3d, fd);
	// map_control(&cub3d);
}
