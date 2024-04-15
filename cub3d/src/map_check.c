/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:59 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/15 12:45:55 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void check_map(t_game *game)
{
	// int row;
	
	// row = 0;
	walls_check_save_in_struct(game);
	printf("check_map => I AM HERE!;)\n");
	// between first and last check for empty s[aces]
	map_check_middle_lines(game);
}

void	check_maps_characters(t_game *game, int row)
{
	
	int col;
	char c;
	col = 0;

	// while (game->map.tmp_line[x] && game->map.tmp_line[x] != ' ')
	// 	x++;
	while (game->map.saved_map[row][col])
	{
		// printf("check_maps_characters => I AM HERE!;)\n");
		c = game->map.saved_map[row][col];
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			// printf("check_maps_characters: player|%c|, x=%d, y= %d\n", game->map.saved_map[x][row],x, row);
		 	player_check_save(game, row, col);
		}
		// if ((c == '0' && game->map.tmp_line[x - 1] && game->map.tmp_line[x - 1] == ' ') ||\
		// 	(c == '0' && game->map.tmp_line[x + 1] && game->map.tmp_line[x + 1] == ' ') ||\
		// 	(c == '0' && game->map.tmp_line[y - 1] && game->map.tmp_line[y - 1] == ' ') ||\
		// 	(c == '0' && game->map.tmp_line[y + 1] && game->map.tmp_line[y + 1] == ' '))
		// 	error_map_exit_game(game, "Map: '0' adjacent to a space character");
		col++;
	}
}
