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

void load_textures(t_game *game)
{
	mlx_texture_t *wall;

	wall = mlx_load_png("./textures/wall.png");
	game->textures.north = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/wall2.png");
	game->textures.south = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/wall3.png");
	game->textures.west = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/wall4.png");
	game->textures.east = get_color(wall);
	mlx_delete_texture(wall);
}

// int get_rgba(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }
// TODO check if colors from 0 to 255
// void save_map_color(t_game *game, char *name_color, char *struct_map_color, int y)
// {
// 	int		color_length;
// 	int		fd;
// 	char	*temp_color;
	
// 	if (struct_map_color != -1)
// 		ft_error(NULL, "Double texture");
// 	temp_color = ft_strtrim(game->map.saved_map[y], " ");
// 	color_length =  ft_strlen(temp_color);
// 	if (color_length <= 6)
// 		ft_error(NULL, "Invalid color texture");
// 	if (!safe_check_substring(name_color, temp_color, 0, 2))
// 		return ;
// 	temp_color = ft_substr(temp_color, 0, 2);
// 	temp_color = ft_strtrim(temp_color, " ");

// 	// if (!safe_check_substring(".png", temp_color, color_length - 4, 4))
// 	// 	ft_error(NULL, "Invalid texture extension: .png expected");		
// 	printf("%s\n", temp_color);
// 	fd = open(temp_color, O_RDONLY);
// 	if (fd == -1)
// 		ft_error(game, "Failure of opening texture");
// 	else
// 		name_color = temp_color;
// 	// (r << 24 | g << 16 | b << 8 | a)
// }


void	check_save_map_texture(t_game *game, char *name_txtr, char *struct_map_path, int y)
{
	int		path_length;
	int		fd;
	char	*temp_path;
	
	if (struct_map_path != NULL)
		ft_error(NULL, "Double texture");
	else
	{

		temp_path = ft_strtrim(game->map.saved_map[y], " ");
		path_length =  ft_strlen(temp_path);
		if (path_length <= 8)
			ft_error(NULL, "Invalid path texture");
		if (!safe_check_substring(name_txtr, temp_path, 0, 3))
			return ;
		temp_path = ft_substr(temp_path, 3, path_length - 3);
		temp_path = ft_strtrim(temp_path, " ");
		if (!safe_check_substring(".png", temp_path, ft_strlen(temp_path) - 4, 4))
			ft_error(NULL, "Invalid texture extension: .png expected");		
		fd = open(temp_path, O_RDONLY);
		if (fd == -1)
			ft_error(game, "Failure of opening texture");
		else
			struct_map_path = temp_path;
		printf("%s\n", temp_path);
	}
}

void	save_map_textures_and_colors(t_game *game)
{
	int		y;
	char *temp_line;
	y = 0;
	
    while (y < game->map.rows - 3)
	{
		//skip new and empty line UNTIL map first line 
		temp_line = ft_strtrim(game->map.saved_map[y], " ");
		// if (!safe_check_substring("NO", temp_line, 0, 2) && game->map.n_texture == NULL)
        check_save_map_texture(game, "NO ", game->map.n_texture, y);
		// else if (!safe_check_substring("SO", temp_line, 0, 2) && game->map.s_texture == NULL)
        check_save_map_texture(game, "SO ", game->map.s_texture, y);
		// else if (!safe_check_substring("WE", temp_line, 0, 2) && game->map.w_texture == NULL)
        check_save_map_texture(game, "WE ", game->map.s_texture, y);
		// else if (!safe_check_substring("EA", temp_line, 0, 2) && game->map.e_texture == NULL)
        check_save_map_texture(game, "WE ", game->map.s_texture, y);
		// else

		// 	ft_error(NULL, "Double texture");
		
		// 	check_save_map_texture(game, "SO ", game->map.s_texture, y);
        // // else if (y == 'W' && y + 1 == 'E' && y + 2 == ' ')
		// 	check_save_map_texture(game, "WE ", game->map.w_texture, y);
        // else if (y == 'E' && y + 1 == 'A' && y + 2 == ' ')
		// 	check_save_map_texture(game, "EA ", game->map.e_texture, y);
		//TODO add color finder and check
			// else if (c == 'F' && next_c == ' ')
			// 	save_map_color(game, game->map.floor_color, y);
			// else if (c == 'C' && next_c == ' ')
			// 	save_map_color(game, game->map.ceiling_color, y);
        y++;
    }
	if (game->map.n_texture == NULL || game->map.s_texture == NULL || \
		game->map.w_texture == NULL || game->map.e_texture == NULL || \
		game->map.floor_color == NULL || game->map.ceiling_color == NULL)
			ft_error(game, "Map's requirements: Texture or color information is missing");
}
