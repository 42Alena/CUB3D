/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:35 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/13 15:30:43 by akurmyza         ###   ########.fr       */
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

/* first and last line can be  one or space*/
void walls_check_save_in_struct(t_game *game)
{
	// int row;

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

t_bool is_map_north_south_wall(t_game *game)
{
    int x;
    int ones;

    x = 0;
    ones = 0;
    while (game->map.tmp_line[x])
    {
        if (game->map.tmp_line[x] == '1')
            ones += 1;
         else if(game->map.tmp_line[x] != ' ')
            error_map_exit_game(game, "Map: no south/north wall");
        x++;
    }
    if (ones == 0)
        return (FALSE);
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
        if ((game->map.saved_map[row][0] != '1') ||\
            (game->map.saved_map[row][game->map.cols - 1] != '1') ||\
            ((game->map.saved_map[row][0] != ' ') ||\
            (game->map.saved_map[row][game->map.cols - 1] != ' ')))
            error_map_exit_game(game, "Map: not valid symbol in east or ost wall");
		row++;
		printf(" EMPTYLIne=%d||%s||\n", row, game->map.tmp_line);	
		printf("[[0]= ||%c||||[game->map.cols - 1]= ||%c||\n", game->map.saved_map[row][0], game->map.saved_map[row][game->map.cols - 1]);	
	}
	// printf(" TMPline=%d||%s||\n", row, game->map.tmp_line);
	game->map.tmp_line = NULL;
	// printf(" TMPline=%d||%s||\n", row, game->map.tmp_line);
}

//check fo we/ost walls if 1.or last symbol  !' ' and ! '1'

/*
it must beginn and end with 1   1
and have only map symbols
*/
t_bool old_is_map_middle_lines(t_game *game)
{
    int x;
    char *line;
    int len;
    char c;

    line = ft_strtrim(game->map.tmp_line, " ");
    len = ft_strlen(line);
    x = 0;

    if (len > 0 && line[0] != '1' && line[len - 1] != '1')
    {
        printf("line[x]: %c,\n", line[x]);
        if (line)
            free(line);
        error_map_exit_game(game, "Map: middlerow: no outside wall");
    }
    while (line[x])
    {
        c = line[x];
        //if (c == '0') TODO:ADD CHECK for spaces with 0

        if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != '0' && c != '1' && c != ' ')
        {
            printf("line[x]: %c,\n", line[x]);
            error_map_exit_game(game, "Map: Not allowed symbol");
        }
        //TODO: add check player
        // if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        // {
        //     game->map.count_player += 1;
        //     if (count_player > 1)
        //         error_map_exit_game(game, "Map: failed wall");
        // }
        //     check_save_player(game, c, x, y);
        x++;
    }
    // if (line[x] != 1 && line[len - 1] != 1)
    //     error_map_exit_game(game, "Map: middlerow: no outside wall");
    return (TRUE);
}
