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

