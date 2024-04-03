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
	if (game->map.no_texture != NULL &&\
	 	game->map.so_texture != NULL &&
		game->map.we_texture != NULL &&\
		game->map.ea_texture != NULL &&
		game->map.floor_color_str != NULL &&\
		game->map.ceiling_color_str != NULL &&\
		game->map.floor_color_uint != 256 &&\
		game->map.ceiling_color_uint != 256)
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
		{
			save_map_color(game, &(game->map.floor_color_str), temp_line);
			game->map.floor_color_uint = get_rgb_from_string(game, game->map.floor_color_str);
		}
		else if (is_substring("C ", temp_line, 0, 2))
		{
			save_map_color(game, &(game->map.ceiling_color_str), temp_line);
			game->map.ceiling_color_uint = get_rgb_from_string(game, game->map.ceiling_color_str);
		}
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

void	draw_floor_ceiling(t_game *game, int x)
{
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	int			y_floor;
	int			y_ceiling;
	
	floor_color = game->map.floor_color_uint;
	ceiling_color = game->map.ceiling_color_uint;
	y_floor = game->ray.draw_end + 1;	
	y_ceiling = game->window_height - y_floor;
	while (y_floor < game->window_height)
	{
		mlx_put_pixel(game->textures.image, x, y_floor, floor_color);
		mlx_put_pixel(game->textures.image, x, y_ceiling, ceiling_color);
		y_floor++;
	}
}
