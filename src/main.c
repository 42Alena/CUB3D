/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/08 11:20:38 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	minimap(t_game *game)
{
	for (int y = WINDOW_HEIGHT / 30; y < WINDOW_HEIGHT / 5; y++)
	{
		for (int x = WINDOW_WIDTH / 30; x < WINDOW_WIDTH / 6; x++)
			mlx_put_pixel(game->image, x, y, 0xFF000000);
	}
}

void ft_hook(void *param)
{
	t_game* game = param;
	if (!game->is_menu)
	{
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		raycasting(game);
		minimap(game);
		if (game->mouse.mouse_x > WINDOW_WIDTH / 1.1)
			rotation(game, ROTATION_SPEED / 2);
		else if (game->mouse.mouse_x < WINDOW_WIDTH * 1.1 - WINDOW_WIDTH)
			rotation(game, -ROTATION_SPEED / 2);
	}
}

int	main(int argc, char **argv)
{
	t_game game;

	check_input(argc, argv);
	init_game_struct(&game);
	check_map(&game, argv[1]);
	map_read(&game, argv[1]);
	check_maps_characters(&game);
	/////////////Alena
	///to test map. Delete if not need
	//print_map(&game);
	//TODO:
	//check walls
	////////////////////////////////
	mlx_cursor_hook(game.mlx, cursor, &game);
	mlx_mouse_hook(game.mlx, mouse, &game);
	mlx_key_hook(game.mlx, key_press, &game);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
