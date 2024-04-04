/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:36:10 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/04 09:55:20 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_bool is_substring(char *substring, char *string, int start, int len)
{
    char *temp;

    temp = ft_substr(string, start, len);
    if (temp == NULL)
        return FALSE;
    if (ft_strncmp(substring, temp, len) != 0)
    {
        // TODO: change to ft_free_return
        free(temp);
        return FALSE;
    }
    if (temp != NULL)
        free(temp);
    return TRUE;
}

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
t_bool is_map_first_last_line(t_game *game, int row)
{
    int i;
    char *line;

    i = 0;
    line =  game->map.saved_map[row];
    while (line[i])
    {
        if (line[i] != '1' && line[i] != ' ')
            printf("c = %c = FALSE\n\n", line [i]);
            // return (FALSE);
        i++;
    }
    printf("T R U E\n\n");
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



//FIRST VERSION
// /* first and last line can  */
// t_bool is_map_walls_first_last_line(char *line)
// {
//     int i;
//     int wall_count;
//     char *temp_line;
//     int length_temp_line;

//     i = 0;
//     wall_count = 0;
//     temp_line = ft_strtrim(line, " ");
//     length_temp_line = ft_strlen(temp_line);


//     while (temp_line[i])
//     {
//         if (temp_line[i] == '1')
//             wall_count += 1;
//         else if (temp_line[i] != ' ')
//         {
//             free(temp_line);
//             return (FALSE);
//         }
//         i++;
//     }
//     if (wall_count < 3)
//     {
//         free(temp_line);
//         return (FALSE);
//     }
//     return (TRUE);
// }
