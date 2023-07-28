#include "../../include/cub3d.h"

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

//int get_color_from_texture(double text_x, double text_y, t_game *info)
//{
//    (void)text_x;
//    (void)text_y;
//    (void)info;
//    int color = 0x000000;
//    int tex_x, tex_y, pixel_index;
//
//    tex_x = (int)(text_x * info->width_sprite);
//    tex_y = (int)(text_y * info->height_sprite);
//
//    unsigned char *texture_bytes = (unsigned char*)wall_texture;
//    pixel_index = (tex_y * info->width_sprite + tex_x) * 4;
//
//
//    unsigned char red = texture_bytes[pixel_index + 1];
//    unsigned char green = texture_bytes[pixel_index + 2];
//    unsigned char blue = texture_bytes[pixel_index + 3];
//
//    int color = (red << 16) | (green << 8) | blue;
//    return color;
//}

//void draw_wall_with_texture(t_game *info, int x)
//{
//    if (info->side == 0)
//        info->texture[0] = info->sprite_east;
//    else if (info->side == 1)
//        info->texture[1] = info->sprite_west;
//    else if (info->side == 2)
//        info->texture[2] = info->sprite_south;
//    else if (info->side == 3)
//        info->texture[3] = info->sprite_north;
//
//	if (info->side == 0 || info->side == 1)
//        info->wall_x = info->position_player_y + info->perp_wall_dist * info->ray_dir_y;
//    else
//        info->wall_x = info->position_player_x + info->perp_wall_dist * info->ray_dir_x;
//    info->wall_x -= floor(info->wall_x);
//
//    if (info->side == 0 || info->side == 1)
//        info->texture_x = (int)(info->wall_x * info->width_sprite);
//    else
//        info->texture_x = (int)(info->wall_x * info->width_sprite) % info->width_sprite;
//
//    if ((info->side == 0 && info->ray_dir_x > 0) || (info->side == 1 && info->ray_dir_y < 0))
//        info->texture_x = info->width_sprite - info->texture_x - 1;
//
//    info->step = 1.0 * info->height_sprite / info->line_height;
//    info->tex_pos = (info->draw_start - info->screen_height / 2 + (double)info->line_height / 2) * info->step;
//    int y = info->draw_start;
//
//    while (y < info->draw_end)
//    {
//        info->texture_y = (int)info->tex_pos & (info->height_sprite - 1);
//        info->tex_pos += info->step;
//        info->color = get_color_from_texture(info->texture_x / info->width_sprite, info->texture_y / info->height_sprite, info);
//        my_mlx_pixel_put(info, x, y, info->color);
//        y++;
//    }
//
//}