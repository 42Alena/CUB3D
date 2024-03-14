/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:59 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/14 09:15:55 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void find_first_last_line(t_game *game)
{
	int	y;
	int	first_line;
	int	last_line;

	y = 0;
	while (y < game->map.rows)
	{
		if (is_map_walls_first_last_line(game->map.saved_map[y]))
			first_line = y;
		y++;
	}
	y = game->map.rows - 1;
	while (y > 0)
	{
		if (is_map_walls_first_last_line(game->map.saved_map[y]))
			last_line = y;
		y--;
	}
	if (first_line == 0 || last_line == 0)
		ft_error(game, "Not valid map");
	if(first_line <= 7)
		ft_error(game, "Missing maps settings");
	game->map.first_map_line = first_line;
	game->map.last_map_line = last_line;
}

void	is_valid_map(t_game *game)
{
	int	player_count;
	int	y;

	player_count = 0;
	y = 0;
	if (game->map.cols == 0 && game->map.rows == 0)
		ft_error(game, "Map is empty");
	find_first_last_line(game);
	//TODO: add hier check colors and structures before game->map.first_map_line;

	y = game->map.first_map_line;
	while (y < game->map.last_map_line)
	{
		is_map_middle_lines(game, y);
		y++;
	}

}
