/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:31:12 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/31 18:36:42 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_info(t_game *info)
{
	info->map = NULL;
	info->players = 0;
	info->position_player_x = 0;
	info->position_player_y = 0;
	info->north = NULL;
	info->south = NULL;
	info->west = NULL;
	info->east = NULL;
	info->floor = NULL;
	info->ceiling = NULL;
	info->count_arguments_in_file = 0;
}

void	check_count_players(char **check_file, t_game *info)
{
	int	i;
	int	j;

	i = -1;
	while (check_file[++i])
	{
		j = 0;
		while (check_file[i][j])
		{
			if (check_file[i][j] == 'N' || check_file[i][j] == 'S' \
					|| check_file[i][j] == 'W' || check_file[i][j] == 'E')
			{
				info->players++;
				info->position_player_x = j + 0.5;
				info->position_player_y = i + 0.5;
				save_direction_player(info);
			}
			else if (check_file[i][j] != '0' && check_file[i][j] != '1' \
					&& check_file[i][j] != 32)
				print_error("Map is not valid", 1);
			j++;
		}
	}
	if (info->players != 1)
		print_error("Bad count of players", 1);
}

int	convert_colors(char *info)
{
	char	**arr;
	int		arr_int[3];
	int		i;

	i = 0;
	arr = ft_split(info, ',');
	if (len_pointer_arr(arr) != 3)
	{
		free_arr(arr);
		print_error("Color is not correctly", 1);
	}
	while (i < 3)
	{
		arr_int[i] = ft_atoi(arr[i]);
		if (arr_int[i] > 255 || arr_int[i] < 0)
		{
			free_arr(arr);
			print_error("Color is not correctly", 1);
		}
		i++;
	}
	free_arr(arr);
	return ((arr_int[0] << 16) + (arr_int[1] << 8) + arr_int[2]);
}

void	parsing_file(char *av, t_game *info, char *open_file, char **check_file)
{
	int		fd;
	char	buf[2];

	fd = open(av, O_RDONLY);
	open_file = calloc(1, 1);
	if (fd < 0)
		print_error("File is not correctly", 1);
	while (read(fd, buf, 1) > 0)
	{
		buf[1] = '\0';
		open_file = ft_strjoin(open_file, buf);
	}
	close(fd);
	check_file = ft_split(open_file, '\n');
	check_map_in_end(check_file);
	check_open_file(check_file, info);
	info->floor_color = convert_colors(info->floor);
	info->ceiling_color = convert_colors(info->ceiling);
	info->map = copy_map(check_file);
	check_count_players(info->map, info);
	check_every_string_of_map(info);
	check_wall_map(info);
	free(open_file);
	free_arr(check_file);
}
