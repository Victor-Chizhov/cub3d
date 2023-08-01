/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_from_file_attributes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:32:29 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/31 17:51:38 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*check_symbols_f_and_c(char *check_file)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = remove_spaces_from_str(check_file);
	tmp++;
	while (tmp[i])
	{
		if (tmp[i] < ',' || (tmp[i] > ',' && tmp[i] < '0') || tmp[i] > '9')
			return (NULL);
		i++;
	}
	return (tmp);
}

char	*copy_from_file(char *check_file, t_game *info)
{
	char	**arr;
	char	*new;

	new = NULL;
	arr = ft_split(check_file, ' ');
	if (len_pointer_arr(arr) != 2)
	{
		free_arr(arr);
		print_error("Sprites have no correctly parameters", 1);
	}
	new = ft_strdup(arr[1]);
	free_arr(arr);
	ft_strlcpy(check_file, " ", 1);
	info->count_arguments_in_file++;
	return (new);
}

char	*copy_from_file_for_f_and_c(char *check_file, t_game *info)
{
	char	*new;

	new = NULL;
	if (!check_symbols_f_and_c(check_file))
		print_error("Floor or ceiling have no correctly color", 1);
	new = ft_substr(check_file, 1, ft_strlen(check_file) - 1);
	ft_strlcpy(check_file, " ", 1);
	info->count_arguments_in_file++;
	return (new);
}

void	check_open_file2(char **file, t_game *info, int i, int j)
{
	if (file[i][j] == 'N' && file[i][j + 1] == 'O' && file[i][j + 2] == ' ')
		info->north = copy_from_file(file[i], info);
	else if (file[i][j] == 'S' && file[i][j + 1] == 'O' \
			&& file[i][j + 2] == ' ')
		info->south = copy_from_file(file[i], info);
	else if (file[i][j] == 'W' && file[i][j + 1] == 'E' \
			&& file[i][j + 2] == ' ')
		info->west = copy_from_file(file[i], info);
	else if (file[i][j] == 'E' && file[i][j + 1] == 'A' \
			&& file[i][j + 2] == ' ')
		info->east = copy_from_file(file[i], info);
	else if (file[i][j] == 'F' && file[i][j + 1] == ' ')
		info->floor = copy_from_file_for_f_and_c(file[i], info);
	else if (file[i][j] == 'C' && file[i][j + 1] == ' ')
		info->ceiling = copy_from_file_for_f_and_c(file[i], info);
}

void	check_open_file(char **check_file, t_game *info)
{
	int	i;
	int	j;

	i = 0;
	while (check_file[i])
	{
		j = 0;
		while (check_file[i][j] && check_file[i][j] == ' ')
			j++;
		check_open_file2(check_file, info, i, j);
		i++;
	}
	if (info->count_arguments_in_file != 6)
		print_error("Count arguments in file: no 6", 1);
}
