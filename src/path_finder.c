/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:11:46 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/24 11:45:43 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../cub3d.h"

int floodFill(t_file *fl, int i, int j, int size)
{

    if (i < 0 || i >= size || j < 0 || j >= size || fl->map[i][j] == '1' || fl->mapInt[i][j] == 1) {
        return 1;
    }
    if (fl->map[i][j] == ' ') {
        printf("Harita bozuk\n");
        return 0;
    }
    fl->mapInt[i][j] = 1;

    
    if (!floodFill(fl, i+1, j, size) || !floodFill(fl, i-1, j, size) || !floodFill(fl, i, j+1, size) || !floodFill(fl, i, j-1, size))
        return 0;
    return 1;
}

void testMap(t_file *fl)
{
    int i = 0;
    while (fl->map[i]) 
	{
        int j = 0;
        while (fl->map[i][j] != '\0')
        {

			if (fl->map[0][j] == ' ')
				j++;
			if (fl->map[0][j] != '1' && fl->map[0][j] != '\0')
				exit(printf("Invalid map!"));
            j++;
        }
        i++;
    }
}

int horizontalcheck(char **map, int i, int j, int flag)
{
    char *tmp;
    while (map[++i])
    {
        flag = 0;
        j = -1;
        tmp = ft_strtrim(map[i], " ");
        if (tmp[ft_strlen(tmp) - 1] != '1')
            return (free(tmp), 0);
        free(tmp);
        while (map[i][++j])
        {
            if (flag == 0 && map[i][j] == '1')
                flag = 1;
            else if (flag == 1 && map[i][j] == ' ')
            {
                if (map[i][j - 1] && ft_strchr("0NSEW", map[i][j - 1]))
                    return (0);
                flag = 0;
            }
            if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
                return (0);
        }
    }
    return (1);
}
int verticalcheck(char **map, int i, int j, int flag)
{
    while (map[0][++j])
    {
        flag = 0;
        i = 0;
        while (map[i] && map[i][j])
        {
            if (flag == 0 && map[i][j] == '1')
                flag = 1;
            else if (flag == 1 && map[i][j] == ' ')
            {
                if (map[i - 1] && map[i - 1][j] && ft_strchr("0NSEW", map[i - 1][j]))
                    return (0);
                flag = 0;
            }
            if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
                return (0);
            if (!map[i + 1] && ft_strchr("NSEW0", map[i][j]))
                return (0);
            i++;
        }
    }
    return (1);
}
int check_map_surrounded(t_game *game)
{
    if (!verticalcheck(game->file->map, -1, -1, 0)
        || !horizontalcheck(game->file->map, -1, -1, 0))
    {
        // free_all(game);
        // ft_exit("Error: map is not surrounded by wall");
		printf("map is valid!");
		exit(1);
    }
    return (1);
}

// char    *ft_strtrim(char const *s1, char const *s2)
// {
//     int     i;
//     int     end;
//     int     start;
//     char    *str;
//     if (!s1)
//         return (NULL);
//     end = ft_strlen(s1);
//     start = 0;
//     while (s1[start] != '\0' && checker(s2, s1[start]))
//         start++;
//     while (start < end && checker(s2, s1[end - 1]))
//         end--;
//     str = (char *)malloc(sizeof(char) * (end - start + 1));
//     if (!str)
//         return (0);
//     i = 0;
//     while (start < end)
//     {
//         str[i] = s1[start];
//         i++;
//         start++;
//     }
//     str[i] = '\0';
//     return (str);
// }

// char    *ft_strchr(const char *s, int c)
// {
//     while (*s != (char)c && *s != '\0')
//         s++;
//     if (*s == '\0')
//     {
//         if (c != '\0')
//             return (NULL);
//         else
//             return ((char *)s);
//     }
//     return ((char *)s);
// }