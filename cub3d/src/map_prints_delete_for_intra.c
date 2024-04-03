/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_prints_delete_for_intra.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:31:15 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/03 19:31:25 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
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
