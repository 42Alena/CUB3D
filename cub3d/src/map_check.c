/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:59 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/12 14:51:07 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void check_map(t_game *game)
{
	int row;
	
	row = 0;
	while(row < game->map.rows)
	{
		game->map.tmp_line = game->map.saved_map[row];
		if (!is_empty_tmp_line(game))
			break ;
		printf("row=%d||emptyLine||%s||\n", row, game->map.tmp_line);
		//move first und last line;
		row++;
	}
	//check for first\last line
	if (!is_map_first_last_line(game))
		error_map_exit_game(game, "Map: Not valid first line");
	printf("row=%d||first_Line||%s||\n", row, game->map.tmp_line);
	// while(row < game->map.rows)
	// {
	// 	game->map.tmp_line = game->map.saved_map[row];
	// 	//move first und last line
		



		
	// 	free(game->map.tmp_line);
	// 	row++;
	// }
	
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
