/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/07 13:52:47 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void ft_hook(void* param)
{
	t_game* game = param;
	if (game->image)
		mlx_delete_image(game->mlx, game->image);
	raycasting(game);
	for (int y = 0; y < WINDOW_HEIGHT / 5; y++)
	{
		for (int x = 0; x < WINDOW_WIDTH / 5; x++)
			mlx_put_pixel(game->image, x, y, 0xFFFFA500);
	}
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
