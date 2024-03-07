/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:35:01 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/07 12:29:09 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3



void	rotation(t_game *game, int direction)
{
	double	oldDirX;
	double	oldPlaneX;
	double	speed;

	speed = ROTATION_SPEED;
	if (direction == RIGHT)
		speed = -ROTATION_SPEED;
	oldDirX = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(speed) - game->player.dir_y * sin(speed);
	game->player.dir_y = oldDirX * sin(speed) + game->player.dir_y * cos(speed);
	oldPlaneX = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(speed) - game->player.plane_y * sin(speed);
	game->player.plane_y = oldPlaneX * sin(speed) + game->player.plane_y * cos(speed);
}

int	distance_to_wall(t_game *game, double check_x, double check_y)
{
	if (game->map.saved_map[(int)check_x][(int)game->player.player_y] == '1'\
	|| game->map.saved_map[(int)game->player.player_x][(int)check_y] == '1')
		return (FALSE);
	return (TRUE);
}

int	check_collision(t_game *game, int direction)
{
	double		check_x;
	double		check_y;

	if (direction == DOWN)
	{
		check_y = game->player.player_y - game->player.dir_y * MOVE_SPEED;
		check_x = game->player.player_x - game->player.dir_x * MOVE_SPEED;
	}
	if (direction == UP)
	{
		check_y = game->player.player_y + game->player.dir_y * MOVE_SPEED;
		check_x = game->player.player_x + game->player.dir_x * MOVE_SPEED;
	}
	if (direction == LEFT)
	{
		check_y = game->player.player_y + game->player.dir_x * MOVE_SPEED;
		check_x = game->player.player_x - game->player.dir_y * MOVE_SPEED;
	}
	if (direction == RIGHT)
	{
		check_y = game->player.player_y - game->player.dir_x * MOVE_SPEED;
		check_x = game->player.player_x + game->player.dir_y * MOVE_SPEED;
	}
	return (distance_to_wall(game, check_x, check_y));
}

void	move(t_game *game, int direction)
{
	if (!check_collision(game, direction))
		return ;
	if (direction == DOWN)
	{
		game->player.player_y -= game->player.dir_y * MOVE_SPEED;
		game->player.player_x -= game->player.dir_x * MOVE_SPEED;
	}
	if (direction == UP)
	{
		game->player.player_y += game->player.dir_y * MOVE_SPEED;
		game->player.player_x += game->player.dir_x * MOVE_SPEED;
	}
	if (direction == LEFT)
	{
		game->player.player_y += game->player.dir_x * MOVE_SPEED;
		game->player.player_x -= game->player.dir_y * MOVE_SPEED;
	}
	if (direction == RIGHT)
	{
		game->player.player_y -= game->player.dir_x * MOVE_SPEED;
		game->player.player_x += game->player.dir_y * MOVE_SPEED;
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
		rotation(game, RIGHT);
	else if (keydata.key == MLX_KEY_LEFT)
		rotation(game, LEFT);
	else if (keydata.key == MLX_KEY_ESCAPE)
		exit(1);
}
