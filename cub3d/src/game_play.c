/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:37:23 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/27 11:38:58 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// draw a cirle (25 is radius)
void pause_music(mlx_image_t *image, int height, int width, int is_paused)
{
	int			x;
	int			y;
	int			center_x;
	int			center_y;
	uint32_t	color;

	color = 0x00FF00FF;
	if (is_paused)
		color = 0xFF808080;
	center_x = 1775;
	center_y = 75;
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			if ((x - center_x) * (x - center_x) + (y - center_y) \
			* (y - center_y) <= 25 * 25)
				ft_mlx_put_pixel(image, x, y,  color);
		}
	}
}

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
					ft_mlx_put_pixel(image, x, y, 0xFF000099);
				else
					ft_mlx_put_pixel(image, x, y, 0xFF000044);
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

void	gameplay(t_game *game, double time)
{
	if (game->textures.image)
		mlx_delete_image(game->mlx, game->textures.image);
	raycasting(game);
	draw_sprites(game);
	key_press(game, time);
	minimap(game);
	timer(game->textures.image, game->window_height, game->window_width, time);
	pause_music(game->textures.image, game->window_height, game->window_width, game->music_is_paused);
	if (game->mouse.mouse_x > game->window_width / 1.1)
		rotation(&game->player, ROTATION_SPEED / 2);
	else if (game->mouse.mouse_x < game->window_width * 1.1 \
	- game->window_width)
		rotation(&game->player, -ROTATION_SPEED / 2);
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
		gameplay(game, time);
	else if (game->end && !game->dead_cursor)
		game_over(game->textures.end, game->mlx, &game->dead_cursor);
	else if (game->is_win && !game->dead_cursor)
		win_screen(game->textures.congrats, game->mlx, &game->dead_cursor);
}
