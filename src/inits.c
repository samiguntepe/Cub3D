/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:56 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/21 14:16:33 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	inits(t_cub *cub3d)
{
	char *ptr;
	cub3d->file.EA = NULL;
	cub3d->file.SO = NULL;
	cub3d->file.WE = NULL;
	cub3d->file.NO = NULL;
	cub3d->file.C = NULL;
	cub3d->file.F = NULL;
	cub3d->file.map_h = 0;
	cub3d->file.map_w = 0;
	cub3d->file.control_index[0] = NULL;
	cub3d->file.control_index[1] = NULL;
	ptr = cub3d->file.verify;
	ft_strcpy(&ptr, "NO SO WE EA ");
}

void	game_inits()
{
	g.w = false;
    g.a = false;
    g.s = false;
    g.d = false;
    g.left = false;
    g.right = false;
}
