/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:59 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 12:24:14 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/* The map must be:
1. closed/surrounded by walls, if not the program must return an error.

2. Except for the map content, each type of element can be separated by one or more empty line(s).

3.  Except for the map content which always has to be the last, each type of element can be set in any order in the file.

4. Except for the map, each type of information from an element can be separated by one or more space(s).

5. The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. 

6. You must be able to parse any kind of map, as long as it respects the rules of the map. 

ADDITIONAL CHECK:
7.  add flood_fill to check, if player surrounded by walls
8. CHECK IF ONLY ONE PLAYER
9. DECIDE: if spaces behind walls is part of map or not
11: TEXTURES
	[] valid letters: NO, SO,WE,EA
	[] valid path (aacesable?)
11: COLORS:
	[] valid letters: F, C
	[] if real RGB colours (220,100,0= R,G,B colors in range [0,255]: 0, 255, 255)

*/


/// ONLY TO TEST as coordinates/////////
void print_map(t_game *game) {
    for (int y = 0; y < game->map_info.rows; y++) {
        for (int x = 0; x < game->map_info.cols; x++) {
            printf("(%d, %d): %c\n", y, x, game->map[y][x]);
        }
    }
}

int	check_input(int argc, char **argv)
{
	int	len_argv1;

	if (argc != 2)
		ft_error(NULL, "Invalid arguments. Start: ./cub3D <map_name>.cub");
	len_argv1 = ft_strlen(argv[1]);
	if ((len_argv1 < 5) || (argv[1][len_argv1 - 4] != '.')
		|| (argv[1][len_argv1 - 3] != 'c') || (argv[1][len_argv1 - 2] != 'u')
		|| (argv[1][len_argv1 - 1] != 'b'))
			ft_error(NULL, "Invalid file extension: .cub expected");
	return (0);
}



// void	check_map_walls(t_game *game)
// {
// 	int		x;
// 	int		y;
// 	char	c;

// 	y = 0;
// 	while (y < game->map_info.rows)
// 	{
// 		x = 0;
// 		while (x < game->map_info.cols)
// 		{
// 			c = get_map_value(game, x, y);
// 			if ((y == 0 || y == (game->map_info.rows - 1)) && (c == '1'))
// 				x++;
// 			else if ((x == 0 || x == (game->map_info.cols - 1)) && (c != '1'))
// 				ft_error(game, "Map must have walls");
// 			else
// 				x++;
// 		}
// 		y++;
// 	}
// }

// /* help function to check_maps_characters(t_game *game) 
// //TODO:DECIDE IF  SPACES ARE PART OF THE MAP
// */
// void	check_characters(t_game *game, char c, int x, int y)
// {
// 	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
// 	{
// 		if (game->player_count > 1)
// 			ft_error(game, "Map's requirements: set player direction to N,S,E or W");
// 		game->player_direction = c;
// 		game->player_x = x;
// 		game->player_y = y;
// 		game->player_count += 1;
// 	}
// 	else if (c != ' ' && c != '0' && c != '1')
// 		ft_error(game, "Map's requirements: set player direction to N,S,E or W");
// }

// /*
// The map must be composed of only 6 possible characters: 0 for an empty space,
// 1 for a wall, and N,S,E or W for the player’s start position and spawning
// orientation
// */
// void	check_maps_characters(t_game *game)
// {
// 	int		x;
// 	int		y;
// 	char	c;

// 	y = 1;
// 	check_map_walls(game);
// 	while (y < game->map_info.rows)
// 	{
// 		x = 1;
// 		while (x < game->map_info.cols)
// 		{
// 			c = get_map_value(game, x, y);
// 			check_characters(game, c, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (player_count != 1)
// 		ft_error(game, "Map's requirements: 1 player");

// 	if (game->player_direction == FALSE)
// 		ft_error(game, "Map's requirements: set player direction to N,S,E or W");
// }
