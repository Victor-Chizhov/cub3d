/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:28:05 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/31 17:32:21 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_closed(int i, int j, t_game *info)
{
	if (info->map[i][j] == '0')
	{
		if (info->map[i - 1][j] != '1' && info->map[i - 1][j] != '0' \
				&& info->map[i - 1][j] != 'N' && info->map[i - 1][j] != 'S' \
				&& info->map[i - 1][j] != 'E' && info->map[i - 1][j] != 'W')
			return (1);
		if (info->map[i + 1][j] != '1' && info->map[i + 1][j] != '0' \
				&& info->map[i + 1][j] != 'N' && info->map[i + 1][j] != 'S' \
				&& info->map[i + 1][j] != 'E' && info->map[i + 1][j] != 'W')
			return (1);
		if (info->map[i][j - 1] != '1' && info->map[i][j - 1] != '0' \
				&& info->map[i][j - 1] != 'N' && info->map[i][j - 1] != 'S' \
				&& info->map[i][j - 1] != 'E' && info->map[i][j - 1] != 'W')
			return (1);
		if (info->map[i][j + 1] != '1' && info->map[i][j + 1] != '0' \
				&& info->map[i][j + 1] != 'N' && info->map[i][j + 1] != 'S' \
				&& info->map[i][j + 1] != 'E' && info->map[i][j + 1] != 'W')
			return (1);
	}
	return (0);
}

void	check_closed_map(t_game *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (is_closed(i, j, info) == 1)
				print_error("Map don't have walls", 1);
			j++;
		}
		i++;
	}
}

void	check_size_map(t_game *info)
{
	int	row;
	int	col;
	int	j;

	row = 0;
	while (info->map[row])
	{
		col = 0;
		j = 0;
		while (info->map[row][col] && info->map[row][col] == ' ')
			col++;
		while (info->map[row][col])
		{
			j++;
			col++;
		}
		if (j <= 2)
			print_error("Map is not valid", 1);
		row++;
	}
	if (row <= 2)
		print_error("Map is not valid", 1);
}

void	check_wall_map(t_game *info)
{
	check_size_map(info);
	check_closed_map(info);
}
