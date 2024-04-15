/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/15 12:10:00 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

///___NOW____________MAIN.WORKING HERE
int main(int argc, char **argv)
{
	t_game game;

	init_map_structure(&game);
	init_player_structure(&game);
	
	map_file_check(&game, argc, argv);
	printf("MAIN => I AM HERE!;)\n");
	map_file_read_save(&game);
	check_map(&game); 
	// check_maps_characters(&game); //from map_check.c
	// print_map(&game);
	// free_double_char_pointer_array(&game.map.saved_map);
	
	//____TEST_____________________
	// print_map(&game);

	// print_map(&game);
	print_map_structure(&game);
	// printf("_____MAP_______\n\n");
	// print_map(&game);
	// printf("_____END_MAP_______\n\n");
	// printf("_____MAP_STRUCT______\n\n");
	// print_map_structure(&game);
	// printf("_____END_MAP_STRUCT______\n\n");
	//_____END_TEST______________

	// free_map_struct(&game);
	// print_map_structure(&game);
	return (EXIT_SUCCESS);
}

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





//__________________________________________

// 	//////from 0.MAIN
// 	//map_file_check(game, argc, argv);
// 	// init_game_struct(&game);
// 	// check_map(&game, argv[1]);
// 	// map_read(&game, argv[1]);
// 	// mlx_set_cursor(game.mlx, mlx_create_cursor(game.textures.cursor));
// 	// mlx_cursor_hook(game.mlx, cursor, &game);
// 	// mlx_mouse_hook(game.mlx, mouse, &game);
// 	// mlx_key_hook(game.mlx, key_hook, &game);
// 	// mlx_loop_hook(game.mlx, ft_hook, &game);
// 	// system("/usr/bin/aplay -q ./music/main.wav &");
// 	// system("/usr/bin/aplay -q ./music/hellothere.wav &");
// 	// mlx_loop(game.mlx);
// 	// free_game(&game);
// 	return (EXIT_SUCCESS);
// }






//////////////////////////////////////////////////
//////////////////////////////////////////

//_____ 1.VERSION_____MAIN___________________________

// int	main(int argc, char **argv)
// {
// 	t_game	game;
// 	map_file_check(game, argc, argv); //NEW
// 	init_map_structure(&game);
// 	init_player_structure(&game);
// 	map_file_read_save(&game, argv[1]);
// 	save_map_textures_and_colors(&game);

// 	init_game_struct(&game);
// 	mlx_set_cursor(game.mlx, mlx_create_cursor(game.textures.cursor));
// 	mlx_cursor_hook(game.mlx, cursor, &game);
// 	mlx_mouse_hook(game.mlx, mouse, &game);
// 	mlx_key_hook(game.mlx, key_hook, &game);
// 	mlx_loop_hook(game.mlx, ft_hook, &game);
// 	system("/usr/bin/aplay -q ./music/main.wav &");
// 	system("/usr/bin/aplay -q ./music/hellothere.wav &");
// 	mlx_loop(game.mlx);
// 	free_game(&game);
// 	return (EXIT_SUCCESS);
// }

//_______________________________________________________

///////////////////////////////////////////////////////
//////////////////////////////////////////////////////








//_____ 0.VERSION_____MAIN___________________________
// ////////was ORIGINAL MAIN not fool checked
// int	main(int argc, char **argv)
// {
// 	t_game	game;
// 	map_file_check(game, argc, argv); //NEW
// 	// check_input(argc, argv); //deleted
// 	init_game_struct(&game);
// 	//check_map(&game, argv[1]);  //deleted?
// 	//map_read(&game, argv[1]); //deleted?
// 	mlx_set_cursor(game.mlx, mlx_create_cursor(game.textures.cursor));
// 	mlx_cursor_hook(game.mlx, cursor, &game);
// 	mlx_mouse_hook(game.mlx, mouse, &game);
// 	mlx_key_hook(game.mlx, key_hook, &game);
// 	mlx_loop_hook(game.mlx, ft_hook, &game);
// 	system("/usr/bin/aplay -q ./music/main.wav &");
// 	system("/usr/bin/aplay -q ./music/hellothere.wav &");
// 	mlx_loop(game.mlx);
// 	free_game(&game);
// 	return (EXIT_SUCCESS);
// }
