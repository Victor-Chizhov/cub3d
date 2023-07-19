/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:13:18 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/15 16:16:49 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_first_string_map(t_game *map)
{
	int		i;
	char	*str;

	i = 0;
	str = map->map[0];
	while (str[i])
	{
		if (str[i] != '1')
		{
			print_error(1);
		}
		i++;
	}
}

void	check_last_string_map(t_game *map)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = len_pointer_arr(map->map);
	str = map->map[len - 1];
	while (str[i])
	{
		if (str[i] != '1')
		{
			print_error(1);
		}
		i++;
	}
}

int	check_other_string_map(char *string)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(string);
	if (string[0] != '1' || string[len - 1] != '1')
		return (1);
	return (0);
}

void	check_wall_map(t_game *map)
{
	int	i;
	int	len;

	i = 1;
	check_first_string_map(map);
	check_last_string_map(map);
	len = len_pointer_arr(map->map);
	while (i < len - 1)
	{
		if (check_other_string_map(map->map[i]))
		{
			print_error(1);
		}
		i++;
	}
}

void	check_map(t_game *info)
{
	int	i;
	int	len;

	i = 0;
	len = len_pointer_arr(map->map);

	check_wall_map(map);
//	map->height_map = len_pointer_arr(map->map);
//	map->width_map = ft_strlen(map->map[0]);
}
