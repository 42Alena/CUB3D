/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/30 21:50:27 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//__________ NOW.VERSION MAIN___________________________
int	main(int argc, char **argv)
{
	t_game	game;
	map_file_check(argc, argv); //NEW
	init_game_struct(&game);
	map_read_save(&game, argv[1]);


	mlx_set_cursor(game.mlx, mlx_create_cursor(game.textures.cursor));
	mlx_cursor_hook(game.mlx, cursor, &game);
	mlx_mouse_hook(game.mlx, mouse, &game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	system("/usr/bin/aplay -q ./music/main.wav &");
	system("/usr/bin/aplay -q ./music/hellothere.wav &");
	mlx_loop(game.mlx);
	free_mlx(&game);
	return (EXIT_SUCCESS);
}
//_______________________________________________________



//___________________MAIN for parsing and tests(ALENA)____________________________________

/* 
PRINTF FOR DEBUG
    
printf("string:|%s|\ntemp:|%s|\n", string, temp);
printf("%s, len_argv1=%d\n", argv[1], len_argv1);
printf("ENTERED HIER\n");
 */


///______________MAIN.WORKING HERE
// int	main(int argc, char **argv)
// {
// 	t_game	game;
	
// 	map_file_check(argc, argv);
// 	init_game_struct(&game);
// 	map_read_save(&game, argv[1]);
// 	// check_maps_characters(&game); //NOW

// 	/// MY CHECK PRINTS
// 	print_map(&game);
// 	print_map_structure(&game);

//__________________________________________
	

// 	//////from original MAIN
// 	//map_file_check(argc, argv);
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
// 	// free_mlx(&game);
// 	return (EXIT_SUCCESS);
// }






















// ////////was ORIGINAL MAIN not fool checked
// int	main(int argc, char **argv)
// {
// 	t_game	game;
// 	map_file_check(argc, argv); //NEW
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
// 	free_mlx(&game);
// 	return (EXIT_SUCCESS);
// }
