/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 12:25:25 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// int32_t	main(void)
int32_t	main(int argc, char **argv)
{
	t_game game;

	check_input(argc, argv);
	init_game_struct(&game);
	/////////from so_long////////////////
	//TODO:
	check_map(&game, argv[1]);
	//TODO:
	map_read(&game, argv[1]);
	//print_map(&game);
	
	//TODO:
	//check_maps_characters(&game);



	// game_init(&game);
	
	// mlx_key_hook(game.mlx, key_press, &game);
	// mlx_loop_hook(game.mlx, ft_hook, &game);
	// mlx_loop(game.mlx);
	// mlx_terminate(game.mlx);
	// return (EXIT_SUCCESS);
}
