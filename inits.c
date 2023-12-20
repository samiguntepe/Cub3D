/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:56 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/20 19:44:01 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	inits(t_cub *cub3d)
{
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
	ft_strcpy(cub3d->file.verify, "NO SO WE EA ");
}
