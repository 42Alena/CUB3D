/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:59 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/07 16:28:30 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

#include "../includes/cub3D.h"

//////////////////////////PRINTs FOR TEST MAPS//////////////////////
//TODO: move/delete before push 
void print_map_pos_x_y(t_game *game)
{
    int y = 0;
    while (y < game->map.rows)
	{
        int x = 0;
        while (x < game->map.cols)
		{
            printf("(%d, %d): %c\n", y, x, game->map.saved_map[y][x]);
            x++;
        }
        y++;
    }
}

void print_map(t_game *game)
{
    int y = 0;
    while (y < game->map.rows)
	{
        int x = 0;
        while (x < game->map.cols)
		{
            printf("%c", game->map.saved_map[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
}

/// //////////////////////////////////////////////////////////



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
	
	//	//TODO:check_map_walls(game);

    while (y < game->map.rows)
	{
        x = 0;
        while (x < game->map.cols)
		{
			c = game->map.saved_map[y][x];
			//CHECK PLAYER
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				player_count += 1;
				if (player_count >= 1)
					ft_error(game, "Map's requirements: set player direction to N,S,E or W");
			}
            x++;
        }
        y++;
    }
}
