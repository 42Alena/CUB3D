/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:35 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/09 16:33:02 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


t_bool is_empty_line(char *line)
{
    int i;
    char *temp_line;

    i = 0;
    if (line == NULL)
        return (TRUE);
    temp_line = ft_strtrim(line, " ");
    if (temp_line == NULL)
        return (TRUE);
    while (temp_line[i])
    {
        if (temp_line[i] != ' ' && temp_line[i] != '\n')
        {
            free(temp_line);
            return (FALSE);
        }
        i++;
    }
    if (temp_line != NULL)
        free(temp_line);
    return (TRUE);
}

/* first and last line can  */
t_bool is_map_first_last_line(t_game *game)
{
    int x;
    // char *line;

    x = 0;
    // line =  game->map.tmp_line;
    while (game->map.tmp_line[x])
    {
        if (game->map.tmp_line[x] != '1' && game->map.tmp_line[x] != ' ')
            return (FALSE);
        x++;
    }
    return (TRUE);
}

/*
it must beginn and end with 1   1
and have only map symbols
*/
t_bool is_map_middle_lines(t_game *game)
{
    int x;
    char *line;
    int end;
    char c;
    int count_player;

    line = game->map.tmp_line;
    x = 0;
    end = ft_strlen(line) - 1;
    count_player = 0;
    while(line[x] && line[x] == ' ')
        x++;
    while(line[end] && line[end] == ' ' && end >= x)

    if (line[x] != 1 && line[end] != 1)
        error_map_exit_game(game, "Map: middlerow: no outside wall");
    while (line[x] < end)
    {
        c = line[x];
        //if (c == '0') TODO:ADD CHECK for spaces with 0

        if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != 0 && c != 1 && c!= ' ')
            error_map_exit_game(game, "Map: failed wall");
        //TODO: add check player
        if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        {
            count_player += 1;
            if (count_player > 1)
                error_map_exit_game(game, "Map: failed wall");
        }
        //     check_save_player(game, c, x, y);
        x++;
    }
    // if (line[x] != 1 && line[len - 1] != 1)
    //     error_map_exit_game(game, "Map: middlerow: no outside wall");
    return (TRUE);
}



/*
it must beginn and end with 1   1
and have only map symbols
*/
// t_bool is_map_middle_lines(t_game *game, int y)
// {
//     int x;
//     char *temp_line;
//     int length_temp_line;
//     char c;

//     x = 1;
//     temp_line = ft_strtrim(game->map.saved_map[y], " ");
//     length_temp_line = ft_strlen(temp_line);
//     if (length_temp_line < 3)
//         return (FALSE);
//     if (temp_line[0] != 1 && temp_line[length_temp_line - 1] != 1)
//         return (FALSE);
//     while (temp_line[x] < length_temp_line)
//     {
//         c = temp_line[x];

//         // if (c == ' ')
//         // {
//         //     //TODO: add check if  spacen inbetween outside walls 11 11
//         //      //                                                     11
//         //     //TODO: ADD HIER FLOOD FILL to check walls
//         // }

//         if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != 0 && c != 1)
//             return (FALSE);

//         if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
//             check_save_player(game, c, x, y);
//         x++;
//     }
//     return (TRUE);
// }



///_1.VERSION
// /* first and last line can  */
// t_bool is_map_first_last_line(t_game *game, int row)
// {
//     int i;
//     char *line;

//     i = 0;
//     line =  game->map.saved_map[row];
//     while (line[i])
//     {
//         if (line[i] != '1' && line[i] != ' ')
//             return (FALSE);
//         i++;
//     }
//     return (TRUE);
// }
