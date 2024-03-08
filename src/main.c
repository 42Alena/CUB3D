/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/08 18:47:27 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	minimap(t_game *game)
{
	for (int y = game->window_height / 30; y < game->window_height / 5; y++)
	{
		for (int x = game->window_width / 30; x < game->window_width / 6; x++)
			mlx_put_pixel(game->textures.image, x, y, 0xFF000000);
	}
}

void	c3po(t_game *game)
{
	uint32_t	color;
	int			index;

	for (int y = 0; y < game->window_height; y++)
	{
		for (int x = 0; x < game->window_width; x++)
		{
			index = (y % 960) * 1920 + (x % 1920);
			color = game->textures.c3po[index];
			if((color & 0x00FFFFFF) != 0)
				mlx_put_pixel(game->textures.image, x, y, color);
		}
	}
}

void ft_hook(void *param)
{
	t_game* game = param;
	if (!game->is_menu)
	{
		if (game->textures.image)
			mlx_delete_image(game->mlx, game->textures.image);
		raycasting(game);
		//minimap(game);
		c3po(game);
		if (game->mouse.mouse_x > game->window_width / 1.1)
			rotation(game, ROTATION_SPEED / 2);
		else if (game->mouse.mouse_x < game->window_width * 1.1 - game->window_width)
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
	mlx_set_cursor(game.mlx, mlx_create_cursor(game.textures.cursor));
	mlx_cursor_hook(game.mlx, cursor, &game);
	mlx_mouse_hook(game.mlx, mouse, &game);
	mlx_key_hook(game.mlx, key_press, &game);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
