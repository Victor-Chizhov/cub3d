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

/*
 * 1. инициализация
		1. сделать проверку на текстуры
 		2. сделать проверку на цвет
 		3. создать окно
 	2. отрисовка
 		1. создать mlx hook loop
 		2. инициализировать mlx_new_image
 		3. инициализировать mlx_get_data_addr
 		4. рисовать пол
 		5. рисовать стены
 		6. райкастинг
 		7. хуки
 		8. инциализировать mlx_put_image
 		9. задестроить




*/

//void	init_sprites(t_game *map)
//{
//	map->sprite_player = mlx_xpm_file_to_image(map->mlx, \
//	"./sprites/player.xpm", &map->width_sprite, &map->height_sprite);
//	map->sprite_wall = mlx_xpm_file_to_image(map->mlx, \
//	"./sprites/wall.xpm", &map->width_sprite, &map->height_sprite);
//	map->sprite_place = mlx_xpm_file_to_image(map->mlx, \
//	"./sprites/place.xpm", &map->width_sprite, &map->height_sprite);
//	map->sprite_exit = mlx_xpm_file_to_image(map->mlx, \
//	"./sprites/exit.xpm", &map->width_sprite, &map->height_sprite);
//	map->sprite_items = mlx_xpm_file_to_image(map->mlx, \
//	"./sprites/items.xpm", &map->width_sprite, &map->height_sprite);
//}
//
//void	print_sprites(t_game *map, char c, int y, int x)
//{
//	if (c == '0')
//		mlx_put_image_to_window(map->mlx, map->mlx_win, \
//		map->sprite_place, 64 * x, 64 * y);
//	else if (c == '1')
//		mlx_put_image_to_window(map->mlx, map->mlx_win, \
//		map->sprite_wall, 64 * x, 64 * y);
//	else if (c == 'C')
//		mlx_put_image_to_window(map->mlx, map->mlx_win, \
//		map->sprite_items, 64 * x, 64 * y);
//	else if (c == 'E')
//		mlx_put_image_to_window(map->mlx, map->mlx_win, \
//		map->sprite_exit, 64 * x, 64 * y);
//	else if (c == 'P')
//		mlx_put_image_to_window(map->mlx, map->mlx_win, \
//		map->sprite_player, 64 * x, 64 * y);
//}
//

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
            my_mlx_pixel_put(info, x, y, 0x6585A1);
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
            my_mlx_pixel_put(info, x, y, 0x314F4F);
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
    mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0, 0);
    return 0;

}

void	init_window_with_map(t_game *info)
{
    info->screen_width = 640;
    info->screen_height = 480;

	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, (int)info->screen_width, (int)info->screen_height, "cub3D");

    mlx_loop_hook(info->mlx, render_scene, info);

	mlx_loop(info->mlx);
}
