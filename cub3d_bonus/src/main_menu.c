/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:39:14 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/04/27 12:11:04 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// draw two cirles (25 is radius) (75 is center_y) (1775 is center_x)
void	pause_music(t_game *game)
{
	int			x;
	int			y;
	uint32_t	color_music;
	uint32_t	color_sound_eff;

	color_music = 0x00FF00FF;
	color_sound_eff = 0x00FF00FF;
	if (game->music_is_paused)
		color_music = 0xFF808080;
	if (game->sound_effects_off)
		color_sound_eff = 0xFF808080;
	y = -1;
	while (++y < game->window_height)
	{
		x = -1;
		while (++x < game->window_width)
		{
			if ((x - 1775) * (x - 1775) + (y - 75) \
			* (y - 75) <= 25 * 25)
				ft_mlx_put_pixel(game->textures.image, x, y, color_music);
			else if ((x - 1875) * (x - 1875) + (y - 75) \
			* (y - 75) <= 25 * 25)
				ft_mlx_put_pixel(game->textures.image, x, y, color_sound_eff);
		}
	}
}

int	move_speed(t_game *game)
{
	if (game->mouse.mouse_x > 675 && game->mouse.mouse_x < 800 \
	&& game->mouse.mouse_y > 500 && game->mouse.mouse_y < 600)
	{
		game->move_speed = INITIAL_MOVE_SPEED / 2;
		mlx_image_to_window(game->mlx, game->textures.settings05, 0, 0);
	}
	else if (game->mouse.mouse_x > 870 && game->mouse.mouse_x < 1000 \
	&& game->mouse.mouse_y > 500 && game->mouse.mouse_y < 600)
	{
		game->move_speed = INITIAL_MOVE_SPEED;
		mlx_image_to_window(game->mlx, game->textures.settings1, 0, 0);
	}
	else if (game->mouse.mouse_x > 1075 && game->mouse.mouse_x < 1200 \
	&& game->mouse.mouse_y > 500 && game->mouse.mouse_y < 600)
	{
		game->move_speed = INITIAL_MOVE_SPEED * 2;
		mlx_image_to_window(game->mlx, game->textures.settings2, 0, 0);
	}
	else
		return (FALSE);
	return (TRUE);
}

void	settings(t_game *game)
{
	if (game->is_settings == FALSE && game->mouse.mouse_x > 700 \
	&& game->mouse.mouse_x < 1200 && game->mouse.mouse_y > 400 \
	&& game->mouse.mouse_y < 500)
	{
		game->is_settings = TRUE;
		mlx_image_to_window(game->mlx, game->textures.settings1, 0, 0);
	}
	if (game->is_settings == FALSE)
		return ;
	if (move_speed(game))
		if (!game->sound_effects_off)
			system("/usr/bin/aplay -q ./music/click.wav &");
}

void	back_to_main_menu(t_game *game)
{
	if (!game->sound_effects_off)
		system("/usr/bin/aplay -q ./music/click.wav &");
	mlx_image_to_window(game->mlx, game->textures.main_menu, 0, 0);
	game->is_settings = FALSE;
}

void	launch_game(t_game *game)
{
	if (game->is_settings == FALSE && !game->sound_effects_off)
		system("/usr/bin/aplay -q ./music/c3po.wav &");
	game->is_menu = FALSE;
	game->is_settings = FALSE;
	game->textures.main_menu->enabled = FALSE;
	game->textures.settings1->enabled = FALSE;
	game->textures.settings05->enabled = FALSE;
	game->textures.settings2->enabled = FALSE;
	if (!game->sound_effects_off)
		system("/usr/bin/aplay -q ./music/click.wav &");
}
