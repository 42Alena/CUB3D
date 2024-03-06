/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/06 15:53:15 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void ft_hook(void* param)
{
	t_game* game = param;
	// if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	// 	calculate(game->mlx);
	//calculate(game);
	(void)game;
}

int	main(int argc, char **argv)
{
	t_game game;

	check_input(argc, argv);
	init_game_struct(&game);
	check_map(&game, argv[1]);
	map_read(&game, argv[1]);
	/////////////Alena
	///to test map. Delete if not need
	//print_map(&game);
	//TODO:
	//check_maps_characters(&game);
	////////////////////////////////
	mlx_key_hook(game.mlx, key_press, &game);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
