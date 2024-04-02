/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:36:10 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/02 01:50:51 by akurmyza         ###   ########.fr       */
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
    free(temp_line);
    return (TRUE);
}

/* first and last line can  */
t_bool is_map_walls_first_last_line(char *line)
{
    int i;
    int wall_count;
    char *temp_line;
    int length_temp_line;

    i = 0;
    wall_count = 0;
    temp_line = ft_strtrim(line, " ");
    length_temp_line = ft_strlen(temp_line);
    if (length_temp_line < 3)
    {
        free(temp_line);
        return (FALSE);
    }
    while (temp_line[i])
    {
        if (temp_line[i] == '1')
            wall_count += 1;
        else if (temp_line[i] != ' ')
        {
            free(temp_line);
            return (FALSE);
        }
        i++;
    }
    if (wall_count < 3)
    {
        free(temp_line);
        return (FALSE);
    }
    return (TRUE);
}

/*
it must beginn and end with 1   1
and have only map symbols
*/
t_bool is_map_middle_lines(t_game *game, int y)
{
    int x;
    char *temp_line;
    int length_temp_line;
    char c;

    x = 1;
    temp_line = ft_strtrim(game->map.saved_map[y], " ");
    length_temp_line = ft_strlen(temp_line);
    if (length_temp_line < 3)
        return (FALSE);
    if (temp_line[0] != 1 && temp_line[length_temp_line - 1] != 1)
        return (FALSE);
    while (temp_line[x] < length_temp_line)
    {
        c = temp_line[x];

        // if (c == ' ')
        // {
        //     //TODO: add check if  spacen inbetween outside walls 11 11
        //      //                                                     11
        //     //TODO: ADD HIER FLOOD FILL to check walls
        // }

        if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != 0 && c != 1)
            return (FALSE);

        if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
            check_save_player(game, c, x, y);
        x++;
    }
    return (TRUE);
}

//////////////////////////PRINTs FOR TEST MAPS//////////////////////
// TODO: move/delete before push
void print_map_pos_x_y(t_game *game)
{
    int y = 0;
    while (y < game->map.rows)
    {
        int x = 0;
        while (x < game->map.cols)
        {
            printf("(%d, %d): %c\n", y, x, game->map.saved_map[y][x]);
            x++;
        }
        y++;
    }
}

void print_map(t_game *game)
{
    int y = 0;
    while (y < game->map.rows)
    {
        int x = 0;
        while (x < game->map.cols)
        {
            printf("%c", game->map.saved_map[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
}

void print_map_structure(t_game *game)
{
    printf("Map Structure:\n");
    printf("cols: %d\n", game->map.cols);
    printf("rows: %d\n", game->map.rows);
    printf("no_texture: %s\n", game->map.no_texture);
    printf("so_texture: %s\n", game->map.so_texture);
    printf("we_texture: %s\n", game->map.we_texture);
    printf("ea_texture: %s\n", game->map.ea_texture);
    printf("floor_color_str: %s\n", game->map.floor_color_str);
    printf("ceiling_color_str: %s\n", game->map.ceiling_color_str);
    printf("floor_color_uint: %d\n", game->map.floor_color_uint);
    printf("ceiling_color_uint: %d\n", game->map.ceiling_color_uint);
}
//////////////
