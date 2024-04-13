/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:59 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/13 11:21:57 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void check_map(t_game *game)
{
	// int row;
	
	// row = 0;
	walls_check_save_in_struct(game);
	//between first and last check for empty s[aces]
	// map_check_empty_lines(game);
}

void walls_check_save_in_struct(t_game *game)
{
	game->map.first_line = 0;
	game->map.last_line = game->map.rows;
	while (game->map.first_line < game->map.last_line)
	{
		game->map.tmp_line = game->map.saved_map[game->map.first_line];
		if (!is_empty_tmp_line(game))
			break ;
		// printf(" firstLIne=%d||%s||\n", game->map.first_line, game->map.tmp_line);
		game->map.first_line++;
	}
	printf(" firstLIne=%d||%s||\n", game->map.first_line, game->map.tmp_line);
	is_map_north_south_wall(game);
	if (game->map.first_line == game->map.last_line)
		error_map_exit_game(game, "Map: no north wall");
	while (game->map.last_line >= game->map.first_line)
	{
		game->map.tmp_line = game->map.saved_map[game->map.last_line];
		if (!is_empty_tmp_line(game))
			break ;
		printf(" lastLIne=%d||%s||\n", game->map.last_line, game->map.tmp_line);	
		game->map.last_line--;
	}
	if (game->map.last_line <= (game->map.first_line + 1))
		error_map_exit_game(game, "Map: no south wall");
	printf(" firstLIne=%d||%s||\n", game->map.last_line, game->map.tmp_line);
	is_map_north_south_wall(game);	
}
void	check_maps_characters(t_game *game)
{
	
	int x;
	int row;
	char c;
	x = 0;
	row = 0;

	// while (game->map.tmp_line[x] && game->map.tmp_line[x] != ' ')
	// 	x++;

	while (game->map.tmp_line[x])
	{
		c = game->map.tmp_line[x];
		if ((c == '0' && game->map.tmp_line[x - 1] && game->map.tmp_line[x - 1] == ' ') ||\
			(c == '0' && game->map.tmp_line[x + 1] && game->map.tmp_line[x + 1] == ' ') ||\
			(c == '0' && game->map.tmp_line[row - 1] && game->map.tmp_line[row - 1] == ' ') ||\
			(c == '0' && game->map.tmp_line[row + 1] && game->map.tmp_line[row + 1] == ' '))
			error_map_exit_game(game, "Map: '0' adjacent to a space character");
		if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != '0' && c != '1' && c != ' ')
			error_map_exit_game(game, "Map: Detected unsupported symbol");
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			if ((game->map.tmp_line[x - 1] && game->map.tmp_line[x - 1] != '0' && game->map.tmp_line[x - 1] != '1') ||
				((game->map.tmp_line[x + 1] && game->map.tmp_line[x + 1] != '0' && game->map.tmp_line[x + 1] != '1')))
				error_map_exit_game(game, "Map: Player's position is not valid");
			game->player.count += 1;
			// if (game->player.count != 1)
			// 	error_map_exit_game(game, "Must be 1 Player with direction  N,S,E or W");
		}
		x++;
	}
}
