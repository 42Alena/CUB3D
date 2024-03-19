/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:59 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/18 11:49:39 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
					ft_error(game, \
					"Map's requirements: set player direction to N,S,E or W");
			}
			x++;
		}
		y++;
	}
}
