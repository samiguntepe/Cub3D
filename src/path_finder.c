/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:46 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/22 15:11:47 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../cub3d.h"

// int floodFill(t_file *fl, int i, int j, int size)
// {

//     if (i < 0 || i >= size || j < 0 || j >= size || fl->map[i][j] == '1' || fl->mapInt[i][j] == 1) {
//         return 1;
//     }
//     if (fl->map[i][j] == ' ') {
//         printf("Harita bozuk\n");
//         return 0;
//     }
//     fl->mapInt[i][j] = 1;

    
//     if (!floodFill(fl, i+1, j, size) || !floodFill(fl, i-1, j, size) || !floodFill(fl, i, j+1, size) || !floodFill(fl, i, j-1, size))
//         return 0;
//     return 1;
// }

// void testMap(t_file *fl)
// {
//     int i = 0;
//     while (fl->map[i]) 
// 	{
//         int j = 0;
//         while (fl->map[i][j] != '\0')
//         {

// 			if (fl->map[0][j] == ' ')
// 				j++;
// 			if (fl->map[0][j] != '1' && fl->map[0][j] != '\0')
// 				exit(printf("Invalid map!"));
//             j++;
//         }
//         i++;
//     }
// }