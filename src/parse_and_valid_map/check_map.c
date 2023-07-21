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

#include "../../include/cub3d.h"

void	check_first_string_of_map(t_game *info)
{
	int		i;
	char	*str;

	i = 0;
	str = info->map[0];
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] != '1' && str[i] != ' ')
			print_error(1);
		i++;
	}
}

void	check_last_string_of_map(t_game *info)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = len_pointer_arr(info->map);
	str = info->map[len - 1];
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] != '1')
			print_error(1);
		i++;
	}
}

int	check_other_string_of_map(char *string)
{
	size_t 	len;
	int i;

	i = 0;
	len = ft_strlen(string);
	while(string[i] && string[i] == ' ')
		i++;
	if (string[0] != '1' && string[len - 1] != '1' && string[i] != ' ')
		return (1);
	return (0);
}


void	check_every_string_of_map(t_game *info)
{
	int	i;
	int	len;

	i = 1;
	check_first_string_of_map(info);
	check_last_string_of_map(info);
	len = len_pointer_arr(info->map);
	while (i < len - 1)
	{
		if (check_other_string_of_map(info->map[i]))
			print_error(1);
		i++;
	}
}
