/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:12:13 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/01 13:27:54 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ray_casting1(t_game *info, int x)
{
	info->camera_x = 2 * x / (double)WINDOW_W - 1;
	info->ray_dir_x = info->dir_x + info->plane_x * info->camera_x;
	info->ray_dir_y = info->dir_y + info->plane_y * info->camera_x;
	info->map_x = (int)info->position_player_x;
	info->map_y = (int)info->position_player_y;
	if (info->ray_dir_x == 0)
		info->delta_dist_x = 1e30;
	else
		info->delta_dist_x = ft_abs(1 / info->ray_dir_x);
	if (info->ray_dir_y == 0)
		info->delta_dist_y = 1e30;
	else
		info->delta_dist_y = ft_abs(1 / info->ray_dir_y);
	info->hit = 0;
}

void	ray_casting2(t_game *info)
{
	if (info->ray_dir_x < 0)
	{
		info->step_x = -1;
		info->side_dist_x = (info->position_player_x - info->map_x) * \
							info->delta_dist_x;
	}
	else
	{
		info->step_x = 1;
		info->side_dist_x = (info->map_x + 1.0 - info->position_player_x) * \
							info->delta_dist_x;
	}
	if (info->ray_dir_y < 0)
	{
		info->step_y = -1;
		info->side_dist_y = (info->position_player_y - info->map_y) * \
							info->delta_dist_y;
	}
	else
	{
		info->step_y = 1;
		info->side_dist_y = (info->map_y + 1.0 - info->position_player_y) * \
							info->delta_dist_y;
	}
}

void	ray_casting3(t_game *info)
{
	while (info->hit == 0)
	{
		if (info->side_dist_x < info->side_dist_y)
		{
			info->side_dist_x += info->delta_dist_x;
			info->map_x += info->step_x;
			info->side = 0;
		}
		else
		{
			info->side_dist_y += info->delta_dist_y;
			info->map_y += info->step_y;
			info->side = 1;
		}
		if (info->map[info->map_y][info->map_x] == '1')
			info->hit = 1;
	}
}

void	ray_casting4(t_game *info)
{
	if (info->side == 0)
		info->perp_wall_dist = info->side_dist_x - info->delta_dist_x;
	else
		info->perp_wall_dist = info->side_dist_y - info->delta_dist_y;
	info->line_height = (int)(WINDOW_H / info->perp_wall_dist);
	info->draw_start = -info->line_height / 2 + WINDOW_H / 2;
	if (info->draw_start < 0)
		info->draw_start = 0;
	info->draw_end = info->line_height / 2 + WINDOW_H / 2;
	if (info->draw_end >= WINDOW_H)
		info->draw_end = WINDOW_H - 1;
}

void	ray_casting(t_game *info)
{
	int	i;

	i = 0;
	while (i < WINDOW_W)
	{
		ray_casting1(info, i);
		ray_casting2(info);
		ray_casting3(info);
		ray_casting4(info);
		draw_wall_with_texture(info, i, 0, 0);
		i++;
	}
}
