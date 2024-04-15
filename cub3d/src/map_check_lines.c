/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:35 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/14 11:05:31 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_bool is_empty_tmp_line(t_game *game)
{
    int i;

    i = 0;
    if (game->map.tmp_line == NULL)
        return (TRUE);
    while (game->map.tmp_line[i])
    {
        if (game->map.tmp_line[i] != ' ' && game->map.tmp_line[i]!= '\n')
            return (FALSE);
        i++;
    }
    // printf("is_empty_tmp_line||%s|| = TRUE\n", game->map.tmp_line);
    return (TRUE);
}

//WORKING HERE;search for empty lines in map
//save player in struct
void map_check_middle_lines(t_game *game)
{
	int row;

	row = game->map.first_line + 1;
	while (row < game->map.last_line)
	{
		game->map.tmp_line = game->map.saved_map[row];
		if (is_empty_tmp_line(game))
			error_map_exit_game(game, "Map: empty line");
        check_maps_characters(game, row);
		row++;
		printf(" middleLIne=%d||%s||\n", row, game->map.tmp_line);	
	}
	// printf(" TMPline=%d||%s||\n", row, game->map.tmp_line);
	game->map.tmp_line = NULL;
	// printf(" TMPline=%d||%s||\n", row, game->map.tmp_line);
}


void check_floor(t_game *game, char c, int x, int y)
{
    //CHANGE ALL FOR 0
	printf("player|%c|, x=%d, y= %d\n", c,x, y);
	printf("x-1=|%c|, x+1=|%c|\n",game->map.saved_map[y][x - 1], game->map.saved_map[y][x + 1] );
	printf("y-1=|%c|, y+1=|%c|\n",game->map.saved_map[y - 1][x], game->map.saved_map[y + 1][x] );
	if (game->map.saved_map[y][x - 1] && game->map.saved_map[y][x + 1] &&\
		game->map.saved_map[y - 1][x] && game->map.saved_map[y + 1][x])
	{
		if	(game->map.tmp_line[x - 1] != '0' && game->map.tmp_line[x - 1] != '1')
			error_map_exit_game(game, "Map: Player's position is not valid");
		printf("ENTERED\n");
		if ((game->map.tmp_line[x + 1] != '0' && game->map.tmp_line[x + 1] != '1'))
			error_map_exit_game(game, "Map: Player's position is not valid");
		if (game->map.tmp_line[y - 1] != '0' && game->map.tmp_line[y - 1] != '1')
			error_map_exit_game(game, "Map: Player's position is not valid");
		if (game->map.tmp_line[y + 1] != '0' && game->map.tmp_line[y + 1] != '1')
			error_map_exit_game(game, "Map: Player's position is not valid");	
	}
	else
		error_map_exit_game(game, "Map: Player's position is not valid");	
	save_player_struct(game, x, y);
}
