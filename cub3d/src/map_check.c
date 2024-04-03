/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:59 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/03 17:34:03 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation
*/
// void	check_maps_characters(t_game *game)
// {
// 	int		x;
// 	int		y;
// 	char	c;
// 	int		player_count;

// 	y = 0;
// 	player_count = 0;

// 	//TODO:check_map_walls(game);

// 	while (y < game->map.rows)
// 	{
// 		x = 0;
// 		while (x < game->map.cols)
// 		{
// 			c = game->map.saved_map[y][x];
// 			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
// 			{
// 				player_count += 1;
// 				if (player_count > 1)
// 					error_map_exit_game(game, \
// 					"Map's requirements: one player");
// 				save_player_struct(game, c, x, y);
// 			}
// 			else if (c != ' ' && c != '0'  && c != '1')
// 			{
// 				//TODO: check if ' ' only before and after outside walls,
// 				//but not inside map
// 				//TODO:check_map_walls(game);
// 				error_map_exit_game(game, \
// 					"Map's requirements: set player direction to N,S,E or W");
// 			}

// 			x++;
// 		}
// 		y++;
// 	}
// }
