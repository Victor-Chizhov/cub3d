/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:01:33 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/01 12:05:02 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotation_right(t_game *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(info->turn_speed) - \
			info->dir_y * sin(info->turn_speed);
	info->dir_y = old_dir_x * sin(info->turn_speed) + \
			info->dir_y * cos(info->turn_speed);
	old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(info->turn_speed) - \
			info->plane_y * sin(info->turn_speed);
	info->plane_y = old_plane_x * sin(info->turn_speed) + \
			info->plane_y * cos(info->turn_speed);
}

void	rotation_left(t_game *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(-info->turn_speed) - \
			info->dir_y * sin(-info->turn_speed);
	info->dir_y = old_dir_x * sin(-info->turn_speed) + \
			info->dir_y * cos(-info->turn_speed);
	old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(-info->turn_speed) - \
			info->plane_y * sin(-info->turn_speed);
	info->plane_y = old_plane_x * sin(-info->turn_speed) + \
			info->plane_y * cos(-info->turn_speed);
}
