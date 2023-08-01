/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:42:17 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/01 11:58:08 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	deleted_sprites(info);
	mlx_destroy_window(info->mlx, info->mlx_win);
	exit(0);
}

int	my_keypress_hook(int keycode, t_game *info)
{
	if (keycode == W)
		move_forward(info);
	else if (keycode == A)
		move_left(info);
	else if (keycode == S)
		move_backward(info);
	else if (keycode == D)
		move_right(info);
	else if (keycode == RIGHT)
		rotation_right(info);
	else if (keycode == LEFT)
		rotation_left(info);
	else if (keycode == ESC)
		exit_game(info);
	return (keycode);
}
