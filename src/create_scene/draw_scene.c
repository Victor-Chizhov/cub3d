#include "../../include/cub3d.h"

void draw_floor_and_ceiling(t_game *info)
{
    unsigned int *dst;
    unsigned int i;

    dst = (unsigned int *)info->img.addr;
    i = WINDOW_W * WINDOW_H / 2 + 1;
    while(--i > 0)
        *dst++ = info->ceiling_color;
    i = WINDOW_W * WINDOW_H / 2 + 1;
    while(--i > 0)
        *dst++ = info->floor_color;
}

int	ft_texx(t_game *address, int n)
{
    int		texx;
    double	wallx;

    wallx = 0.0;
    if (address->side == 0)
        wallx = address->position_player_y + address->perp_wall_dist \
		* address->ray_dir_y;
    else
        wallx = address->position_player_x + address->perp_wall_dist \
		* address->ray_dir_x;
    wallx -= floor(wallx);
    texx = (int)(wallx * (double)address->img_sprites[n].width);
    if (address->side == 0 && address->ray_dir_x > 0)
        texx = address->img_sprites[n].width - texx - 1;
    if (address->side == 1 && address->ray_dir_y < 0)
        texx = address->img_sprites[n].width - texx - 1;
    return (texx);
}

int draw_wall_with_texture(t_game *address, int x, char *dest, char *dest_2, int texx)
{
    double	step;
    double	texpos;
    int		texy;
    int		i;
    int		n;

    n = create_texture(address);
    i = address->draw_start;
    texx = (int)ft_texx(address, n);
    step = 1.0 * address->img_sprites[n].width / address->line_height;
    texpos = (address->draw_start - WINDOW_H / 2 + \
	address->line_height / 2) * step;
    while (i < address->draw_end)
    {
        texy = (int)texpos & address->img_sprites[n].width;
        texpos += step;
        dest = address->img.img + (i * address->img.line_length + x * (address->img.bits_per_pixel / 8));
        dest_2 = address->img_sprites[n].img + ((int)texpos * address->img_sprites[n].line_length + texx * (address->img_sprites[n].bits_per_pixel / 8));
        *(int *)dest = *(int *)dest_2;
        i++;
    }
    return (0);
}