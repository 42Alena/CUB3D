/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/26 17:41:18 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_map_structure(&game);
	init_player_structure(&game);
	map_file_check(&game, argc, argv);
	map_file_read_save(&game);
	check_map(&game);
	init_game_struct(&game);
	mlx_set_cursor(game.mlx, mlx_create_cursor(game.textures.cursor));
	mlx_cursor_hook(game.mlx, cursor, &game);
	mlx_mouse_hook(game.mlx, mouse, &game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	system("/usr/bin/aplay -q ./music/main.wav &");
	system("/usr/bin/aplay -q ./music/hellothere.wav &");
	mlx_loop(game.mlx);
	free_game(&game);
	return (EXIT_SUCCESS);
}
