/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:56 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/25 13:27:25 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <unistd.h>

void	inits(t_file *fl)
{
	char	*ptr;

	ptr = NULL;
	fl->EA = NULL;
	fl->SO = NULL;
	fl->WE = NULL;
	fl->NO = NULL;
	fl->C = NULL;
	fl->F = NULL;
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
	g->text.texHeight = 64;
	g->text.texWidth = 64;
}

void	inits_rgb(t_game *g)
{
	char	**ptr_f;
	char	**ptr_c;

	ptr_f = ft_split(g->file->F, ',');
	ptr_c = ft_split(g->file->C, ',');
	g->text.floor
		= create_rgb(ft_atoi(ptr_f[0]),
			ft_atoi(ptr_f[1]), ft_atoi(ptr_f[2]));
	g->text.ceiling
		= create_rgb(ft_atoi(ptr_c[0]),
			ft_atoi(ptr_c[1]), ft_atoi(ptr_c[2]));
	double_array_free(ptr_f, 3);
	double_array_free(ptr_c, 3);
}

void	texture_init(t_game *g)
{
	g->text.imgNO = malloc(sizeof(t_image));
	if (!g->text.imgNO)
		exit(printf("Error\n"));
	g->text.imgSO = malloc(sizeof(t_image));
	if (!g->text.imgNO)
		exit(printf("Error\n"));
	g->text.imgWE = malloc(sizeof(t_image));
	if (!g->text.imgNO)
		exit(printf("Error\n"));
	g->text.imgEA = malloc(sizeof(t_image));
	if (!g->text.imgNO)
		exit(printf("Error\n"));
}

void	texture_init_next(t_game *g)
{
	int	n;
	int	k;

	g->text.imgNO->img = mlx_xpm_file_to_image(g->mlx, g->file->NO, &n, &n);
	if (g->text.imgNO->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgSO->img = mlx_xpm_file_to_image(g->mlx, g->file->SO, &n, &n);
	if (g->text.imgSO->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgEA->img = mlx_xpm_file_to_image(g->mlx, g->file->EA, &n, &n);
	if (g->text.imgEA->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgWE->img = mlx_xpm_file_to_image(g->mlx, g->file->WE, &n, &n);
	if (g->text.imgWE->img == NULL)
		exit(printf("Wrong, texture path!\nError\n"));
	g->text.imgNO->addr
		= (int *)mlx_get_data_addr(g->text.imgNO->img, &k, &k, &k);
	g->text.imgSO->addr
		= (int *)mlx_get_data_addr(g->text.imgSO->img, &k, &k, &k);
	g->text.imgEA->addr
		= (int *)mlx_get_data_addr(g->text.imgEA->img, &k, &k, &k);
	g->text.imgWE->addr
		= (int *)mlx_get_data_addr(g->text.imgWE->img, &k, &k, &k);
}
