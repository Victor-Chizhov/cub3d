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

//int get_color_from_texture(void *texture_data, t_game *info)
//{
//    int texture_x;
//    int texture_y;
//    int color;
//
//    unsigned char *texture = (unsigned char*)texture_data;
//    texture_x = (int)(info->texture_x * (double)info->width_sprite);
//    texture_y = (int)(info->texture_y * (double)info->height_sprite);
//    if(texture_x < 0)
//        texture_x = 0;
//    if(texture_y < 0)
//        texture_y = 0;
//    if(texture_x >= info->width_sprite)
//        texture_x = info->width_sprite - 1;
//    if(texture_y >= info->height_sprite)
//        texture_y = info->height_sprite - 1;
//
//    int pixel = (int)(info->texture_y * info->width_sprite + info->texture_x) * 4;
//
//
//    color = (pixel << 24) + (pixel << 16) + (pixel << 8) + pixel;
//    return (color);
//}

void draw_wall_with_texture(t_game *info, int x)
{
    int y;

    if(info->side == 0)
        info->texture[0] = info->sprite_north;
    else if (info->side == 1)
        info->texture[1] = info->sprite_south;
    else if (info->side == 2)
        info->texture[2] = info->sprite_west;
    else if (info->side == 3)
        info->texture[3] = info->sprite_east;


    if(info->side == 0)
        info->wall_x = info->position_player_y + info->perp_wall_dist * info->ray_dir_y;
    else
        info->wall_x = info->position_player_x + info->perp_wall_dist * info->ray_dir_x;
    info->wall_x -= floor(info->wall_x);
    info->texture_x = (int)(info->wall_x * (double)info->width_sprite);

    if(info->side == 0 && info->ray_dir_x > 0)
        info->texture_x = info->width_sprite - info->texture_x - 1;
    if(info->side == 1 && info->ray_dir_y < 0)
        info->texture_x = info->width_sprite - info->texture_x - 1;

    info->step = 1.0 * info->height_sprite / info->line_height;
    info->tex_pos = (info->draw_start - info->screen_height / 2 + (double)info->line_height / 2) * info->step;
    y = info->draw_start;
    while (y < info->draw_end)
    {
        info->texture_y = (int)info->tex_pos & (info->height_sprite - 1);
        info->tex_pos += info->step;
        info->color = (info->texture[info->num_sprite][info->height_sprite * (int)info->texture_y + (int)info->texture_x]);
        if(info->side == 1)
            info->color = (info->color >> 1) & 8355711;
        my_mlx_pixel_put(info, x, y, info->color);
        y++;
    }
}