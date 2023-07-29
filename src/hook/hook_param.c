#include "../../include/cub3d.h"

void	deleted_sprites(t_game *info)
{
    mlx_destroy_image(info->mlx, info->sprite_north);
    mlx_destroy_image(info->mlx, info->sprite_south);
    mlx_destroy_image(info->mlx, info->sprite_east);
    mlx_destroy_image(info->mlx, info->sprite_west);
}

int	exit_game(t_game *info)
{
//	deleted_sprites(info);
	mlx_destroy_window(info->mlx, info->mlx_win);
//	system("leaks cub3D");
	exit(0);
}


int	my_keypress_hook(int keycode, t_game *info)
{

	if (keycode == 13)
	{
        double new_x = info->position_player_x + info->dir_x * info->move_speed;
        double new_y = info->position_player_y + info->dir_y * info->move_speed;
        if (info->map[(int)new_y][(int)new_x] != '1')
        {
            info->position_player_x = new_x;
            info->position_player_y = new_y;
        }
	}
	else if (keycode == 0)
	{
        double new_x = info->position_player_x + info->dir_y * info->move_speed;
        double new_y = info->position_player_y - info->dir_x * info->move_speed;
        if (info->map[(int)new_y][(int)new_x] != '1')
        {
            info->position_player_x = new_x;
            info->position_player_y = new_y;
        }
	}
	else if (keycode == 1)
	{
        double new_x = info->position_player_x - info->dir_x * info->move_speed;
        double new_y = info->position_player_y - info->dir_y * info->move_speed;
        if (info->map[(int)new_y][(int)new_x] != '1')
        {
            info->position_player_x = new_x;
            info->position_player_y = new_y;
        }
	}
	else if (keycode == 2)
	{
        double new_x = info->position_player_x - info->dir_y * info->move_speed;
        double new_y = info->position_player_y + info->dir_x * info->move_speed;
        if (info->map[(int)new_y][(int)new_x] != '1')
        {
            info->position_player_x = new_x;
            info->position_player_y = new_y;
        }
	}
	else if (keycode == 124)
	{
        double old_dir_x = info->dir_x;
        info->dir_x = info->dir_x * cos(info->turn_speed) - info->dir_y * sin(info->turn_speed);
        info->dir_y = old_dir_x * sin(info->turn_speed) + info->dir_y * cos(info->turn_speed);
        double old_plane_x = info->plane_x;
        info->plane_x = info->plane_x * cos(info->turn_speed) - info->plane_y * sin(info->turn_speed);
        info->plane_y = old_plane_x * sin(info->turn_speed) + info->plane_y * cos(info->turn_speed);

	}
	else if (keycode == 123)
	{
        double old_dir_x = info->dir_x;
        info->dir_x = info->dir_x * cos(-info->turn_speed) - info->dir_y * sin(-info->turn_speed);
        info->dir_y = old_dir_x * sin(-info->turn_speed) + info->dir_y * cos(-info->turn_speed);
        double old_plane_x = info->plane_x;
        info->plane_x = info->plane_x * cos(-info->turn_speed) - info->plane_y * sin(-info->turn_speed);
        info->plane_y = old_plane_x * sin(-info->turn_speed) + info->plane_y * cos(-info->turn_speed);

	}
	else if (keycode == 53) {
		exit_game(info);
	}
	return (keycode);
}