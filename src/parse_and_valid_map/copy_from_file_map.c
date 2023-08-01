/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_from_file_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:53:30 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/31 17:56:04 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_map_in_end(char **check_file)
{
	int	i;
	int	j;

	j = 0;
	i = len_pointer_arr(check_file) - 1;
	while (check_file[i][j] && check_file[i][j] == ' ')
		j++;
	if (check_file[i][j] != '1')
		print_error("Map is not in end or have no 1", 1);
}

int	start_map(char **check_file)
{
	int	i;
	int	j;

	i = 0;
	while (check_file[i])
	{
		j = 0;
		while (check_file[i][j] && check_file[i][j] == ' ')
			j++;
		if (check_file[i][j] == '1' || check_file[i][j] == '0')
			return (i);
		i++;
	}
	return (0);
}

int	end_map(char **check_file)
{
	int	i;
	int	j;

	i = len_pointer_arr(check_file) - 1;
	while (check_file[i])
	{
		j = 0;
		while (check_file[i][j] && check_file[i][j] == ' ')
			j++;
		if (check_file[i][j] == '1' || check_file[i][j] == '0')
			return (i);
		i--;
	}
	return (0);
}

char	**copy_after_check_map(char **check_file, int start, int end)
{
	char	**map;
	int		row;

	row = 0;
	map = malloc(sizeof(char *) * (end - start + 1) + 8);
	while (start <= end)
	{
		map[row] = ft_strdup(check_file[start]);
		start++;
		row++;
	}
	map[row] = NULL;
	return (map);
}

char	**copy_map(char **check_file)
{
	char	**map;
	int		start;
	int		end;

	start = start_map(check_file);
	end = end_map(check_file);
	map = copy_after_check_map(check_file, start, end);
	return (map);
}
