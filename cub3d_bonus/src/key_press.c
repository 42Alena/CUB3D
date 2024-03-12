/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:35:01 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/12 16:39:27 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	rotation(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = \
	game->player.dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
	game->player.dir_y = \
	old_dir_x * sin(rot_speed) + game->player.dir_y * cos(rot_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed) \
	- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = \
	old_plane_x * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
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
		check_y = game->player.pos_y - game->player.dir_y * game->move_speed;
		check_x = game->player.pos_x - game->player.dir_x * game->move_speed;
	}
	if (direction == UP)
	{
		check_y = game->player.pos_y + game->player.dir_y * game->move_speed;
		check_x = game->player.pos_x + game->player.dir_x * game->move_speed;
	}
	if (direction == RIGHT)
	{
		check_y = game->player.pos_y + game->player.dir_x * game->move_speed;
		check_x = game->player.pos_x - game->player.dir_y * game->move_speed;
	}
	if (direction == LEFT)
	{
		check_y = game->player.pos_y - game->player.dir_x * game->move_speed;
		check_x = game->player.pos_x + game->player.dir_y * game->move_speed;
	}
	return (distance_to_wall(game, check_x, check_y));
}

void	move(t_game *game, int direction)
{
	if (!check_collision(game, direction))
		return ;
	if (direction == DOWN)
	{
		game->player.pos_y -= game->player.dir_y * game->move_speed;
		game->player.pos_x -= game->player.dir_x * game->move_speed;
	}
	if (direction == UP)
	{
		game->player.pos_y += game->player.dir_y * game->move_speed;
		game->player.pos_x += game->player.dir_x * game->move_speed;
	}
	if (direction == RIGHT)
	{
		game->player.pos_y += game->player.dir_x * game->move_speed;
		game->player.pos_x -= game->player.dir_y * game->move_speed;
	}
	if (direction == LEFT)
	{
		game->player.pos_y -= game->player.dir_x * game->move_speed;
		game->player.pos_x += game->player.dir_y * game->move_speed;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE)
	{
		if (!game->is_map)
			game->is_map = TRUE;
		else
			game->is_map = FALSE;
	}
	else if (keydata.key == MLX_KEY_TAB)
	{
		game->is_settings = TRUE;
		game->textures.settings1->enabled = TRUE;
		game->textures.settings05->enabled = TRUE;
		game->textures.settings2->enabled = TRUE;
		if (game->move_speed == INITIAL_MOVE_SPEED)
			mlx_image_to_window(game->mlx, game->textures.settings1, 0, 0);
		else if (game->move_speed == INITIAL_MOVE_SPEED / 2)
			mlx_image_to_window(game->mlx, game->textures.settings05, 0, 0);
		else if (game->move_speed == INITIAL_MOVE_SPEED * 2)
			mlx_image_to_window(game->mlx, game->textures.settings2, 0, 0);
	}
}

void	key_press(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move(game, DOWN);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move(game, UP);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move(game, RIGHT);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move(game, LEFT);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotation(game, ROTATION_SPEED);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotation(game, -ROTATION_SPEED);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		free_mlx(game);
		exit(EXIT_SUCCESS);
	}
}
