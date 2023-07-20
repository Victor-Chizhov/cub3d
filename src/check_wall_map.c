#include "../include/cub3d.h"

int	is_closed(int i, int j, t_game *info)
{
	if (info->map[i][j] == '0' || (info->map[i][j] != '1' && info->map[i][j] != ' '))
	{
		if (i == 0 || !info->map[i + 1] || j == 0 || !info->map[i][j + 1])
			return (1);
		if (info->map[i - 1] && info->map[i - 1][j] && info->map[i - 1][j] == ' ')
			return (1);
		if (info->map[i + 1] && info->map[i + 1][j] && info->map[i + 1][j] == ' ')
			return (1);
		if (info->map[i] && info->map[i][j - 1] && info->map[i][j - 1] == ' ')
			return (1);
		if (info->map[i] && info->map[i][j + 1] && info->map[i][j + 1] == ' ')
			return (1);
	}
	return (0);
}


void check_closed_map(t_game *info)
{
	int i;
	int j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j]) {
			if (is_closed(i, j, info) == 1)
				print_error(1);
			j++;
		}
		i++;
	}
}

void check_size_map(t_game *info)
{
	int row;
	int col;
	int j;

	row = 0;
	while (info->map[row])
	{
		col = 0;
		j = 0;
		while (info->map[row][col] && info->map[row][col] == ' ')
			col++;
		while(info->map[row][col]) {
			j++;
			col++;
		}
		if(j <= 2)
			print_error(1);
		row++;
	}
	if (row <= 2)
		print_error(1);

}

void check_wall_map(t_game *info)
{
	check_size_map(info);
	check_closed_map(info);
}