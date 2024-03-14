/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/14 06:42:48 by akurmyza         ###   ########.fr       */
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



/* 
	// printf("%s=%d\n", argv[1], len_argv1);
 */

int	main(int argc, char **argv)
{
	t_game	game;

	check_input(argc, argv);
	init_game_struct(&game);
	map_read_save(&game, argv[1]);
	is_valid_map(&game);


	///MY CHECK PRINTS
	print_map(&game);






	////////ORIGINAL
	// check_maps_characters(&game);
	//game->mlx = \
	// mlx_init(game->window_width, game->window_height, "CUB3D", true);
	// if (!game->mlx)
	// 	ft_error(game, "Could not initialize MLX");
	// mlx_loop_hook(game.mlx, ft_hook, &game);
	// mlx_loop(game.mlx);
	// mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}



//OLD __VERSION

// int	main(int argc, char **argv)
// {
// 	t_game	game;
// 	char	**map;

// 	map = NULL;
// 	check_input(argc, argv);

// 	//ADD HIER VERY GOOD CHECK MAP BEFORE INITIALIZING ALL STRUCTURES


// 	//
// 	// 
// 	//PROBABLY i can direct save **map i struct, after nitilizing
// 	init_game_struct(&game);
// 	get_size_map(&game, argv[1]);
// 	map_read_save(&game, argv[1]);
// 	check_maps_characters(&game);
// 	mlx_loop_hook(game.mlx, ft_hook, &game);
// 	mlx_loop(game.mlx);
// 	mlx_terminate(game.mlx);
// 	return (EXIT_SUCCESS);
// }
