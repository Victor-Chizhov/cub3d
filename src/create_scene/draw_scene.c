/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:03:42 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/31 19:20:26 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_floor_and_ceiling(t_game *info)
{
	unsigned int	*dst;
	unsigned int	i;

	dst = (unsigned int *)info->img.addr;
	i = WINDOW_W * WINDOW_H / 2 + 1;
	while (--i > 0)
		*dst++ = info->ceiling_color;
	i = WINDOW_W * WINDOW_H / 2 + 1;
	while (--i > 0)
		*dst++ = info->floor_color;
}

void	find_side_wall(t_game *info)
{
	if (info->side == 0)
		info->wall_x = info->position_player_y + \
				info->perp_wall_dist * info->ray_dir_y;
	else
		info->wall_x = info->position_player_x + \
				info->perp_wall_dist * info->ray_dir_x;
	info->wall_x -= floor(info->wall_x);
	info->texture_x = (int)(info->wall_x * (double)TEX_WIDTH);
	if (info->side == 0 && info->ray_dir_x > 0)
		info->texture_x = TEX_WIDTH - info->texture_x - 1;
	if (info->side == 1 && info->ray_dir_y < 0)
		info->texture_x = TEX_WIDTH - info->texture_x - 1;
}

void	draw_wall_with_texture(t_game *info, int x, \
		int num_texture, double step)
{
	double	tex_pos;
	int		i;
	char	*dst;

	num_texture = find_num_texture(info);
	i = info->draw_start;
	find_side_wall(info);
	step = 1.0 * TEX_HEIGHT / info->line_height;
	tex_pos = (info->draw_start - WINDOW_H / 2 + info->line_height / 2) * step;
	while (i < info->draw_end)
	{
		info->texture_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		dst = info->img_sprites[num_texture].addr + ((int)info->texture_y * \
				info->img_sprites[num_texture].line_length + \
				(int)info->texture_x * \
				(info->img_sprites[num_texture].bits_per_pixel / 8));
		my_mlx_pixel_put(info, x, i, *(int *)dst);
		i++;
	}
}
