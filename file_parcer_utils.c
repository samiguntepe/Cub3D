#include "cub3d.h"
#include <stdlib.h>

int	*point_ignore_line(t_file	*fl)
{
	int i;
	int j;
	int	k;
	size_t	count;

	i = 0;
	count = 0;
	k = 0;
	while (fl->lines[i])
	{
		j = 0;
		while (fl->lines[i][j])
		{
			if (fl->lines[i][j] < 32)
				count++;
			if (count == ft_strlen(fl->lines[i]))
				fl->wrgLines[k++] = i;
			j++;
		}
		i++;
	}
	return (fl->wrgLines);
}

int count_lines(t_file	*fl)
{
    int line_count;
    int index;

	fl->wrgLines_count = 0;
	line_count = 0;
	index = 0;
    while (fl->lines[index] != '\0')
	{
        if (fl->lines[index] == '\n')
            line_count++;
		if (fl->lines[index] < 32)
            line_count++;
        index++;
    }
    return line_count + 1;
}
