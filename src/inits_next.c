/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:43:15 by sguntepe          #+#    #+#             */
/*   Updated: 2024/01/15 02:11:03 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

void	inits(t_game *game)
{
	game->file = init_t_file();
	if (game->file == NULL)
		exit_game(game, "Allocation is failed!");
	game->img = init_t_image();
	if (game->img == NULL)
		exit_game(game, "Allocation is failed!");
	init_t_texture(&game->text);
	texture_init(game);
	init_t_game(game);
	init_t_raycast(&game->ray);
}

void	upload_image(t_game *g)
{
	int	n;
	int	k;

	g->text.imgno->img = mlx_xpm_file_to_image(g->mlx, g->file->no, &n, &n);
	if (g->text.imgno->img == NULL)
		exit_game(g, "Wrong, texture path!");
	g->text.imgso->img = mlx_xpm_file_to_image(g->mlx, g->file->so, &n, &n);
	if (g->text.imgso->img == NULL)
		exit_game(g, "Wrong, texture path!");
	g->text.imgea->img = mlx_xpm_file_to_image(g->mlx, g->file->ea, &n, &n);
	if (g->text.imgea->img == NULL)
		exit_game(g, "Wrong, texture path!");
	g->text.imgwe->img = mlx_xpm_file_to_image(g->mlx, g->file->we, &n, &n);
	if (g->text.imgwe->img == NULL)
		exit_game(g, "Wrong, texture path!");
	g->text.imgno->addr
		= (int *)mlx_get_data_addr(g->text.imgno->img, &k, &k, &k);
	g->text.imgso->addr
		= (int *)mlx_get_data_addr(g->text.imgso->img, &k, &k, &k);
	g->text.imgea->addr
		= (int *)mlx_get_data_addr(g->text.imgea->img, &k, &k, &k);
	g->text.imgwe->addr
		= (int *)mlx_get_data_addr(g->text.imgwe->img, &k, &k, &k);
}

void	texture_init(t_game *g)
{
	g->text.imgno = malloc(sizeof(t_image));
	if (!g->text.imgno)
		exit_game(g, "Allocation is failed!");
	g->text.imgso = malloc(sizeof(t_image));
	if (!g->text.imgso)
		exit_game(g, "Allocation is failed!");
	g->text.imgwe = malloc(sizeof(t_image));
	if (!g->text.imgwe)
		exit_game(g, "Allocation is failed!");
	g->text.imgea = malloc(sizeof(t_image));
	if (!g->text.imgea)
		exit_game(g, "Allocation is failed!");
}

void	inits_rgb(t_game *g)
{
	char	**ptr_f;
	char	**ptr_c;

	ptr_f = ft_split(g->file->f, ',');
	ptr_c = ft_split(g->file->c, ',');
	g->text.floor
		= create_rgb(ft_atoi(ptr_f[0]),
			ft_atoi(ptr_f[1]), ft_atoi(ptr_f[2]));
	g->text.ceiling
		= create_rgb(ft_atoi(ptr_c[0]),
			ft_atoi(ptr_c[1]), ft_atoi(ptr_c[2]));
	double_array_free(ptr_f);
	double_array_free(ptr_c);
}
