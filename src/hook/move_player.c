/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:58:15 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/01 12:01:26 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_game *info)
{
	double	new_x;
	double	new_y;

	new_x = info->position_player_x + info->dir_x * info->move_speed;
	new_y = info->position_player_y + info->dir_y * info->move_speed;
	if (info->map[(int)new_y][(int)new_x] != '1')
	{
		info->position_player_x = new_x;
		info->position_player_y = new_y;
	}
}

void	move_left(t_game *info)
{
	double	new_x;
	double	new_y;

	new_x = info->position_player_x + info->dir_y * info->move_speed;
	new_y = info->position_player_y - info->dir_x * info->move_speed;
	if (info->map[(int)new_y][(int)new_x] != '1')
	{
		info->position_player_x = new_x;
		info->position_player_y = new_y;
	}
}

void	move_backward(t_game *info)
{
	double	new_x;
	double	new_y;

	new_x = info->position_player_x - info->dir_x * info->move_speed;
	new_y = info->position_player_y - info->dir_y * info->move_speed;
	if (info->map[(int)new_y][(int)new_x] != '1')
	{
		info->position_player_x = new_x;
		info->position_player_y = new_y;
	}
}

void	move_right(t_game *info)
{
	double	new_x;
	double	new_y;

	new_x = info->position_player_x - info->dir_y * info->move_speed;
	new_y = info->position_player_y + info->dir_x * info->move_speed;
	if (info->map[(int)new_y][(int)new_x] != '1')
	{
		info->position_player_x = new_x;
		info->position_player_y = new_y;
	}
}
