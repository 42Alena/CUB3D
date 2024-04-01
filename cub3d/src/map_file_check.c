/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:52:02 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/01 19:47:27 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/* NEW_WORKING */
t_bool	map_file_check(int argc, char **argv)
{
	char	*temp_file;
	int		length_temp_file;

	if (argc != 2)
		ft_error(NULL, "Missing map file: <map_name>.cub");
    temp_file = ft_strtrim(argv[1], " ");
    if (temp_file == NULL)
		ft_error(NULL, "Missing map file: <map_name>.cub");
	length_temp_file = ft_strlen(temp_file);
	if (length_temp_file <= 4)
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
	return (TRUE);
}

//TODO: add check if file is empty
/* Attempt to read a single byte */
t_bool check_valid_file(char *temp_file)
{
	int		fd;
	char	buffer[1];
	ssize_t	bytes_read;
	 
	fd = open(temp_file, O_RDONLY);
	if (fd == -1)
	{
		free(temp_file);
		ft_error(NULL, "Can not open the map");
	}
   	bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1)
	{
        free(temp_file);
        close(fd);
		ft_error(NULL, "Error reading file");
    }
    if (bytes_read == 0)
	{
        free(temp_file);
		close(fd);
		ft_error(NULL, "Error: File is empty");
	}
	close(fd);
	return (TRUE);
}

//TODO: WORKING HIER
//do I need hier struct game?
// t_bool	wall_file_check_save(char *name_txtr,char *wall_file, t_game *game)
t_bool	wall_file_check_save(char *name_txtr, char *line)
{
	char	*wall_path;
	int		length_wall_path;

	if (name_txtr != NULL)
	{
		free(line);
		ft_error(NULL, "Double texture");
	}
	length_wall_path = ft_strlen(line) - 3;
	wall_path = ft_substr(line, 3, length_wall_path);
	wall_path = ft_strtrim(wall_path, " ");
    if (wall_path == NULL)
		ft_error(NULL, "Missing file: <wall>.png");
	length_wall_path = ft_strlen(wall_path);
	if (length_wall_path <= 4)
	{
		free(line);
		free(wall_path);
		ft_error(NULL, "Expected file:  <wall>.png");
	}
	else if (is_substring(".png", wall_path, length_wall_path - 4, 4) == FALSE)
	{
		free(line);
		free(wall_path);
		ft_error(NULL, "Invalid  file extension: .png expected");
	}
	check_valid_file(wall_path);
	name_txtr = wall_path;
	free(wall_path);
	return (TRUE);
}
