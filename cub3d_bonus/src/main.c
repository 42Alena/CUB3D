/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/16 12:28:39 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	timer(mlx_image_t *image, int height, int width, double time)
{
	int			y;
	int			x;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			if (x < 1700 - time * TIMER_SPEED && x > 1000 && y > 50 && y < 100)
			{
				if (time * TIMER_SPEED > 500)
					mlx_put_pixel(image, x, y, 0xFF000099);
				else
					mlx_put_pixel(image, x, y, 0xFF000044);
			}
		}
	}
}

void	game_over(mlx_image_t *end, mlx_t *mlx, int *dead_cursor)
{
	if (*dead_cursor == FALSE)
	{
		*dead_cursor = TRUE;
		system("pkill aplay");
		system("aplay -q ./music/no.wav &");
		system("aplay -q ./music/end.wav &");
		mlx_image_to_window(mlx, end, 0, 0);
	}
}

void	win_screen(mlx_image_t *congrats, mlx_t *mlx, int *dead_cursor)
{
	if (*dead_cursor == FALSE)
	{
		*dead_cursor = TRUE;
		system("pkill aplay");
		system("aplay -q ./music/yoda.wav &");
		mlx_image_to_window(mlx, congrats, 0, 0);
	}
}

void	ft_hook(void *param)
{
	t_game	*game;
	double	time;

	game = param;
	time = mlx_get_time();
	if (time * TIMER_SPEED > 700)
		game->end = TRUE;
	if (!game->is_menu && !game->is_settings \
	&& !game->is_win && !game->end)
	{
		if (game->textures.image)
			mlx_delete_image(game->mlx, game->textures.image);
		raycasting(game);
		key_press(game);
		minimap(game);
		timer(game->textures.image, game->window_height, game->window_width, time);
		if (game->mouse.mouse_x > game->window_width / 1.1)
			rotation(&game->player, ROTATION_SPEED / 2);
		else if (game->mouse.mouse_x < game->window_width * 1.1 \
		- game->window_width)
			rotation(&game->player, -ROTATION_SPEED / 2);
	}
	else if (game->end && !game->dead_cursor)
		game_over(game->textures.end, game->mlx, &game->dead_cursor);
	else if (game->is_win && !game->dead_cursor)
		win_screen(game->textures.congrats, game->mlx, &game->dead_cursor);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	check_input(argc, argv);
	init_game_struct(&game);
	check_map(&game, argv[1]);
	map_read(&game, argv[1]);
	//check_maps_characters(&game);
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
// int i = 0;
// int j = 0;
// while (game.map.saved_map[i])
// {
// 	j = 0;
// 	while (game.map.saved_map[i][j])
// 		printf("%c", game.map.saved_map[i][j++]);
// 	printf("\n");
// 	i++;
// }
