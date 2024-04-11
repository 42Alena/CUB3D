/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:35 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/11 14:45:17 by akurmyza         ###   ########.fr       */
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


t_bool is_empty_tmp_line(t_game *game)
{
    int i;

    i = 0;

    if (game->map.tmp_line == NULL)
    {
        // printf("is_empty_tmp_line||%s|| = TRUE\n", game->map.tmp_line);
        return (TRUE);
    }
    while (game->map.tmp_line[i])
    {
        if (game->map.tmp_line[i] != ' ')
            return (FALSE);

        i++;
    }
    
    // printf("is_empty_tmp_line||%s|| = TRUE\n", game->map.tmp_line);
    return (TRUE);
}

/* first and last line can  */
t_bool is_map_first_last_line(t_game *game)
{
    int x;
    int ones;
    // char *line;

    x = 0;
    ones = 0;
    // line =  game->map.tmp_line;
    while (game->map.tmp_line[x])
    {
        if (game->map.tmp_line[x] == '1')
            ones += 1;
         else if(game->map.tmp_line[x] != ' ')
            return (FALSE);
        x++;
    }
    if (ones == 0)
        return (FALSE);
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
    int len;
    char c;

    line = ft_strtrim(game->map.tmp_line, " ");
    len = ft_strlen(line);
    x = 0;

    if (len > 0 && line[0] != '1' && line[len - 1] != '1')
    {
        printf("line[x]: %c,\n", line[x]);
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
