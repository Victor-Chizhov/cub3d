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

int get_color_from_texture(t_img *texture, double texture_x, double texture_y)
{
    int tex_x = (int)(texture_x * texture->width);
    int tex_y = (int)(texture_y * texture->height);

    if (tex_x < 0)
        tex_x = 0;
    if (tex_y < 0)
        tex_y = 0;
    if (tex_x >= texture->width)
        tex_x = texture->width - 1;
    if (tex_y >= texture->height)
        tex_y = texture->height - 1;

    int pixel_index = tex_y * texture->line_length + tex_x * (texture->bits_per_pixel / 8);
    unsigned char *pixels = (unsigned char *)texture->addr;
    unsigned char red = pixels[pixel_index];
    unsigned char green = pixels[pixel_index + 1];
    unsigned char blue = pixels[pixel_index + 2];
    unsigned char alpha = pixels[pixel_index + 3];

    int color = (alpha << 24) | (red << 16) | (green << 8) | blue;
    return color;
}

void draw_wall_with_texture(t_game *info, int x)
{
    int y;

//    int tex_num = info->map[info->map_x][info->map_y] - 1;
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
        info->color = get_color_from_texture(&info->texture[info->num_sprite], info->texture_x / (double)info->width_sprite, info->texture_y / (double)info->height_sprite);
        my_mlx_pixel_put(info, x, y, info->color);
        y++;
    }
}