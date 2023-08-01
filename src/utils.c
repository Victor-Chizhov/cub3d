/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:35:12 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/31 17:22:19 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_error(char *err, int a)
{
	printf("%s\n", err);
	exit(a);
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

char	*remove_spaces_from_str(char *string)
{
	int	non_space_count;
	int	i;

	i = 0;
	non_space_count = 0;
	while (string[i] != '\0')
	{
		if (string[i] != ' ')
		{
			string[non_space_count] = string[i];
			non_space_count++;
		}
		i++;
	}
	string[non_space_count] = '\0';
	return (string);
}
