/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:52:02 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/08 18:37:38 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void map_file_check(t_game *game, int argc, char **argv)
{
	int len;
	int	is_dot_cub;

	if (argc != 2)
		error_map_exit_game(game, "To start: ./cub3D map.cub");
	game->map.file_path = ft_strtrim(argv[1], " ");
	if (game->map.file_path == NULL)
		error_map_exit_game(game, "Missing map file: <map_name>.cub");
	len = ft_strlen(game->map.file_path);
	if (len <= 4)
		error_map_exit_game(game, "Expected file: <map_name>.cub");
	is_dot_cub = is_substring(".cub", game->map.file_path, len - 4, 4);
	if (is_dot_cub == FALSE)
		error_map_exit_game(game, "Invalid  file extension: .cub expected");
	is_valid_file(game, game->map.file_path);
}

t_bool is_valid_file(t_game *game, char *temp_file)
{
	int fd;
	char buffer[1];
	ssize_t bytes_read;

	fd = open(temp_file, O_RDONLY);
	if (fd == -1)
		error_map_exit_game(game, "Can not open the map");
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
		close(fd);
		error_map_exit_game(game, "Error reading file");
	}
	if (bytes_read == 0)
	{
		close(fd);
		error_map_exit_game(game, "Error: File is empty");
	}
	close(fd);
	return (TRUE);
}
