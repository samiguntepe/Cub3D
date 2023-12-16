#include "cub3d.h"
#include <stdlib.h>

char **split_lines(const char *str)
{
	int line_count;
	
	line_count = line_counter(str);
	char **lines = (char **)malloc((line_count + 1) * sizeof(char *));
	if (!lines)
		return NULL;

	int i = 0;
	int start = 0;
	int line_length = 0;
	int j = 0;

	while (str[start] != '\0')
	{
		line_length = get_line_length(str, i, '\n');

		if (line_length == -1)
			break;

		lines[i] = (char *)malloc((line_length + 1) * sizeof(char));

		if (!lines[i]) 
		{
			while (j < i)
			{
				free(lines[j]);
				j++;
			}
			free(lines);
			return NULL;
		}

		ft_strlcpy(lines[i], &str[start], line_length);
		lines[i][line_length] = '\0';
		start += line_length + 1;
		i++;
	}

	lines[i] = NULL;

	return lines;
}


int	line_counter(const char *str)
{
	int	line_count;

	line_count = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
			line_count++;
		str++;
	}
	if (*(str - 1) != '\n')
		line_count++;
	return (line_count);
}


int get_line_length(const char *str, int line_number, char sep)
{
    int line_count = 0;
    int i = 0;

    while (str[i] != '\0' && line_count < line_number) {
        if (str[i] == sep || str[i] == '\0') {
            line_count++;
        }
        i++;
    }

    if (line_count == line_number) {
        int line_length = 0;
        while (str[i] != '\0' && str[i] != sep) {
            line_length++;
            i++;
        }
        return line_length;
    }

    return -1;
}