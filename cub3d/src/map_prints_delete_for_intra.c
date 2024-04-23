/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_prints_delete_for_intra.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:31:15 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/23 19:23:01 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
// 		printf("gnl:||%d||%s||\n", game->map.rows, game->map.tmp_line);
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
        while (game->map.saved_map[i] && i < game->map.rows)
        {
            printf("||%s||\n", game->map.saved_map[i]);
            i++;
        }
    }
}

void print_map_structure(t_game *game)
{

    printf("\n=================Map_INFO_struct====================================\n");
    printf("cols: %d\n", game->map.cols);
    printf("rows: %d\n", game->map.rows);

    //___new
    printf("fd: %d\n", game->map.fd);
    printf("fd_open: %d\n", game->map.fd_open);
    printf("map_path: %s\n", game->map.file_path);
    printf("tmp_line: %s\n", game->map.tmp_line);
    printf("first_line: %d\n", game->map.first_line);
    printf("last_line: %d\n", game->map.last_line);
    printf("len_tmp_line: %d\n", game->map.len_tmp_line);
    // end_new
    
    printf("no_texture: %s\n", game->map.no_texture);
    printf("so_texture: %s\n", game->map.so_texture);
    printf("we_texture: %s\n", game->map.we_texture);
    printf("ea_texture: %s\n", game->map.ea_texture);
    printf("floor_color_str: %s\n", game->map.floor_color_str);
    printf("ceiling_color_str: %s\n", game->map.ceiling_color_str);
    printf("floor_color_uint: %d\n", game->map.floor_color_uint);
    printf("ceiling_color_uint: %d\n", game->map.ceiling_color_uint);
    printf("\n++++++++++++++++++++++PLAYER+++++++++++++++++\n");
    printf("count player: %d\n",game->player.count);
    printf("map_start_dir: %c\n",game->player.map_start_dir);
    printf("row player: %d\n",game->player.row);
    printf("col player: %d\n",game->player.col);
    printf("pos_x: %f\n",game->player.pos_x);
    printf("pos_y: %f\n",game->player.pos_y);
    printf("dir_x: %f\n",game->player.dir_x);
    printf("dir_y: %f\n",game->player.dir_y);   
    printf("plane_x: %f\n",game->player.plane_x);
    printf("plane_y: %f\n",game->player.plane_y);
    printf("\n++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n===========MAP_STRUCT==========================================\n");
    print_map(game);
    printf("================================================================\n");
}

/* 
	printf("player|%c|, x=%d, y= %d\n", game->player.map_start_dir,row, col);
	printf("col-1=|%c|, col+1=|%c|\n",game->map.saved_map[row][col - 1], game->map.saved_map[row][col + 1] );
	printf("row-1=|%c|, row+1=|%c|\n",game->map.saved_map[row - 1][col], game->map.saved_map[row + 1][col] );
	
 */




//_____________TESTS______MAIN for parsing and tests(ALENA)____________________________________
/*
./cub3D ./maps/empty.cub

make && make clean &&  ./cub3D ./maps/empty.cub
 */
/*
PRINTF FOR DEBUG
// 	/// MY CHECK PRINTS
// 	print_map(&game);
// 	print_map_structure(&game);

/////////////////debug
//	printf("cols:%d, rows: %d", game->map.cols, game->map.rows);
////////////////end debug

printf("string:|%s|\ntemp:|%s|\n", string, temp);
printf("%s, len_argv1=%d\n", argv[1], len_argv1);
printf("ENTERED HIER\n");
 */



//____Alena____FOR TESTS
// int main(int argc, char **argv)
// {
// 	t_game game;

// 	init_map_structure(&game);
// 	init_player_structure(&game);

// 	map_file_check(&game, argc, argv);
// 	map_file_read_save(&game);
// 	check_map(&game);

	//____TEST_____________________
	// print_map(&game);

	// print_map(&game);
	// print_map_structure(&game);
	// printf("_____MAP_______\n\n");
	// print_map(&game);
	// printf("_____END_MAP_______\n\n");
	// printf("_____MAP_STRUCT______\n\n");
	// print_map_structure(&game);
	// printf("_____END_MAP_STRUCT______\n\n");
	//_____END_TEST______________

	// free_map_struct(&game);
	// print_map_structure(&game);
// 	return (EXIT_SUCCESS);
// }

//---!!!!!--------CONTINUE OF MAIN --------------------

//  init_game_struct(&game);
// mlx_set_cursor(game.mlx, mlx_create_cursor(game.textures.cursor));
// mlx_cursor_hook(game.mlx, cursor, &game);
// mlx_mouse_hook(game.mlx, mouse, &game);
// mlx_key_hook(game.mlx, key_hook, &game);
// mlx_loop_hook(game.mlx, ft_hook, &game);
// system("/usr/bin/aplay -q ./music/main.wav &");
// system("/usr/bin/aplay -q ./music/hellothere.wav &");
// mlx_loop(game.mlx);
// free_game(&game);
// 	return (EXIT_SUCCESS);
// }
