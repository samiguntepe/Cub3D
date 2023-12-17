/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:50 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/17 16:01:36 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include <stdlib.h>

void	control_components(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'N' ||
				map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W');
			else
				perror("Error\n");
			j++;
		}
		i++;
	}
}

int control_RGB_path(char *mainStr, char *subStr) {
    int i = 0;
    int main_length = ft_strlen(mainStr);
    int sub_length = ft_strlen(subStr);

    while (i <= main_length - sub_length) {
        int j = 0;

        if (mainStr[i] == subStr[0]) {
            while (j < sub_length && mainStr[i + j] == subStr[j]) {
                j++;
            }

            if (j == sub_length) {
                while (mainStr[i + j] != '\0') {
                    if (mainStr[i + j] > 32) {
                        return 0;
                    }
                    j++;
                }
                return 1;
            }
        }
        i++;
    }
    return 0;
}


int	control_RGB_comma(char *kod)
{
    int virgul_sayisi = 0;

    for (int i = 0; kod[i] != '\0'; i++) {
        if (kod[i] == ',') {
            virgul_sayisi++;
        } else if (!(kod[i] >= '0' && kod[i] <= '9')) {
            return 0; // Rakam veya virgül dışında bir karakter var, hata
        }
    }

    if (virgul_sayisi != 2) {
        return 0; // Virgül sayısı 2 değil, hata
    }

    char *token;
    char *kopya = ft_strdup(kod); // Veriyi bozmamak için kopyalama
    if (kopya == NULL) {
        return 0; // Bellek hatası
    }

    token = strtok_custom(kopya, ",");
	if (token == NULL)
		exit(printf("Wrong RGB Error\n"));
    while (token != NULL) {
        int deger = ft_atoi(token);
		printf("%d\n", deger);
        if ((deger < 0 || deger > 255)) {
            free(kopya);
            return 0; // RGB aralığında olmayan bir değer, hata
        }
        token = strtok_custom(NULL, ",");
    }

    free(kopya);
    return 1; // Her şey uygun
}


void	map_control(t_cub	*cub3d)
{
	(void)cub3d;
}
