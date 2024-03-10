/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/10 17:50:22 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_hook(void *param)
{
	t_game	*game;

	game = param;
	if (game->textures.image)
		mlx_delete_image(game->mlx, game->textures.image);
	raycasting(game);
	key_press(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_input(argc, argv);
	init_game_struct(&game);
	check_map(&game, argv[1]);
	map_read(&game, argv[1]);
	check_maps_characters(&game);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
