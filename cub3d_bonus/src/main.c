/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/14 13:16:07 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	timer(t_game *game, double time)
{
	uint32_t	color;
	int			index;
	int			y;
	int			x;

	y = -1;
	if (time * TIMER_SPEED > 700)
		game->end = TRUE;
	while (++y < game->window_height)
	{
		x = -1;
		while (++x < game->window_width)
		{
			index = (y % 960) * 1920 + (x % 1920);
			color = game->textures.bottom_image[index];
			if (x < 1700 - time * TIMER_SPEED && x > 1000 && y > 850 && y < 920)
			{
				if (time * TIMER_SPEED > 500)
					mlx_put_pixel(game->textures.image, x, y, 0xFF000099);
				else
					mlx_put_pixel(game->textures.image, x, y, 0xFF000044);
			}
			else if ((color & 0x00FFFFFF) != 0)
				mlx_put_pixel(game->textures.image, x, y, color);
		}
	}
}

void	game_over(t_game *game)
{
	if (game->dead_cursor == FALSE)
	{
		game->dead_cursor = TRUE;
		system("pkill aplay");
		system("aplay -q ./music/no.wav &");
		system("aplay -q ./music/end.wav &");
		mlx_image_to_window(game->mlx, game->textures.end, 0, 0);
	}
}

void	win_screen(t_game *game)
{
	if (game->dead_cursor == FALSE)
	{
		game->dead_cursor = TRUE;
		system("pkill aplay");
		system("aplay -q ./music/yoda.wav &");
		mlx_image_to_window(game->mlx, game->textures.congrats, 0, 0);
	}
}

void	ft_hook(void *param)
{
	t_game	*game;
	double	time;

	game = param;
	time = mlx_get_time();
	if (game->end)
		game_over(game);
	if (game->is_win)
		win_screen(game);
	else if (!game->is_menu && !game->is_settings)
	{
		if (game->textures.image)
			mlx_delete_image(game->mlx, game->textures.image);
		raycasting(game);
		if (game->is_map)
			bigmap(game);
		else
			minimap(game);
		timer(game, time);
		key_press(game);
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
