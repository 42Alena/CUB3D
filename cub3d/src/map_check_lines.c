/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:35 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/14 07:49:58 by akurmyza         ###   ########.fr       */
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
		row++;
		printf(" middleLIne=%d||%s||\n", row, game->map.tmp_line);	
	}
	// printf(" TMPline=%d||%s||\n", row, game->map.tmp_line);
	game->map.tmp_line = NULL;
	// printf(" TMPline=%d||%s||\n", row, game->map.tmp_line);
}
