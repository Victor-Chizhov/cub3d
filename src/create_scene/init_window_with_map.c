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

//void init_sprites(t_game *info)
//{
//    if (mlx_xpm_file_to_image(info->mlx, info->north, &info->width_sprite, &info->height_sprite) == NULL)
//        printf("Error with sprite\n");
//    if (mlx_xpm_file_to_image(info->mlx, info->south, &info->width_sprite, &info->height_sprite) == NULL)
//        printf("Error with sprite\n");
//    if (mlx_xpm_file_to_image(info->mlx, info->west, &info->width_sprite, &info->height_sprite) == NULL)
//        printf("Error with sprite\n");
//    if (mlx_xpm_file_to_image(info->mlx, info->east, &info->width_sprite, &info->height_sprite) == NULL)
//        printf("Error with sprite\n");
//    info->sprite_north = mlx_xpm_file_to_image(info->mlx, info->north, &info->width_sprite, &info->height_sprite);
//    info->sprite_south = mlx_xpm_file_to_image(info->mlx, info->south, &info->width_sprite, &info->height_sprite);
//    info->sprite_west = mlx_xpm_file_to_image(info->mlx, info->west, &info->width_sprite, &info->height_sprite);
//    info->sprite_east = mlx_xpm_file_to_image(info->mlx, info->east, &info->width_sprite, &info->height_sprite);
//}

void init_sprites(t_game *info)
{
//    printf("north %s\n",info->north);
//    printf("south %s\n",info->south);
//    printf("west %s\n",info->west);
//    printf("east %s\n",info->east);
    info->texture[0].img_ptr = mlx_xpm_file_to_image(info->mlx, info->north, &info->texture[0].width, &info->texture[0].height);
    if(info->texture[0].img_ptr == NULL)
        printf("Error with sprite\n");
    info->texture[1].img_ptr = mlx_xpm_file_to_image(info->mlx, info->south, &info->texture[1].width, &info->texture[1].height);
    if(info->texture[1].img_ptr == NULL)
        printf("Error with sprite\n");
    info->texture[2].img_ptr = mlx_xpm_file_to_image(info->mlx, info->west, &info->texture[2].width, &info->texture[2].height);
    if(info->texture[2].img_ptr == NULL)
        printf("Error with sprite\n");
    info->texture[3].img_ptr = mlx_xpm_file_to_image(info->mlx, info->east, &info->texture[3].width, &info->texture[3].height);
    if(info->texture[3].img_ptr == NULL)
        printf("Error with sprite\n");
    info->texture[0].addr = mlx_get_data_addr(info->texture[0].img_ptr, &info->texture[0].bits_per_pixel, &info->texture[0].line_length, &info->texture[0].endian);
    info->texture[1].addr = mlx_get_data_addr(info->texture[1].img_ptr, &info->texture[1].bits_per_pixel, &info->texture[1].line_length, &info->texture[1].endian);
    info->texture[2].addr = mlx_get_data_addr(info->texture[2].img_ptr, &info->texture[2].bits_per_pixel, &info->texture[2].line_length, &info->texture[2].endian);
    info->texture[3].addr = mlx_get_data_addr(info->texture[3].img_ptr, &info->texture[3].bits_per_pixel, &info->texture[3].line_length, &info->texture[3].endian);
}


int 	render_scene(void *info_raw)
{
    t_game *info;

    info = (t_game *)info_raw;

    draw_floor_and_ceiling(info);
    ray_casting(info);
    mlx_put_image_to_window(info->mlx, info->mlx_win, info->img, 0, 0);
    return 0;

}

void	init_window_with_map(t_game *info)
{
    info->screen_width = 640;
    info->screen_height = 480;
    info->width_sprite = 64;
    info->height_sprite = 64;

	info->move_speed = 0.05;
	info->turn_speed = 0.03;
	info->player_angle = 0.0;


	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, (int)info->screen_width, (int)info->screen_height, "cub3D");
    init_sprites(info);
    info->img = mlx_new_image(info->mlx, (int)info->screen_width, (int)info->screen_height);
    info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->line_length, &info->endian);

	mlx_hook(info->mlx_win, 17, 1L << 17, exit_game, info);
    mlx_loop_hook(info->mlx, render_scene, info);
	mlx_hook(info->mlx_win, 2, 1L << 0, my_keypress_hook, info);

	mlx_loop(info->mlx);
}
