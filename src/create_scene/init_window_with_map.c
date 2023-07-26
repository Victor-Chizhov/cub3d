/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_with_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:22:04 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/15 16:29:00 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
{
    char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void draw_wall(t_game *info)
{
    info->dir_x = 1;
    info->dir_y = 0;
    info->plane_x = 0;
    info->plane_y = 0.66;

    int x;

    x = -1;

    while(++x < info->screen_width)
    {
        info->camera_x = 2 * x / (double)info->screen_width - 1;
        info->ray_dir_x = info->dir_x + info->plane_x * info->camera_x;
        info->ray_dir_y = info->dir_y + info->plane_y * info->camera_x;

        info->map_x = (int)info->position_player_x;
        info->map_y = (int)info->position_player_y;


        info->delta_dist_x = fabs(1 / info->ray_dir_x);
        info->delta_dist_y = fabs(1 / info->ray_dir_y);
        info->hit = 0;

        if (info->ray_dir_x < 0)
        {
            info->step_x = -1;
            info->side_dist_x = (info->position_player_x - info->map_x) * info->delta_dist_x;
        }
        else
        {
            info->step_x = 1;
            info->side_dist_x = (info->map_x + 1.0 - info->position_player_x) * info->delta_dist_x;
        }
        if (info->ray_dir_y < 0)
        {
            info->step_y = -1;
            info->side_dist_y = (info->position_player_y - info->map_y) * info->delta_dist_y;
        }
        else
        {
            info->step_y = 1;
            info->side_dist_y = (info->map_y + 1.0 - info->position_player_y) * info->delta_dist_y;
        }

        while(info->hit == 0)
        {
            if (info->side_dist_x < info->side_dist_y)
            {
                info->side_dist_x += info->delta_dist_x;
                info->map_x += (int)info->step_x;
                info->side = 0;
            }
            else
            {
                info->side_dist_y += info->delta_dist_y;
                info->map_y += (int)info->step_y;
                info->side = 1;
            }
            if (info->map[info->map_y][info->map_x] == '1') {
				info->hit = 1;
			}
        }
        if(info->side == 0)
        {
            info->perp_wall_dist = (info->map_x - info->position_player_x + (1 - info->step_x) / 2) / info->ray_dir_x;
        }
        else
        {
            info->perp_wall_dist = (info->map_y - info->position_player_y + (1 - info->step_y) / 2) / info->ray_dir_y;
        }
        info->line_height = (int)(info->screen_height / info->perp_wall_dist);
        info->draw_start = (-1) * info->line_height / 2 + (int)info->screen_height / 2;

        if (info->draw_start < 0)
            info->draw_start = 0;
        info->draw_end = info->line_height / 2 + (int)info->screen_height / 2;
        if (info->draw_end >= (int)info->screen_height)
            info->draw_end = (int)info->screen_height - 1;


        while(info->draw_start < info->draw_end)
        {
            my_mlx_pixel_put(info, x, info->draw_start, 0xB6B6B4);
            info->draw_start++;
        }
    }
}

void draw_floor_and_ceiling(t_game *info)
{
    int x;
    int y;

    y = 0;
    while (y < info->screen_height / 2)
    {
        x = 0;
        while (x < info->screen_width)
        {
            my_mlx_pixel_put(info, x, y, info->floor_color);
            x++;
        }
        y++;
    }
    y = (int)info->screen_height / 2;
    while (y < info->screen_height)
    {
        x = 0;
        while (x < info->screen_width)
        {
            my_mlx_pixel_put(info, x, y, info->ceiling_color);
            x++;
        }
        y++;
    }
}

int 	render_scene(void *info_raw)
{
    t_game *info;

    info = (t_game *)info_raw;
    info->img = mlx_new_image(info->mlx, (int)info->screen_width, (int)info->screen_height);
    info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->line_length, &info->endian);
    draw_floor_and_ceiling(info);
    draw_wall(info);

    mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0, 0);
    return 0;

}

void	init_window_with_map(t_game *info)
{
    info->screen_width = 640;
    info->screen_height = 480;


	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, (int)info->screen_width, (int)info->screen_height, "cub3D");


	mlx_hook(info->mlx_win, 17, 1L << 17, exit_game, info);
    mlx_loop_hook(info->mlx, render_scene, info);
	mlx_hook(info->mlx_win, 2, 1L << 0, my_keypress_hook, info);

	mlx_loop(info->mlx);
}
