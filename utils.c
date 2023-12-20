/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:47:31 by sguntepe          #+#    #+#             */
/*   Updated: 2023/12/20 19:55:36 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
    size_t len_s1 = 0;
    size_t len_s2 = 0;

    if (s1 != NULL)
        len_s1 = ft_strlen(s1);
    if (s2 != NULL)
        len_s2 = ft_strlen(s2);

    size_t total_len = len_s1 + len_s2;
    char *result;

    if (s1 == NULL && s2 == NULL)
        return NULL;

    result = (char *)malloc(sizeof(char) * (total_len + 1));
    if (result == NULL)
        return NULL;

    if (len_s1 > 0)
        ft_strcpy(result, s1);
    if (len_s2 > 0)
        ft_strcpy(result + len_s1, s2);

    result[total_len] = '\0';
    return result;
}

char	*ft_freejoin(const char *s1, const char *s2)
{
    size_t len_s1 = 0;
    size_t len_s2 = 0;

    if (s2 != NULL)
        len_s2 = ft_strlen(s2);
    if (s1 != NULL)
        len_s1 = ft_strlen(s1);
	else
		s1 = malloc(sizeof(char) * len_s2 + 1);

    size_t total_len = len_s1 + len_s2;
    char *result;

    if (s1 == NULL && s2 == NULL)
        return NULL;

    result = (char *)malloc(sizeof(char) * (total_len + 1));
    if (result == NULL)
        return NULL;

    if (len_s1 > 0)
        ft_strcpy(result, s1);
    if (len_s2 > 0)
        ft_strcpy(result + len_s1, s2);

    result[total_len] = '\0';
    return result;
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

    if (*ptr != '\0') {
        if (*(ptr + 1) == '\0' || ft_strchr(delim, *(ptr + 1)) != NULL) {
            return NULL; // Virgülün hemen sonrasında karakter yok, hata
        }
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

int	wordcounter(const char *s, char delimiter)
{
	unsigned int	word;

	word = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			while (*s != delimiter && *s)
				s++;
			word++;
		}
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	j;
	unsigned int	a;

	if (!s)
		return (NULL);
	arr = (char **) ft_calloc(wordcounter(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	a = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (*s != c && *s && ++j)
				s++;
			arr[++a -1] = (char *) ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(arr[a -1], s - j, j + 1);
		}
	}
	return (arr);
}


void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}


void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

char*	ft_strstr(const char* str, const char* substr)
{
    if (*substr == '\0') {
        return (char*)str; // Alt string boşsa, ana stringin başlangıcını döndür
    }

    while (*str != '\0') {
        const char* temp_str = str;
        const char* temp_substr = substr;

        while (*temp_substr != '\0' && *temp_str == *temp_substr) {
            temp_str++;
            temp_substr++;
        }

        if (*temp_substr == '\0') {
            return (char*)str; // Alt string bulundu, ana stringdeki başlangıç adresini döndür
        }

        str++;
    }

    return NULL; // Alt string bulunamadı
}