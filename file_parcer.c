#include "cub3d.h"
#include <stdio.h>

void	file_parcer(t_file *file)
{
	char	*all_lines;
	int		i;
	int		j;

	all_lines = read_file(file->fd);
	file->lines = ft_split(all_lines, '\n');
	i = 0;
	j = 0;
	while (file->lines[i])
	{
		printf("%s---",file->lines[i]);
		i++;
	}
	

}