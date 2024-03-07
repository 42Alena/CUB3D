/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:35:01 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/07 19:22:05 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	rotation(t_game *game, double rot_speed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
	game->player.dir_y = oldDirX * sin(rot_speed) + game->player.dir_y * cos(rot_speed);
	oldPlaneX = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed) - game->player.plane_y * sin(rot_speed);
	game->player.plane_y = oldPlaneX * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
}

int	distance_to_wall(t_game *game, double check_x, double check_y)
{
	if (game->map.saved_map[(int)check_x][(int)game->player.pos_y] == '1'\
	|| game->map.saved_map[(int)game->player.pos_x][(int)check_y] == '1')
		return (FALSE);
	return (TRUE);
}

int	check_collision(t_game *game, int direction)
{
	double		check_x;
	double		check_y;

	if (direction == DOWN)
	{
		check_y = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
		check_x = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
	}
	if (direction == UP)
	{
		check_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
		check_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	}
	if (direction == LEFT)
	{
		check_y = game->player.pos_y + game->player.dir_x * MOVE_SPEED;
		check_x = game->player.pos_x - game->player.dir_y * MOVE_SPEED;
	}
	if (direction == RIGHT)
	{
		check_y = game->player.pos_y - game->player.dir_x * MOVE_SPEED;
		check_x = game->player.pos_x + game->player.dir_y * MOVE_SPEED;
	}
	return (distance_to_wall(game, check_x, check_y));
}

void	move(t_game *game, int direction)
{
	if (!check_collision(game, direction))
		return ;
	if (direction == DOWN)
	{
		game->player.pos_y -= game->player.dir_y * MOVE_SPEED;
		game->player.pos_x -= game->player.dir_x * MOVE_SPEED;
	}
	if (direction == UP)
	{
		game->player.pos_y += game->player.dir_y * MOVE_SPEED;
		game->player.pos_x += game->player.dir_x * MOVE_SPEED;
	}
	if (direction == LEFT)
	{
		game->player.pos_y += game->player.dir_x * MOVE_SPEED;
		game->player.pos_x -= game->player.dir_y * MOVE_SPEED;
	}
	if (direction == RIGHT)
	{
		game->player.pos_y -= game->player.dir_x * MOVE_SPEED;
		game->player.pos_x += game->player.dir_y * MOVE_SPEED;
	}
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	
	game = param;
	if (keydata.key == MLX_KEY_S)
		move(game, DOWN);
	else if (keydata.key == MLX_KEY_W)
		move(game, UP);
	else if (keydata.key == MLX_KEY_D)
		move(game, RIGHT);
	else if (keydata.key == MLX_KEY_A)
		move(game, LEFT);
	else if (keydata.key == MLX_KEY_RIGHT)
		rotation(game, ROTATION_SPEED);
	else if (keydata.key == MLX_KEY_LEFT)
		rotation(game, -ROTATION_SPEED);
	else if (keydata.key == MLX_KEY_ESCAPE)
		exit(1);
}
