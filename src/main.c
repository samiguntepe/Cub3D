/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:52 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/22 09:18:38 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
    t_file file;

	inits(&file);
    if (argc != 2)
        exit(printf("Wrong, arguments count!"));
    
	file.fd = open(argv[1], O_RDONLY);
    if (file.fd == -1) {
        printf("File can't open!");
        return 0;
    }
    map_name_control(argv[1]);
    file_parcer(&file);
    
    // t_game g;

    // keyinit(&g);
    // g.mlx = mlx_init();
    // g.mlxWin = mlx_new_window(g.mlx, SW, SH, "cub3D");
    // g.img = malloc(sizeof(t_image)); 
    // g.img->i = mlx_new_image(g.mlx, SW, SH);
    // g.img->addr = (int *)mlx_get_data_addr(g.img->i, &g.img->nbr, &g.img->nbr, &g.img->nbr);
    
    // mlx_hook(g.mlxWin, 2, 1L<<0, movePress, &g);
    // mlx_hook(g.mlxWin, 3, 1L<<1, moveRelease, &g);
    // mlx_hook_loop(g.mlx, &game, &g);
    // mlx_loop(g.mlx);
    return (0);
}
