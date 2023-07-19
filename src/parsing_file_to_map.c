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

char *check_symbols_f_and_c(char *check_file)
{
	char *tmp;
	int i;

	i = 0;
	tmp = remove_spaces_from_str(check_file);
	tmp++;
	while(tmp[i])
	{
		if (tmp[i] < ',' || (tmp[i] > ',' && tmp[i] < '0')  || tmp[i] > '9')
			return (NULL);
		i++;
	}
    return tmp;
}


void	init_info(t_game *map)
{
	map->map = NULL;
	map->height_map = 0;
	map->width_map = 0;
	map->players = 0;
	map->walls = 0;
	map->empty_space = 0;
	map->map_exit = 0;
	map->items = 0;
	map->position_player_x = 0;
	map->position_player_y = 0;
	map->step_count = 0;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->floor = NULL;
	map->ceilling = NULL;
}

void check_map_in_end(char **check_file)
{
	int i;
	int j;

	j = 0;
	i = len_pointer_arr(check_file) - 1;
	while(check_file[i][j] && check_file[i][j] == ' ')
		j++;
	if (check_file[i][j] != '1') {
		print_error(1);
	}
}

char **cut_map(char **check_file)
{
	int i;
	int j;
	int k;
	char **map;
	char **dublicate;

	i = 0;
	j = 0;
	map = malloc(len_pointer_arr(check_file) * sizeof(char *) + 8);
	dublicate = create_dublicate(check_file);
	while (check_file[i])
	{
		check_file[i] = ft_strtrim(check_file[i], " ");
		if (check_file[i][0] == '1')
		{
			map[j] = malloc(ft_strlen(dublicate[i]) * sizeof(char) + 1);
			k = 0;
			while (dublicate[i][k])
			{
				map[j][k] = dublicate[i][k];
				k++;
			}
			map[j][k] = '\0';
			j++;
		}
		i++;
	}
	map[j] = NULL;
	return (map);
}

char *copy_from_file(char *check_file)
{
	char **arr;
	char *new;

	new = NULL;
	arr = ft_split(check_file, ' ');
	if (len_pointer_arr(arr) != 2)
	{
		free_arr(arr);
		print_error(1);
	}
	new = ft_strdup(arr[1]);
	free(check_file);
	check_file = NULL;
	return new;
}

char *copy_from_file_for_f_and_c(char *check_file)
{
	char *new;

	new = NULL;

	if (!check_symbols_f_and_c(check_file))
		print_error(1);
	else
	{
		new = ft_substr(check_file, 1, ft_strlen(check_file) - 1);
		free(check_file);
		check_file = NULL;
	}
	return new;
}

void	check_open_file(char **check_file, t_game *info)
{
	int	i;
	char **arr;
	int j;

	i = 0;
	arr = NULL;
	while (check_file[i])
	{
		j = 0;
		while(check_file[i][j] && check_file[i][j] == ' ')
			j++;
		if(check_file[i][j] == 'N' && check_file[i][j + 1] == 'O' && check_file[i][j + 2] == ' ')
			info->north = copy_from_file(check_file[i]);
		else if (check_file[i][j] == 'S' && check_file[i][j + 1] == 'O' && check_file[i][j + 2] == ' ')
			info->south = copy_from_file(check_file[i]);
		else if (check_file[i][j] == 'W' && check_file[i][j + 1] == 'E' && check_file[i][j + 2] == ' ')
			info->west = copy_from_file(check_file[i]);
		else if (check_file[i][j] == 'E' && check_file[i][j + 1] == 'A' && check_file[i][j + 2] == ' ')
			info->east = copy_from_file(check_file[i]);
		else if (check_file[i][j] == 'F' && check_file[i][j + 1] == ' ')
		{
			if (!check_symbols_f_and_c(check_file[i])) {
                print_error(1);
            }
			else
			{
				info->floor = ft_substr(check_file[i], 1, ft_strlen(check_file[i]) - 1);
				free(check_file[i]);
				check_file[i] = ft_strdup(" ");
			}
		}
		else if (check_file[i][j] == 'C' && check_file[i][j + 1] == ' ')
		{
			if (!check_symbols_f_and_c(check_file[i]))
				print_error(1);
			else
			{
				info->ceilling = ft_substr(check_file[i], 1, ft_strlen(check_file[i]) - 1);
				free(check_file[i]);
				check_file[i] = ft_strdup(" ");
			}
		}
		i++;
	}
}

//void	check_count_players_and_exits(char *open_file, t_game *map)
//{
//	int	i;
//
//	i = 0;
//	while (open_file[i])
//	{
//		if (open_file[i] == 'E')
//			map->map_exit++;
//		else if (open_file[i] == 'C')
//			map->items++;
//		else if (open_file[i] == 'P')
//			map->players++;
//		i++;
//	}
//	if (map->map_exit != 1 || map->items < 1 || map->players != 1)
//	{
//		print_error(1);
//	}
//}

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
	read_arr(check_file);
	info->map = cut_map(check_file);

//	read_arr(info->map);

//	check_count_players_and_exits(open_file, map);
//	map->map = ft_split(open_file, '\n');
//	check_map(map);
//	check_no_exit(map);


//	read_arr(check_file);
//	free(open_file);
//	free_arr(check_file);


//	printf("info->NO = %s\n", info->north);
//	printf("info->SO = %s\n", info->south);
//	printf("info->WE = %s\n", info->west);
//	printf("info->EA = %s\n", info->east);
//	printf("info->F = %s\n", info->floor);
//	printf("info->C = %s\n", info->ceilling);
}
