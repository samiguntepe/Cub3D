/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:52 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/10 17:27:28 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "cub3d.h"

int	main(void)
{
	// t_cub	cub3d;
	int		fd;
	char	*ptr;

	fd = open("mapfile.cub", O_RDONLY);
	ptr = read_type_of_element(fd);
	printf("%s", ptr);
	// inits(&cub3d, fd);
	// map_control(&cub3d);
}
