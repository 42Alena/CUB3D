/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:59 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/15 19:40:10 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/// //////////////////////////////////////////////////////////
// void	check_map_walls(t_game *game)
// {
// 	int		x;
// 	int		y;
// 	char	c;

// 	y = 0;
// 	while (y < game->map.rows)
// 	{
// 		x = 0;
// 		while (x < game->map.cols)
// 		{
// 			c = get_map_value(game, x, y);
// 			if ((y == 0 || y == (game->map.rows - 1)) && (c == '1'))
// 				x++;
// 			else if ((x == 0 || x == (game->map.cols - 1)) && (c != '1'))
// 				ft_error(game, "Map must have walls");
// 			else
// 				x++;
// 		}
// 		y++;
// 	}
// }


/*
The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation
*/
void	check_maps_characters(t_game *game)
{
	int		x;
	int		y;
	char	c;
	int		player_count;

	y = 0;
	player_count = 0;
	
	//TODO:check_map_walls(game);

    while (y < game->map.rows)
	{
        x = 0;
        while (x < game->map.cols)
		{
			c = game->map.saved_map[y][x];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				save_player_struct(game, c, x, y);
					player_count += 1;
			if (player_count > 1)
				ft_error(game, "Map's requirements: set player direction to N,S,E or W");
			}
            x++;
        }
        y++;
    }
}


/*

*/
void check_min_requirements_map(t_game *game, char *filename)
{
	if (game->map.rows <= 9 && game->map.cols <= 7)
		ft_error(game, "Map is not valid");
	close(fd);
}

check_min_requirements_map