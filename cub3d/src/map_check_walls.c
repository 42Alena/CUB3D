/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:35 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/04 10:41:38 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/* first and last column can be only 1 or space 
111
101
 1111
    111
*/
// t_bool has_map_left_wall(t_game *game, int first_line, int last_line)
// {
//     int    i;
//     char *line;
//     int   flag_beginn;  

//     while (line[i])
//     {
//         i = 0;
//         line =  game->map.saved_map[col];
//         if (line[i] != '1' && line[i] != ' ')
//             printf("c = %c = FALSE\n\n", line [i]);
//             // return (FALSE);
//         i++;
//     }
//     printf("T R U E\n\n");
//     return (TRUE);
// }

/* first and last column can be only 1 or space */
// t_bool has_map_right_wall(t_game *game, int col)
// {
//     int i;
//     char *line;

//     i = 0;
//     line =  game->map.saved_map[col];
//     while (line[i])
//     {
//         if (line[i] != '1' && line[i] != ' ')
//             return (FALSE);
//             // printf("c = %c = FALSE\n\n", line [i]);
//         i++;
//     }
//     printf("T R U E\n\n");
//     return (TRUE);
// }




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

