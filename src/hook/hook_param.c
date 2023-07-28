#include "../../include/cub3d.h"

int	exit_game(t_game *info)
{
//	deleted_sprites(info);
	mlx_destroy_window(info->mlx, info->mlx_win);
//	system("leaks cub3D");
	exit(0);
}

void	check_rotation(t_game *info)
{
	double plane_angle;

	if (info->player_angle >= 2 * M_PI)
		info->player_angle -= 2 * M_PI;
	if (info->player_angle < 0)
		info->player_angle += 2 * M_PI;
	info->dir_x = cos(info->player_angle);
	info->dir_y = sin(info->player_angle);

	plane_angle = info->player_angle + M_PI / 2;
	info->plane_x = cos(plane_angle);
	info->plane_y = sin(plane_angle);
}

int	my_keypress_hook(int keycode, t_game *info)
{
	if (keycode == 13)
	{
//		info->position_player_x += info->dir_x * info->move_speed;
//		info->position_player_y += info->dir_y * info->move_speed;
		info->position_player_x += info->move_speed;
	}
	else if (keycode == 0)
	{
//		info->position_player_x -= info->dir_y * info->move_speed;
//		info->position_player_y += info->dir_x * info->move_speed;
		info->position_player_y -= info->move_speed;
	}
	else if (keycode == 1)
	{
//		info->position_player_x -= info->dir_x * info->move_speed;
//		info->position_player_y -= info->dir_y * info->move_speed;
		info->position_player_x -= info->move_speed;
	}
	else if (keycode == 2)
	{
//		info->position_player_x += info->dir_y * info->move_speed;
//		info->position_player_y -= info->dir_x * info->move_speed;
		info->position_player_y += info->move_speed;
	}
	else if (keycode == 123)
	{
		info->player_angle -= info->turn_speed;
		check_rotation(info);
	}
	else if (keycode == 124)
	{
		info->player_angle += info->turn_speed;
		check_rotation(info);
	}
	else if (keycode == 53) {
		exit_game(info);
	}
	return (keycode);
}