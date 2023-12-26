/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:56 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/26 21:25:33 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <unistd.h>

void	inits(t_file *fl)
{
	char	*ptr;

	ptr = NULL;
	fl->ea = NULL;
	fl->no = NULL;
	fl->we = NULL;
	fl->so = NULL;
	fl->c = NULL;
	fl->f = NULL;
	fl->map_h = 0;
	fl->map_w = 0;
	ptr = fl->verify;
	ft_strcpy(&ptr, "NO SO WE EA ");
}

void	game_inits(t_game *g)
{
	g->w = false;
	g->a = false;
	g->s = false;
	g->d = false;
	g->left = false;
	g->right = false;
	g->speed = 0.100f;
	g->rspeed = 0.05f;
	g->text.tx_height = 64;
	g->text.tx_width = 64;
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

void	texture_init(t_game *g)
{
	g->text.imgno = malloc(sizeof(t_image));
	if (!g->text.imgno)
		exit(printf("Error\n"));
	g->text.imgso = malloc(sizeof(t_image));
	if (!g->text.imgso)
		exit(printf("Error\n"));
	g->text.imgwe = malloc(sizeof(t_image));
	if (!g->text.imgwe)
		exit(printf("Error\n"));
	g->text.imgea = malloc(sizeof(t_image));
	if (!g->text.imgea)
		exit(printf("Error\n"));
}

void	texture_init_next(t_game *g)
{
	int	n;
	int	k;

	g->text.imgno->img = mlx_xpm_file_to_image(g->mlx, g->file->no, &n, &n);
	if (g->text.imgno->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgso->img = mlx_xpm_file_to_image(g->mlx, g->file->so, &n, &n);
	if (g->text.imgso->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgea->img = mlx_xpm_file_to_image(g->mlx, g->file->ea, &n, &n);
	if (g->text.imgea->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgwe->img = mlx_xpm_file_to_image(g->mlx, g->file->we, &n, &n);
	if (g->text.imgwe->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgno->addr
		= (int *)mlx_get_data_addr(g->text.imgno->img, &k, &k, &k);
	g->text.imgso->addr
		= (int *)mlx_get_data_addr(g->text.imgso->img, &k, &k, &k);
	g->text.imgea->addr
		= (int *)mlx_get_data_addr(g->text.imgea->img, &k, &k, &k);
	g->text.imgwe->addr
		= (int *)mlx_get_data_addr(g->text.imgwe->img, &k, &k, &k);
}
