/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/09 16:00:42 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	minimap(t_game *game)
{
	int	y;
	int	x;

	y = game->window_height / 30;
	while (y < game->window_height / 5)
	{
		x = game->window_width / 30;
		while (x < game->window_width / 6)
			mlx_put_pixel(game->textures.image, x++, y, 0xFF000000);
		y++;
	}
}

void	c3po(t_game *game)
{
	uint32_t	color;
	int			index;
	int			y;
	int			x;

	y = 0;
	while (y < game->window_height)
	{
		x = 0;
		while (x < game->window_width)
		{
			index = (y % 960) * 1920 + (x % 1920);
			color = game->textures.bottom_image[index];
			if ((color & 0x00FFFFFF) != 0)
				mlx_put_pixel(game->textures.image, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_hook(void *param)
{
	t_game	*game;

	game = param;
	if (!game->is_menu)
	{
		if (game->textures.image)
			mlx_delete_image(game->mlx, game->textures.image);
		raycasting(game);
		minimap(game);
		c3po(game);
		if (game->mouse.mouse_x > game->window_width / 1.1)
			rotation(game, ROTATION_SPEED / 2);
		else if (game->mouse.mouse_x < game->window_width * 1.1 \
		- game->window_width)
			rotation(game, -ROTATION_SPEED / 2);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_input(argc, argv);
	init_game_struct(&game);
	check_map(&game, argv[1]);
	map_read(&game, argv[1]);
	check_maps_characters(&game);
	mlx_set_cursor(game.mlx, mlx_create_cursor(game.textures.cursor));
	mlx_cursor_hook(game.mlx, cursor, &game);
	mlx_mouse_hook(game.mlx, mouse, &game);
	mlx_key_hook(game.mlx, key_press, &game);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}

/////////////Alena
	///to test map. Delete if not need
	//print_map(&game);
	//TODO:
	//check walls
	////////////////////////////////