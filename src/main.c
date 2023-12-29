/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:52 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/29 15:09:05 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_game	game;
	int		n;

	if (argc != 2)
		exit(printf("Wrong, arguments count!"));
	inits(&game);
	map_name_control(argv[1]);
	game.file->fd = open(argv[1], O_RDONLY);
	if (game.file->fd == -1)
	{
		printf("File can't open!");
		return (0);
	}
	file_parcer(game.file);
	control_companent(game.file, 0, 0);
	upload_image(&game);
	find_player(game.file, &game);
	inits_rgb(&game);
	game.mlx = mlx_init();
	game.mlxWin = mlx_new_window(game.mlx, SW, SH, "cub3D");
	game.img = malloc(sizeof(t_image));
	game.img->img = mlx_new_image(game.mlx, SW, SH);
	game.img->addr = (int *)mlx_get_data_addr(game.img->img, &n, &n, &n);
	mlx_hook(game.mlxWin, 2, 1L << 0, move_press, &game);
	mlx_hook(game.mlxWin, 3, 1L << 1, move_release, &game);
	mlx_hook(game.mlxWin, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
