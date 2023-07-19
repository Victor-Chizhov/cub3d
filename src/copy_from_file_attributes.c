#include "../include/cub3d.h"

char *check_symbols_f_and_c(char *check_file)
{
	char *tmp;
	int i;

	i = 0;
	tmp = remove_spaces_from_str(check_file);
	tmp++;
	while(tmp[i])
	{
		if (tmp[i] < ',' || (tmp[i] > ',' && tmp[i] < '0')  || tmp[i] > '9')
			return (NULL);
		i++;
	}
	return tmp;
}

char *copy_from_file(char *check_file, t_game *info)
{
	char **arr;
	char *new;

	new = NULL;
	arr = ft_split(check_file, ' ');
	if (len_pointer_arr(arr) != 2)
	{
		free_arr(arr);
		printf("In copy_from_file len_pointer_arr != 2\n");
		print_error(1);
	}
	new = ft_strdup(arr[1]);
	ft_strlcpy(check_file, " ", 1);
	info->count_arguments_in_file++;
	return new;
}

char *copy_from_file_for_f_and_c(char *check_file, t_game *info)
{
	char *new;

	new = NULL;
	if (!check_symbols_f_and_c(check_file)) {
		printf("After check_symbols_f_and_c F or C not valid\n");
		print_error(1);
	}
	new = ft_substr(check_file, 1, ft_strlen(check_file) - 1);
	ft_strlcpy(check_file, " ", 1);
	info->count_arguments_in_file++;
	return new;
}

void	check_open_file(char **check_file, t_game *info)
{
	int	i;
	int j;

	i = 0;
	while (check_file[i])
	{
		j = 0;
		while(check_file[i][j] && check_file[i][j] == ' ')
			j++;
		if(check_file[i][j] == 'N' && check_file[i][j + 1] == 'O' && check_file[i][j + 2] == ' ')
			info->north = copy_from_file(check_file[i], info);
		else if (check_file[i][j] == 'S' && check_file[i][j + 1] == 'O' && check_file[i][j + 2] == ' ')
			info->south = copy_from_file(check_file[i], info);
		else if (check_file[i][j] == 'W' && check_file[i][j + 1] == 'E' && check_file[i][j + 2] == ' ')
			info->west = copy_from_file(check_file[i], info);
		else if (check_file[i][j] == 'E' && check_file[i][j + 1] == 'A' && check_file[i][j + 2] == ' ')
			info->east = copy_from_file(check_file[i], info);
		else if (check_file[i][j] == 'F' && check_file[i][j + 1] == ' ')
			info->floor = copy_from_file_for_f_and_c(check_file[i], info);
		else if (check_file[i][j] == 'C' && check_file[i][j + 1] == ' ')
			info->ceilling = copy_from_file_for_f_and_c(check_file[i], info);
		i++;
	}
	if (info->count_arguments_in_file != 6) {
		printf("count_arguments_in_file: no 6");
		print_error(1);
	}
}