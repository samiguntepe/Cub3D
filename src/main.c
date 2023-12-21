/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:52 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/21 16:59:00 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../cub3d.h"

int	main(void)
{
	t_cub cub3d;

	inits(&cub3d);
	cub3d.file.fd = open("mapfile.cub", O_RDONLY);
    if (cub3d.file.fd == -1) {
        perror("Dosya açılamadı");
        return 0;
    }
	 int b;
    char *path = "./42N.xpm";
	file_parcer(&cub3d.file);
	g.mlx = mlx_init();
    g.mlxWin = mlx_new_window(g.mlx, SW, SH, "cub3D");
    g.image = malloc(sizeof(t_image));
    g.image->image = mlx_new_image(g.mlx, SW, SH);
    g.image->addr = (int*)mlx_get_data_addr(g.image->image, &a, &a, &a);

	g.NO = malloc(sizeof(t_image));
    if (!g.NO)
    {
        printf("%s\n", "error");
        return (1);
    }
	int k;
    g.NO->image = mlx_xpm_file_to_image(g.mlx, path, &b, &b);
    g.NO->addr = (int *)mlx_get_data_addr(g.NO->image, &k, &k, &k);
    mlx_hook(g.mlxWin, 2, 1L << 0, movePress, &g);
    mlx_hook(g.mlxWin, 3, 1L << 1, moveRelease, &g);
    mlx_loop_hook(g.mlx, &game, &g);
    mlx_loop(g.mlx);
    return (0);
}
