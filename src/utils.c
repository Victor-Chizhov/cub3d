/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:35:12 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/19 19:59:07 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_error(int a)
{
	a = 0;
	write(2, "Error\n", 6);
	exit(1);
}

char	**create_dublicate(char **arr)
{
	char	**dublicate;
	int		i;
	int		j;

	i = 0;
	dublicate = malloc(len_pointer_arr(arr) * sizeof(char *) + 8);
	while (i < len_pointer_arr(arr))
	{
		j = 0;
		dublicate[i] = malloc(ft_strlen(arr[i]) * sizeof(char) + 1);
		while (arr[i][j])
		{
			dublicate[i][j] = arr[i][j];
			j++;
		}
		dublicate[i][j] = '\0';
		i++;
	}
	dublicate[i] = NULL;
	return (dublicate);
}

void	read_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_putstr_fd(arr[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

int	len_pointer_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}


char *remove_spaces_from_str(char *string)
{
	int non_space_count = 0;

	int i = 0;
	while(string[i] != '\0')
	{
		if (string[i] != ' ') {
			string[non_space_count] = string[i];
			non_space_count++;
		}
		i++;
	}
	string[non_space_count] = '\0';
	return string;
}

