#include "../../include/cub3d.h"

int	exit_game(t_game *info)
{
//	deleted_sprites(info);
	mlx_destroy_window(info->mlx, info->mlx_win);
	system("leaks cub3D");
	exit(0);
}

int	my_keypress_hook(int keycode, t_game *info)
{
	if (keycode == 53)
		exit_game(info);
	return (keycode);
}