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


void wall_file_check_save(t_game *game, char **name_txtr)
{
	if (*name_txtr != NULL)
		error_map_exit_game(game, "Map: double map settings for texture");
	*name_txtr = ft_substr(game->map.tmp_line, 3, game->map.len_tmp_line - 3); 
	*name_txtr = ft_strtrim(*name_txtr, " ");
	if (*name_txtr == NULL)   //TODO: change to is_empty_line
		error_map_exit_game(game, "Missing file: <wall>.png");
	game->map.len_tmp_line = ft_strlen(*name_txtr);
	if (game->map.len_tmp_line <= 4)
		error_map_exit_game(game, "Expected file:  <wall>.png");
	else if (is_substring(".png", *name_txtr, game->map.len_tmp_line - 4, 4) == FALSE)
		error_map_exit_game(game, "Invalid  file extension: .png expected");

	// printf("wall_file_check_save: %s\n", *name_txtr);
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
