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

int	main(int ac, char **av)
{
	t_game	info;

	if (ac != 2)
		print_error(1);
	check_name_file(av[1]);
	init_info(&info);
	parsing_file(av[1], &info);
}