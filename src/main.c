/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:52 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 21:00:15 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit(printf("Wrong, arguments count!"));
	map_name_control(argv[1]);
	game.file = NULL;
	game.file = (t_file *)malloc(sizeof(t_file)); //*game
	game.file->fd = open(argv[1], O_RDONLY);
	if (game.file->fd == -1)
	{
		game_exit(&game, argv[1]);
		return (0);
	}
	next(&game);
	return (0);
}
