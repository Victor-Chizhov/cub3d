/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_raycasting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:09:03 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/01 12:10:39 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	find_num_texture(t_game *info)
{
	int	n;

	n = 0;
	if (info->side == 1 && info->ray_dir_y < 0)
		n = 3;
	else if (info->side == 1 && info->ray_dir_y > 0)
		n = 2;
	else if (info->side == 0 && info->ray_dir_x > 0)
		n = 1;
	else if (info->side == 0 && info->ray_dir_x < 0)
		n = 0;
	return (n);
}
