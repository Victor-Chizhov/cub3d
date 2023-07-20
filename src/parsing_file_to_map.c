/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:31:12 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/16 13:25:45 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	init_info(t_game *info)
{
	info->map = NULL;
	info->height_map = 0;
	info->width_map = 0;
	info->players = 0;
	info->walls = 0;
	info->empty_space = 0;
	info->map_exit = 0;
	info->items = 0;
	info->position_player_x = 0;
	info->position_player_y = 0;
	info->step_count = 0;
	info->north = NULL;
	info->south = NULL;
	info->west = NULL;
	info->east = NULL;
	info->floor = NULL;
	info->ceilling = NULL;
	info->count_arguments_in_file = 0;

}


void	check_count_players_and_exits(char **check_file, t_game *info)
{
	int	i;
	int j;

	i = 0;
	while (check_file[i])
	{
		j = 0;
		while(check_file[i][j])
		{
			if (check_file[i][j] == 'N' || check_file[i][j] == 'S' || check_file[i][j] == 'W' || check_file[i][j] == 'E')
			{
				info->players++;
				info->position_player_x = j;
				info->position_player_y = i;
				if (info->players > 1) {
					printf("In check_count_players_and_exits Too many players\n");
					print_error(1);
				}
			}
			else if (check_file[i][j] != '0' && check_file[i][j] != '1' && check_file[i][j] != 32)
			{
				printf("In check_count_players_and_exits map don't valid\n");
				print_error(1);
			}
			j++;
		}
		i++;
	}
}

void	parsing_file(char *av, t_game *info)
{
	int		fd;
	char	*open_file;
	char 	**check_file;
	char	buf[2];

	fd = open(av, O_RDONLY);
	open_file = calloc(1, 1);
	if (fd < 0)
	{
		print_error(1);
	}
	while (read(fd, buf, 1) > 0)
	{
		buf[1] = '\0';
		open_file = ft_strjoin(open_file, buf);
	}
	close(fd);
	check_file = ft_split(open_file, '\n');
	check_map_in_end(check_file);
	check_open_file(check_file, info);
	check_count_players_and_exits(check_file, info);
	info->map = copy_map(check_file);
	check_every_string_of_map(info);
	check_wall_map(info);
	read_arr(info->map);
//	check_no_exit(map);


	free(open_file);
	free_arr(check_file);

//	read_arr(info->map);
//	printf("info->NO = %s\n", info->north);
//	printf("info->SO = %s\n", info->south);
//	printf("info->WE = %s\n", info->west);
//	printf("info->EA = %s\n", info->east);
//	printf("info->F = %s\n", info->floor);
//	printf("info->C = %s\n", info->ceilling);
}
