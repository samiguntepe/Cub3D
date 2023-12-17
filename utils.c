/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:47:31 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/17 16:33:49 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

char	*ft_strjoin(char *str, char *add)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	new = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(add)) + 1));
	i = -1;
	j = 0;
	if (str)
		while (str[++i])
			new[i] = str[i];
	while (add[j])
		new[i++] = add[j++];
	new[ft_strlen(str) + ft_strlen(add)] = '\0';
	free(str);
	return (new);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i <= (n - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen (src));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *destination, const char *source)
{
	int	i = 0;
	if (destination == NULL)
	{
		destination = malloc(sizeof(char) * ft_strlen(source) + 1);
	}
    while (source[i] != '\0')
	{
        destination[i] = source[i];
		i++;
    }
    destination[i] = '\0';
	return (destination);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

int	ft_atoi(const char *str)
{
	int	d;
	int	s;

	d = 1;
	s = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
			str++;
	if (*str == '-')
	{
		d = d * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		s = (s * 10);
		s = s + (*str - '0');
		str++;
	}
	return (s * d);
}

// char *strtok_custom(char *str, const char *delim) 
// {
//     static char *ptr = NULL;
// 	if (*ptr == ',' && *(ptr+1) == '\0')
// 			exit(printf("hata"));
		
//     if (str != NULL) {
//         ptr = str;
//     } else if (ptr == NULL) {
//         return NULL; // İlk çağrıda string verilmediyse ve daha önce bir string işlenmediyse NULL döndür
//     }

//     // Ayraç karakterlerini geç
//     while (*ptr != '\0' && ft_strchr(delim, *ptr) != NULL) {
//         ptr++;
//     }

//     if (*ptr == '\0') {
//         return NULL; // String sonuna gelindi, NULL döndür
//     }

//     char *start = ptr; // Token'ın başlangıç adresi
//     // Token'ı bul
//     while (*ptr != '\0' && ft_strchr(delim, *ptr) == NULL) {
//         ptr++;
//     }

//     if (*ptr != '\0') {
//         *ptr = '\0'; // Null karakter ile token'ı bitir
//         ptr++; // Bir sonraki karaktere geç
//     }

//     return start; // Token'ı döndür
// }

char *strtok_custom(char *str, const char *delim) {
    static char *ptr = NULL;

    if (str != NULL) {
        ptr = str;
    } else if (ptr == NULL) {
        return NULL; // İlk çağrıda string verilmediyse ve daha önce bir string işlenmediyse NULL döndür
    }

    // Ayraç karakterlerini geç
    while (*ptr != '\0' && ft_strchr(delim, *ptr) != NULL) {
        ptr++;
    }

    if (*ptr == '\0') {
        return NULL; // String sonuna gelindi, NULL döndür
    }

    char *start = ptr; // Token'ın başlangıç adresi

    // Token'ı bul
    while (*ptr != '\0' && ft_strchr(delim, *ptr) == NULL) {
        ptr++;
    }

    if (*(ptr - 1) == ',') {
        return NULL; // Virgülün hemen sonrasında karakter yok, hata
    }

    if (*ptr != '\0') {
        *ptr = '\0'; // Null karakter ile token'ı bitir
        ptr++; // Bir sonraki karaktere geç
    }

    return start; // Token'ı döndür
}

char	*ft_strchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		s_len--;
	}
	return (NULL);
}


char	*ft_strtrim(char const *s1, char const *set)
{
	char	*m;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_checkset(s1[start], set))
		start++;
	while (end > start && ft_checkset(s1[end - 1], set))
		end--;
	m = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (start < end)
		m[i++] = s1[start++];
	m[i] = '\0';
	return (m);
}

int	ft_checkset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}