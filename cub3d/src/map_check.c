/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:59 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/21 21:37:16 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void check_map(t_game *game)
{
	int row;

	check_walls_save_in_struct(game);
	row = game->map.first_line + 1;
	while (row < game->map.last_line)
	{
		game->map.tmp_line = game->map.saved_map[row];
		if (is_empty_tmp_line(game))
			error_map_exit_game(game, "Map: empty line");
		check_maps_characters(game, row);
		row++;
	}
}

void check_maps_characters(t_game *game, int row)
{
	int col;
	char c;
	col = 0;

	while (game->map.saved_map[row][col])
	{
		c = game->map.saved_map[row][col];
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			player_check_save(game, row, col);
		else if (c == '0')
			map_check_floor(game, row, col);
		col++;
	}
}


void map_check_floor(t_game *game, int row, int col)
{

	if (col > 0 && col < game->map.cols - 1)
	{
		if ((game->map.saved_map[row][col - 1] == ' ') |\
			(game->map.saved_map[row][col + 1] == ' ') ||\
			(game->map.saved_map[row + 1][col] == ' ') ||\
			(game->map.saved_map[row - 1][col] == ' '))
			error_map_exit_game(game, "Map: Floor is not inside walls");
	}
}
