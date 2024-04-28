/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:20:47 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/04/28 10:56:24 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
