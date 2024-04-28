/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:35 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/04 10:41:38 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/* first and last line must be  one's with/without spaces*/
void	check_walls_save_in_struct(t_game *game)
{
	game->map.first_line = 0;
	game->map.last_line = game->map.rows;
	while (game->map.first_line < game->map.last_line)
	{
		game->map.tmp_line = game->map.saved_map[game->map.first_line];
		if (!is_empty_tmp_line(game))
			break ;
		game->map.first_line++;
	}
	is_map_north_south_wall(game);
	if (game->map.first_line == game->map.last_line)
		error_map_exit_game(game, "Map: no north wall");
	while (game->map.last_line >= game->map.first_line)
	{
		game->map.tmp_line = game->map.saved_map[game->map.last_line];
		if (!is_empty_tmp_line(game))
			break ;
		game->map.last_line--;
	}
	if (game->map.last_line <= (game->map.first_line + 1))
		error_map_exit_game(game, "Map: no south wall");
	is_map_north_south_wall(game);
}

t_bool	is_map_north_south_wall(t_game *game)
{
	int	x;
	int	ones;

	x = 0;
	ones = 0;
	while (game->map.tmp_line[x])
	{
		if (game->map.tmp_line[x] == '1')
			ones += 1;
		else if (game->map.tmp_line[x] != ' ')
		{
			game->map.tmp_line = NULL;
			error_map_exit_game(game, "Map: no south/north wall");
		}
		x++;
	}
	if (ones == 0)
		return (FALSE);
	return (TRUE);
}
