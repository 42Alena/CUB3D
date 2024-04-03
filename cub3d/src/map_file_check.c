/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:52:02 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/03 17:34:03 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_bool map_file_check(t_game *game, int argc, char **argv)
{
	char *temp_file;
	int length_temp_file;

	if (argc != 2)
		error_map_exit_game(game, "Missing map file: <map_name>.cub");
	temp_file = ft_strtrim(argv[1], " ");
	if (temp_file == NULL)
		error_map_exit_game(game, "Missing map file: <map_name>.cub");
	length_temp_file = ft_strlen(temp_file);
	if (length_temp_file <= 4)
	{
		free(temp_file);
		error_map_exit_game(game, "Expected file: <map_name>.cub");
	}
	else if (is_substring(".cub", temp_file, length_temp_file - 4, 4) == FALSE)
	{
		free(temp_file);
		error_map_exit_game(game, "Invalid  file extension: .cub expected");
	}
	is_valid_file(game, temp_file);
	free(temp_file);
	return (TRUE);
}

t_bool is_valid_file(t_game *game, char *temp_file)
{
	int fd;
	char buffer[1];
	ssize_t bytes_read;

	fd = open(temp_file, O_RDONLY);
	if (fd == -1)
	{
		free(temp_file);
		error_map_exit_game(game, "Can not open the map");
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
		free(temp_file);
		close(fd);
		error_map_exit_game(game, "Error reading file");
	}
	if (bytes_read == 0)
	{
		free(temp_file);
		close(fd);
		error_map_exit_game(game, "Error: File is empty");
	}
	close(fd);
	return (TRUE);
}
