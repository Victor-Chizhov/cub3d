#include "../../include/cub3d.h"

void ray_casting1(t_game *info, int x)
{
    info->camera_x = 2 * x / (double)info->screen_width - 1;
    info->ray_dir_x = info->dir_x + info->plane_x * info->camera_x;
    info->ray_dir_y = info->dir_y + info->plane_y * info->camera_x;
    info->map_x = (int)info->position_player_x;
    info->map_y = (int)info->position_player_y;
    info->delta_dist_x = fabs(1 / info->ray_dir_x);
    info->delta_dist_y = fabs(1 / info->ray_dir_y);
    info->hit = 0;
}

void ray_casting2(t_game *info)
{
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
}

void create_texture(t_game *info)
{
    if (info->side == 0)
    {
        if(info->map_x > info->position_player_x)
            info->num_sprite = 1;
        else
            info->num_sprite = 3;
    }
    else
    {
        if(info->map_y > info->position_player_y)
            info->num_sprite = 2;
        else
            info->num_sprite = 0;
    }
}

void ray_casting3(t_game *info)
{
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
//            create_texture(info);
        }
    }
}

void ray_casting4(t_game *info)
{
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
}


void ray_casting(t_game *info)
{
    int x;

    x = -1;
    while(++x < info->screen_width)
    {
        ray_casting1(info, x);
        ray_casting2(info);
        ray_casting3(info);
        ray_casting4(info);
        while(info->draw_start < info->draw_end)
        {
            my_mlx_pixel_put(info, x, info->draw_start, 0xB6B6B4);
//            draw_wall_with_texture(info, x);
            info->draw_start++;
        }
    }
}
