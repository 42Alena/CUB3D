/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visuals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:32:28 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/11 05:32:52 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_bool is_map_settings_complete(t_game *game)
{
	if (game->map.no_texture != NULL && game->map.so_texture != NULL &&
		game->map.we_texture != NULL && game->map.ea_texture != NULL &&
		game->map.floor_color_str != NULL && game->map.ceiling_color_str != NULL)
		return (TRUE);
	else
		return (FALSE);
}

/*
map must be at the and of file. mininimal size of map can be col=3, rows=3:
(y < game->map.rows - 3)
 */
void save_map_textures_and_colors(t_game *game)
{
	int y;
	char *temp_line;

	y = 0;
	while (y <= game->map.rows - 3 || is_map_settings_complete(game))
	{
		temp_line = ft_strtrim(game->map.saved_map[y], " ");
		if (is_substring("NO ", temp_line, 0, 3))
			wall_file_check_save(game, &(game->map.no_texture), temp_line);
		else if (is_substring("SO ", temp_line, 0, 3))
			wall_file_check_save(game, &(game->map.so_texture), temp_line);
		else if (is_substring("WE ", temp_line, 0, 3))
			wall_file_check_save(game, &(game->map.we_texture), temp_line);
		else if (is_substring("EA ", temp_line, 0, 3))
			wall_file_check_save(game, &(game->map.ea_texture), temp_line);
		else if (is_substring("F ", temp_line, 0, 2))
			save_map_color(game, &(game->map.floor_color_str), temp_line);
		else if (is_substring("C ", temp_line, 0, 2))
			save_map_color(game, &(game->map.ceiling_color_str), temp_line);
		else if (!is_empty_line(temp_line))
		{
			free(temp_line);
			break;
		}
		free(temp_line);
		y++;
	}
	// print_map_structure(game);
	if (is_map_settings_complete(game) == FALSE)
		error_map_exit_game(game, "Map's requirements: Texture or color information is missing");
	// extract_map_save(game, y);
	// TODO: save y as first line of map

	// if all structures full => beginns map check from this line
}

void wall_file_check_save(t_game *game, char **name_txtr, char *line)
{
	int length_name_txtr;

	if (*name_txtr != NULL)
	{
		free(line);
		error_map_exit_game(game, "Map: double map settings for texture");
	}
	length_name_txtr = ft_strlen(line) - 3;
	*name_txtr = ft_substr(line, 3, length_name_txtr);
	*name_txtr = ft_strtrim(*name_txtr, " ");
	if (*name_txtr == NULL)
		error_map_exit_game(game, "Missing file: <wall>.png");
	length_name_txtr = ft_strlen(*name_txtr);
	if (length_name_txtr <= 4)
	{
		free(line);
		error_map_exit_game(game, "Expected file:  <wall>.png");
	}
	else if (is_substring(".png", *name_txtr, length_name_txtr - 4, 4) == FALSE)
	{
		free(line);
		error_map_exit_game(game, "Invalid  file extension: .png expected");
	}
	is_valid_file(game, *name_txtr);
}

// void	wall_file_check_save(t_game *game, char **name_txtr, char *line)
// {
// 	char	*wall_path;
// 	int		length_wall_path;

// 	if (*name_txtr != NULL)
// 	{
// 		free(line);
// 		error_map_exit_game(game, "Map: double map settings for texture");
// 	}
// 	length_wall_path = ft_strlen(line) - 3;
// 	wall_path = ft_substr(line, 3, length_wall_path);
// 	wall_path = ft_strtrim(wall_path, " ");
//     if (wall_path == NULL)
// 		error_map_exit_game(game, "Missing file: <wall>.png");
// 	length_wall_path = ft_strlen(wall_path);
// 	if (length_wall_path <= 4)
// 	{
// 		free(line);
// 		free(wall_path);
// 		error_map_exit_game(game, "Expected file:  <wall>.png");
// 	}
// 	else if (is_substring(".png", wall_path, length_wall_path - 4, 4) == FALSE)
// 	{
// 		free(line);
// 		free(wall_path);
// 		error_map_exit_game(game, "Invalid  file extension: .png expected");
// 	}
// 	is_valid_file(game, wall_path);
// 	*name_txtr = wall_path;

// }

// int get_rgba(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }
// TODO check if colors from 0 to 255

//(rgb[0] << 24) + (rgb[1] << 16) + (rgb[2] << 8)
void save_map_color(t_game *game, char **name_color, char *line)
{
	int length_color_str;

	// dprintf(2,"name_color: %s\n", name_color);
	// printf("floor_color_str: %s\n", name_color);
	// printf("ceiling_color_str: %s\n", name_color);
	if (*name_color != NULL)
	{
		free(line);
		error_map_exit_game(game, "Map: double map settings for color");
	}
	length_color_str = ft_strlen(line) - 2;
	*name_color = ft_substr(line, 2, length_color_str);
	*name_color = ft_strtrim(*name_color, " ");
	if (*name_color == NULL)
		error_map_exit_game(game, "Missing map settings for color");
	length_color_str = ft_strlen(*name_color);
	if (length_color_str <= 6)
	{
		free(line);
		error_map_exit_game(game, "Invalid color texture");
	}
	// dprintf(2,"name_color after :%s\n", name_color);
	// printf("floor_color_str: %s\n", name_color);
	// printf("ceiling_color_str: %s\n", name_color);

	// TODO: add conversion from color_str to color_uint
	//  (r << 24 | g << 16 | b << 8 | a)
}
