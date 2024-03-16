/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:20:47 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/16 12:15:24 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	settings(t_game *game)
{
	if (game->is_settings == FALSE && game->mouse.mouse_x > 700 \
	&& game->mouse.mouse_x < 1200 && game->mouse.mouse_y > 400 && game->mouse.mouse_y < 500)
	{
		game->is_settings = TRUE;
		mlx_image_to_window(game->mlx, game->textures.settings1, 0, 0);
		system("/usr/bin/aplay -q ./music/click.wav &");
	}
	if (game->is_settings == FALSE)
		return ;
	if (game->mouse.mouse_x > 675 && game->mouse.mouse_x < 800 \
	&& game->mouse.mouse_y > 500 && game->mouse.mouse_y < 600)
	{
		game->move_speed = INITIAL_MOVE_SPEED / 2;
		mlx_image_to_window(game->mlx, game->textures.settings05, 0, 0);
		system("/usr/bin/aplay -q ./music/click.wav &");
	}
	else if (game->mouse.mouse_x > 870 && game->mouse.mouse_x < 1000 \
	&& game->mouse.mouse_y > 500 && game->mouse.mouse_y < 600)
	{
		game->move_speed = INITIAL_MOVE_SPEED;
		mlx_image_to_window(game->mlx, game->textures.settings1, 0, 0);
		system("/usr/bin/aplay -q ./music/click.wav &");
	}
	else if (game->mouse.mouse_x > 1075 && game->mouse.mouse_x < 1200 \
	&& game->mouse.mouse_y > 500 && game->mouse.mouse_y < 600)
	{
		game->move_speed = INITIAL_MOVE_SPEED * 2;
		mlx_image_to_window(game->mlx, game->textures.settings2, 0, 0);
		system("/usr/bin/aplay -q ./music/click.wav &");
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
	if (game->mouse.mouse_x > 700 && game->mouse.mouse_x < 1200 \
	&& game->mouse.mouse_y > 265 && game->mouse.mouse_y < 360)
	{
		if (game->is_settings == TRUE && game->is_menu == TRUE)
		{
			system("/usr/bin/aplay -q ./music/click.wav &");
			mlx_image_to_window(game->mlx, game->textures.main_menu, 0, 0);
			game->is_settings = FALSE;
			return ;
		}
		if (game->is_settings == FALSE)
			system("/usr/bin/aplay -q ./music/c3po.wav &");
		game->is_menu = FALSE;
		game->is_settings = FALSE;
		game->textures.main_menu->enabled = FALSE;
		game->textures.settings1->enabled = FALSE;
		game->textures.settings05->enabled = FALSE;
		game->textures.settings2->enabled = FALSE;
		system("/usr/bin/aplay -q ./music/click.wav &");
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
