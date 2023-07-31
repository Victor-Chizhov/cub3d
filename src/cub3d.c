#include "../include/cub3d.h"

void	check_name_file(char *av)
{
	size_t	len;
	char	*tmp;

	tmp = av;
	len = ft_strlen(tmp);
	if (ft_strncmp(&tmp[len - 4], ".cub", len))
		print_error(1);
}

void	init_struct_img(t_game *info)
{
    int	i;

    i = -1;
    while (++i < 4)
    {
        info->img_sprites[i].img = 0;
        info->img_sprites[i].addr = 0;
        info->img_sprites[i].bits_per_pixel = 0;
        info->img_sprites[i].width = 0;
        info->img_sprites[i].height = 0;
        info->img_sprites[i].line_length = 0;
        info->img_sprites[i].endian = 0;
    }
}

int	main(int ac, char **av)
{
	t_game	info;

	if (ac != 2)
		print_error(1);
	check_name_file(av[1]);
	init_info(&info);
    init_struct_img(&info);
	parsing_file(av[1], &info);
	init_window_with_map(&info);
}