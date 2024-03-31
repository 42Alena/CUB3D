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

/* 
map must be at the and of file. mininimal size of map can be col=3, rows=3:
(y < game->map.rows - 3)
 */
void	save_map_textures_and_colors(t_game *game)
{
	int		y;
	char *temp_line;
	char *key;
	y = 0;
	
	key = NULL;
    while (y < game->map.rows - 3)
	{
		temp_line = ft_strtrim(game->map.saved_map[y], " ");
		if (temp_line == NULL)
			y++;	
		else if (is_substring("NO ", temp_line, 0, 3))
			wall_file_check_save(game->map.no_texture, char *wall_file);



		// if (!safe_check_substring("NO", temp_line, 0, 2) && game->map.n_texture == NULL)
        check_save_map_texture(game, "NO ", game->map.no_texture, y);
		// else if (!safe_check_substring("SO", temp_line, 0, 2) && game->map.s_texture == NULL)
        check_save_map_texture(game, "SO ", game->map.so_texture, y);
		// else if (!safe_check_substring("WE", temp_line, 0, 2) && game->map.w_texture == NULL)
        check_save_map_texture(game, "WE ", game->map.we_texture, y);
		// else if (!safe_check_substring("EA", temp_line, 0, 2) && game->map.e_texture == NULL)
        check_save_map_texture(game, "EA ", game->map.ea_texture, y);
		
		
		// else

			// 	save_map_color(game, game->map.ceiling_color, y);
        y++;
    }
	//check if all structures full
	if (game->map.no_texture == NULL || game->map.so_texture == NULL || \
		game->map.we_texture == NULL || game->map.ea_texture == NULL || \
		game->map.floor_color == NULL || game->map.ceiling_color == NULL)
			ft_error(game, "Map's requirements: Texture or color information is missing");
	// if all structures full => beginns map check from this line
	free(temp_line);
}


// /* 
// map must be at the and of file. mininimal size of map can be col=3, rows=3:
// (y < game->map.rows - 3)
//  */
// void	save_map_textures_and_colors(t_game *game)
// {
// 	int		y;
// 	char *temp_line;
// 	y = 0;
	
//     while (y < game->map.rows - 3)
// 	{
// 		temp_line = ft_strtrim(game->map.saved_map[y], " ");
// 		//skip empty lines till map
// 		if (temp_line == NULL)
// 			y++;





// 		// if (!safe_check_substring("NO", temp_line, 0, 2) && game->map.n_texture == NULL)
//         check_save_map_texture(game, "NO ", game->map.no_texture, y);
// 		// else if (!safe_check_substring("SO", temp_line, 0, 2) && game->map.s_texture == NULL)
//         check_save_map_texture(game, "SO ", game->map.so_texture, y);
// 		// else if (!safe_check_substring("WE", temp_line, 0, 2) && game->map.w_texture == NULL)
//         check_save_map_texture(game, "WE ", game->map.we_texture, y);
// 		// else if (!safe_check_substring("EA", temp_line, 0, 2) && game->map.e_texture == NULL)
//         check_save_map_texture(game, "EA ", game->map.ea_texture, y);
		
		
// 		// else

// 			// 	save_map_color(game, game->map.ceiling_color, y);
//         y++;
//     }
// 	if (game->map.n_texture == NULL || game->map.s_texture == NULL || \
// 		game->map.w_texture == NULL || game->map.e_texture == NULL || \
// 		game->map.floor_color == NULL || game->map.ceiling_color == NULL)
// 			ft_error(game, "Map's requirements: Texture or color information is missing");
// }




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
