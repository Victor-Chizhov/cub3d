/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:09:04 by vchizhov          #+#    #+#             */
/*   Updated: 2023/08/01 13:29:53 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "string.h"
# include <math.h>

# define A				0
# define S				1
# define D				2
# define W				13
# define RIGHT			124
# define LEFT			123
# define ESC			53
# define WINDOW_W		640
# define WINDOW_H		480
# define TEX_WIDTH		64
# define TEX_HEIGHT		64

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_game {
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		players;
	double	position_player_x;
	double	position_player_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		hit;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		map_x;
	int		map_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	move_speed;
	double	turn_speed;
	double	wall_x;
	double	texture_x;
	double	texture_y;
	void	*sprite_north;
	void	*sprite_south;
	void	*sprite_west;
	void	*sprite_east;
	int		height_sprite;
	int		width_sprite;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		floor_color;
	int		ceiling_color;
	int		count_arguments_in_file;
	t_img	img;
	t_img	img_sprites[4];
}			t_game;

void	print_error(char *err, int a);
void	read_arr(char **arr);
int		len_pointer_arr(char **arr);
void	free_arr(char **arr);
char	*remove_spaces_from_str(char *string);

//=============== COPY FROM FILE ATTRIBUTES =====================
char	*check_symbols_f_and_c(char *check_file);
char	*copy_from_file(char *check_file, t_game *info);
char	*copy_from_file_for_f_and_c(char *check_file, t_game *info);
void	check_open_file(char **check_file, t_game *info);

// =============== COPY FROM FILE MAP ==========================

char	**copy_map(char **check_file);
char	**copy_after_check_map(char **check_file, int start, int end);
int		end_map(char **check_file);
int		start_map(char **check_file);
void	check_map_in_end(char **check_file);

// =============== CHECK MAP ========================

void	check_first_string_of_map(t_game *info);
void	check_last_string_of_map(t_game *info);
int		check_other_string_of_map(char *string);
void	check_wall_map(t_game *info);
void	check_every_string_of_map(t_game *info);

// ============== PARSING FILE TO MAP ===============

void	init_info(t_game *map);
void	check_count_players(char **check_file, t_game *info);
void	parsing_file(char *av, t_game *info, \
		char *open_file, char **check_file);
void	save_direction_player(t_game *info);

// ============== FOR RAYCASTING =====================

float	ft_abs(float num);

// ============== INIT WINDOW WITH MAP ================

void	init_window_with_map(t_game *map);
void	init_sprites(t_game *map);

// ============== DRAW SCENE ===========================

void	draw_floor_and_ceiling(t_game *info);
void	my_mlx_pixel_put(t_game *data, int x, int y, int color);
void	ray_casting(t_game *info);
void	draw_wall_with_texture(t_game *info, int x, \
		int num_texture, double step);
int		find_num_texture(t_game *info);

// =============== EXIT GAME ==========================

int		my_keypress_hook(int keycode, t_game *map);
int		exit_game(t_game *map);
void	deleted_sprites(t_game *map);

// =============== MOVE PLAYER ========================

void	move_forward(t_game *info);
void	move_left(t_game *info);
void	move_backward(t_game *info);
void	move_right(t_game *info);
void	rotation_right(t_game *info);
void	rotation_left(t_game *info);

#endif
