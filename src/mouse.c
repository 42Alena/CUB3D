/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:20:47 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/08 12:36:22 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
If left mouse button is pressed and the mouse is inside of the button-> launch the game
*/
void	mouse(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_game	*game;

	game = param;
	if (button == 0 && action == 0 &&\
	game->mouse.mouse_x > 700 && game->mouse.mouse_x < 1200\
	&& game->mouse.mouse_y > 265 && game->mouse.mouse_y < 360)
	{
		game->is_menu = FALSE;
		mlx_delete_image(game->mlx, game->main_menu);
	}
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
		if (game->mouse.mouse_x > xpos ||\
		game->mouse.mouse_x > WINDOW_WIDTH / 1.1)
			return (FALSE);
		speed = (ROTATION_SPEED / 10) / position;
		if (speed < ROTATION_SPEED / 30)
			speed *= 100;
	}
	else if (direction == LEFT)
	{
		if (game->mouse.mouse_x < xpos ||\
		game->mouse.mouse_x < WINDOW_WIDTH * 1.1 - WINDOW_WIDTH)
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
	t_game *game;
	double	speed;
	double	position;

	game = param;
	if (xpos > WINDOW_WIDTH / 2)
	{
		position = WINDOW_WIDTH - xpos;
		if (position <= 0)
			position = 1;
		speed = rotation_speed(game, RIGHT, position, xpos);
	}
	else
	{
		position = WINDOW_WIDTH + xpos - WINDOW_WIDTH;
		if (position <= 0)
			position = 1;
		speed = rotation_speed(game, LEFT, position, xpos);
	}
	game->mouse.mouse_y = ypos;
	game->mouse.mouse_x = xpos;
	printf("x:%f y:%f\n", xpos, ypos);
	if (speed != 0)
		rotation(game, speed);
}
