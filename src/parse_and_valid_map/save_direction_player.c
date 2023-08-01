/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_direction_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:08:48 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/31 18:31:31 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	save_direction_player2(t_game *info)
{
	if (info->map[(int)info->position_player_y][(int)info->position_player_x] \
			== 'W')
	{
		info->dir_x = -1;
		info->dir_y = 0;
		info->plane_x = 0;
		info->plane_y = -0.66;
	}
	if (info->map[(int)info->position_player_y][(int)info->position_player_x] \
			== 'E')
	{
		info->dir_x = 1;
		info->dir_y = 0;
		info->plane_x = 0;
		info->plane_y = 0.66;
	}
}

void	save_direction_player(t_game *info)
{
	if (info->map[(int)info->position_player_y][(int)info->position_player_x] \
			== 'N')
	{
		info->dir_x = 0;
		info->dir_y = -1;
		info->plane_x = 0.66;
		info->plane_y = 0;
	}
	if (info->map[(int)info->position_player_y][(int)info->position_player_x] \
			== 'S')
	{
		info->dir_x = 0;
		info->dir_y = 1;
		info->plane_x = -0.66;
		info->plane_y = 0;
	}
	else
		save_direction_player2(info);
}
