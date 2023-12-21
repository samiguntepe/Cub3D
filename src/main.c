/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:52 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/21 17:48:40 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	t_cub cub3d;

	inits(&cub3d);
	cub3d.file.fd = open("mapfile.cub", O_RDONLY);
    if (cub3d.file.fd == -1) {
        perror("Dosya açılamadı");
        return 0;
    }
    t_game g;

    keyinit(&g);
    g.mlx = mlx_init();
    g.mlxWin = mlx_new_window(g.mlx, SW, SH, "cub3D");
    g.img = malloc(sizeof(t_image)); 
    g.img->i = mlx_new_image(g.mlx, SW, SH);
    g.img->addr = (int *)mlx_get_data_addr(g.img->i, &g.img->nbr, &g.img->nbr, &g.img->nbr);
    
    mlx_hook(g.mlxWin, 2, 1L<<0, movePress, &g);
    mlx_hook(g.mlxWin, 3, 1L<<1, moveRelease, &g);
    mlx_hook_loop(g.mlx, &game, &g);
    mlx_loop(g.mlx);
    return (0);
}
