/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_prints_delete_for_intra.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:31:15 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/08 20:10:52 by akurmyza         ###   ########.fr       */
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
    
    if (game->map.saved_map == NULL)
        printf("\n MAP = NULL\n");
    else
    {
        int i = 0;
        printf("%d rows\n", game->map.rows);
        while (game->map.saved_map[i] && i < game->map.rows)
        {
            printf("||%s||\n", game->map.saved_map[i]);
            i++;
        }
    }
    // (void)game;
}

void print_map_structure(t_game *game)
{

    printf("\n=================Map_INFO_struct====================================\n");
    printf("cols: %d\n", game->map.cols);
    printf("rows: %d\n", game->map.rows);

	//___new
    printf("fd: %d\n", game->map.fd);
    printf("fd_open: %d\n", game->map.fd_open);
    printf("path: %s\n", game->map.file_path);
    printf("tmp_line: %s\n", game->map.tmp_line);
    printf("first_line: %d\n", game->map.first_line);
    printf("last_line: %d\n", game->map.last_line);

    printf("len_tmp_line: %d\n", game->map.len_tmp_line);

	//end_new

    printf("no_texture: %s\n", game->map.no_texture);
    printf("so_texture: %s\n", game->map.so_texture);
    printf("we_texture: %s\n", game->map.we_texture);
    printf("ea_texture: %s\n", game->map.ea_texture);
    printf("floor_color_str: %s\n", game->map.floor_color_str);
    printf("ceiling_color_str: %s\n", game->map.ceiling_color_str);
    printf("floor_color_uint: %d\n", game->map.floor_color_uint);
    printf("ceiling_color_uint: %d\n", game->map.ceiling_color_uint);
    printf("\n===========MAP_STRUCT==========================================\n");
    print_map(game);
    printf("\n================================================================\n");
}

