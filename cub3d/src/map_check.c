/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:59 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/14 10:38:04 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void check_map(t_game *game)
{
	// int row;
	
	// row = 0;
	walls_check_save_in_struct(game);
	// between first and last check for empty s[aces]
	map_check_middle_lines(game);
}

void	check_maps_characters(t_game *game, int row)
{
	
	int x;
	char c;
	x = 0;

	// while (game->map.tmp_line[x] && game->map.tmp_line[x] != ' ')
	// 	x++;

	while (game->map.tmp_line[x])
	{
		c = game->map.tmp_line[x];
		// if ((c == '0' && game->map.tmp_line[x - 1] && game->map.tmp_line[x - 1] == ' ') ||\
		// 	(c == '0' && game->map.tmp_line[x + 1] && game->map.tmp_line[x + 1] == ' ') ||\
		// 	(c == '0' && game->map.tmp_line[y - 1] && game->map.tmp_line[y - 1] == ' ') ||\
		// 	(c == '0' && game->map.tmp_line[y + 1] && game->map.tmp_line[y + 1] == ' '))
		// 	error_map_exit_game(game, "Map: '0' adjacent to a space character");
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			check_save_player(game, c, x, row);
		x++;
	}
}
