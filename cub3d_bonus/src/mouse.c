/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:20:47 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/04/27 12:04:27 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// buttons to pause music and turn of sound effects
static void	music_buttons(t_game *game)
{
	if (game->mouse.mouse_x > 1750 && game->mouse.mouse_x < 1800 \
	&& game->mouse.mouse_y > 50 && game->mouse.mouse_y < 100)
	{
		system("screen -S music_session -p 1 -X stuff ' ' ");
		if (game->music_is_paused == FALSE)
			game->music_is_paused = TRUE;
		else if (game->music_is_paused == TRUE)
			game->music_is_paused = FALSE;
	}
	else if (game->mouse.mouse_x > 1850 && game->mouse.mouse_x < 1900 \
	&& game->mouse.mouse_y > 50 && game->mouse.mouse_y < 100)
	{
		if (game->sound_effects_off == FALSE)
			game->sound_effects_off = TRUE;
		else if (game->sound_effects_off == TRUE)
			game->sound_effects_off = FALSE;
	}
}

/*
If left mouse button is pressed 
and the mouse is inside of the button-> launch the game
*/
void	mouse(mouse_key_t button, action_t action, \
modifier_key_t mods, void *param)
{
	t_game	*game;

	game = param;
	if (button != 0 || action != 0)
		return ;
	music_buttons(game);
	if (!game->is_menu && !game->is_settings)
		return ;
	if (game->mouse.mouse_x > 700 && game->mouse.mouse_x < 1200 \
	&& game->mouse.mouse_y > 265 && game->mouse.mouse_y < 360)
	{
		if (game->is_settings == TRUE && game->is_menu == TRUE)
			return (back_to_main_menu(game));
		launch_game(game);
	}
	settings(game);
	(void)mods;
}
/*
Calculate rotation speed based on the position of the mouse
The closer it is to the center the slower rotation speed is
If previous mouse position was faster then do not rotate view
*/

double	rotation_speed(t_game *game, int direction, int position, double xpos)
{
	double	speed;

	speed = 0;
	if (direction == RIGHT)
	{
		if (game->mouse.mouse_x > xpos || \
		game->mouse.mouse_x > game->window_width / 1.1)
			return (FALSE);
		speed = (ROTATION_SPEED / 10) / position;
		if (speed < ROTATION_SPEED / 30)
			speed *= 100;
	}
	else if (direction == LEFT)
	{
		if (game->mouse.mouse_x < xpos || \
		game->mouse.mouse_x < game->window_width * 1.1 - game->window_width)
			return (FALSE);
		speed = (-ROTATION_SPEED / 10) / position;
		if (speed < ROTATION_SPEED / 30)
			speed *= 100;
	}
	return (speed);
}

/*
If mouse is in the right part of the screen -> rotate right
If mouse is in the left part of the screen -> rotate left
*/
void	cursor(double xpos, double ypos, void *param)
{
	t_game	*game;
	double	speed;
	double	position;

	game = param;
	if (xpos > game->window_width / 2)
	{
		position = game->window_width - xpos;
		if (position <= 0)
			position = 1;
		speed = rotation_speed(game, RIGHT, position, xpos);
	}
	else
	{
		position = game->window_width + xpos - game->window_width;
		if (position <= 0)
			position = 1;
		speed = rotation_speed(game, LEFT, position, xpos);
	}
	game->mouse.mouse_y = ypos;
	game->mouse.mouse_x = xpos;
	if (speed != 0)
		rotation(&game->player, speed * 2);
}
