/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:52:02 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/28 21:18:47 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/* NEW_WORKING */
int	map_file_check(int argc, char **argv)
{
	char	*temp_file;
	int		length_temp_file;

	if (argc != 2)
		ft_error(NULL, "Missing map file: <map_name>.cub");
    temp_file = ft_strtrim(argv[1], " ");
    if (temp_file == NULL)
		ft_error(NULL, "Missing map file: <map_name>.cub");
	length_temp_file = ft_strlen(temp_file);
	if (length_temp_file < 5)
	{
		free(temp_file);
		ft_error(NULL, "Expected file: <map_name>.cub");
	}
	else if (is_substring(".cub", temp_file, length_temp_file - 4, 4) == FALSE)
	{
		free(temp_file);
		ft_error(NULL, "Invalid  file extension: .cub expected");
	}
	check_valid_file(temp_file);
	free(temp_file);
	return (0);
}

void check_valid_file(char *temp_file)
{
	int		fd;
	
	fd = open(temp_file, O_RDONLY);
	if (fd == -1)
	{
		free(temp_file);
		ft_error(NULL, "Can not open the map");
	}
	else
		close(fd);
}