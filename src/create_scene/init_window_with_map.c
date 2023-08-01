/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_with_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:22:04 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/31 19:26:29 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_game *info, int x, int y, int color)
{
	char	*dst;

	dst = info->img.addr + (y * info->img.line_length + \
			x * (info->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_sprites(t_game *info)
{
	if (mlx_xpm_file_to_image(info->mlx, info->north, &info->width_sprite, \
				&info->height_sprite) == NULL)
		print_error("Error with sprite", 1);
	if (mlx_xpm_file_to_image(info->mlx, info->south, &info->width_sprite, \
				&info->height_sprite) == NULL)
		print_error("Error with sprite", 1);
	if (mlx_xpm_file_to_image(info->mlx, info->west, &info->width_sprite, \
				&info->height_sprite) == NULL)
		print_error("Error with sprite", 1);
	if (mlx_xpm_file_to_image(info->mlx, info->east, &info->width_sprite, \
				&info->height_sprite) == NULL)
		print_error("Error with sprite", 1);
	info->sprite_north = mlx_xpm_file_to_image(info->mlx, info->west, \
			&info->width_sprite, &info->height_sprite);
	info->sprite_south = mlx_xpm_file_to_image(info->mlx, info->east, \
			&info->width_sprite, &info->height_sprite);
	info->sprite_west = mlx_xpm_file_to_image(info->mlx, info->south, \
			&info->width_sprite, &info->height_sprite);
	info->sprite_east = mlx_xpm_file_to_image(info->mlx, info->north, \
			&info->width_sprite, &info->height_sprite);
}

void	get_sprites(t_game *info)
{
	info->img_sprites[0].addr = mlx_get_data_addr(info->sprite_north, \
			&info->img_sprites[0].bits_per_pixel, \
			&info->img_sprites[0].line_length, &info->img_sprites[0].endian);
	info->img_sprites[1].addr = mlx_get_data_addr(info->sprite_south, \
			&info->img_sprites[1].bits_per_pixel, \
			&info->img_sprites[1].line_length, &info->img_sprites[1].endian);
	info->img_sprites[2].addr = mlx_get_data_addr(info->sprite_west, \
			&info->img_sprites[2].bits_per_pixel, \
			&info->img_sprites[2].line_length, &info->img_sprites[2].endian);
	info->img_sprites[3].addr = mlx_get_data_addr(info->sprite_east, \
			&info->img_sprites[3].bits_per_pixel, \
			&info->img_sprites[3].line_length, &info->img_sprites[3].endian);
}

int	render_scene(void *data)
{
	t_game	*info;

	info = (t_game *)data;
	info->img.img = mlx_new_image(info->mlx, WINDOW_W, WINDOW_H);
	info->img.addr = mlx_get_data_addr(info->img.img, \
			&info->img.bits_per_pixel, &info->img.line_length, \
			&info->img.endian);
	draw_floor_and_ceiling(info);
	ray_casting(info);
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img.img, 0, 0);
	mlx_destroy_image(info->mlx, info->img.img);
	return (0);
}

void	init_window_with_map(t_game *info)
{
	info->move_speed = 0.05;
	info->turn_speed = 0.03;
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, WINDOW_W, WINDOW_H, "cub3D");
	init_sprites(info);
	get_sprites(info);
	mlx_loop_hook(info->mlx, render_scene, info);
	mlx_hook(info->mlx_win, 17, 1L << 17, exit_game, info);
	mlx_hook(info->mlx_win, 2, 1L << 0, my_keypress_hook, info);
	mlx_loop(info->mlx);
}
