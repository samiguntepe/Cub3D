#include "../cub3d.h"

void	game_free(t_game *g)
{
	int len;

	free(g->file->NO);
	free(g->file->WE);
	free(g->file->EA);
	free(g->file->SO);
	free(g->file->F);
	free(g->file->C);
	len = line_counter(g->file->whole_lines);
	double_array_free(g->file->map, g->file->map_h);
	double_array_free(g->file->lines, len);
	// doubleInt_array_free(g->file->mapInt, len);
	double_array_free(g->file->control_index, 0);
	free(g->file->whole_lines);
}

void	double_array_free(char **arr, int len)
{
	int	i;

	i = 0;
	if (len == 0)
	{
		free(arr[0]);
		free(arr[1]);
		free(arr[2]);
		return ;
	}
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	doubleInt_array_free(int **arr, int len)
{
	int	i;

	i = 0;
	if (len == 0)
	{
		if (arr[0])
			free(arr[0]);
		if (arr[1])
			free(arr[1]);
		if (arr[2])
			free(arr[2]);
	}
	while (i < len)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}