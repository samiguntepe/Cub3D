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
	fl->wrgLines = malloc(fl->wrgLines_count * sizeof(int));
	while (fl->lines[i])
	{
		j = 0;
		while (fl->lines[i][j] != '\0')
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

void	count_wrgLine(t_file *fl)
{
	int i;
	int j;
	int	k;
	size_t	count;

	i = 0;
	k = 0;
	fl->wrgLines_count = 0;
	while (fl->lines[i])
	{
		// printf("%s\n", fl->lines[i]);
		j = 0;
		count = 0;
		while (fl->lines[i][j] != '\0')
		{
			// if (fl->lines[i][j] < 32 && fl->lines[i][j] != '\n')
			// 	count++;
			printf("%d\n", j);
			j++;
		// printf("%zu  ", count);
		// printf("%d\n", j );
		}
		// printf("%d\n", fl->wrgLines_count);


		if (count == ft_strlen(fl->lines[i]))
			fl->wrgLines_count++;
		i++;
	}
}

// char **split_lines(const char *str) {
//     int line_count = 0;
   

//     // Bellekte satırları saklamak için yer ayır
//     char **lines = (char **)malloc(line_count * sizeof(char *));
//     if (!lines) {
//         return NULL;
//     }

//     // Her satırı '\n' karakterine göre ayır ve diziye kopyala
//     int index = 0;
//     const char *start = str;
//     ptr = str;

//     while (*ptr != '\0') {
//         if (*ptr == '\n') {
//             int len = ptr - start + 1; // Satır uzunluğu
//             lines[index] = (char *)malloc(len);
//             if (!lines[index]) {
//                 // Bellek hatası, var olan belleği temizle ve NULL döndür
//                 for (int i = 0; i < index; i++) {
//                     free(lines[i]);
//                 }
//                 free(lines);
//                 return NULL;
//             }
//             ft_strlcpy(lines[index], start, len - 1); // Satırı kopyala
//             lines[index][len - 1] = '\0'; // Null karakter ekle
//             index++;
//             start = ptr + 1; // Bir sonraki satırın başlangıcı
//         }
//         ptr++;
//     }

//     // Son satırı da ekle
//     int len = ptr - start + 1;
//     lines[index] = (char *)malloc(len);
//     if (!lines[index]) {
//         for (int i = 0; i <= index; i++) {
//             free(lines[i]);
//         }
//         free(lines);
//         return NULL;
//     }
//     ft_strlcpy(lines[index], start, len - 1);
//     lines[index][len - 1] = '\0';

//     return lines;
// }

// void free_lines(char **lines, int line_count) {
//     for (int i = 0; i < line_count; i++) {
//         free(lines[i]);
//     }
//     free(lines);
// }

int	line_counter(char *str)
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
