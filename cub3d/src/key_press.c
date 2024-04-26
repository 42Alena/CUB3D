/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:35:01 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/26 10:19:24 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	rotation(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = \
	player->dir_x * cos(rot_speed) - player->dir_y * sin(rot_speed);
	player->dir_y = \
	old_dir_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed) \
	- player->plane_y * sin(rot_speed);
	player->plane_y = \
	old_plane_x * sin(rot_speed) + player->plane_y * cos(rot_speed);
}

int	check_collision(t_player *player, char **saved_map, double speed, int dir)
{
	double		check_x;
	double		check_y;

	if (dir == DOWN)
	{
		check_y = player->pos_y - player->dir_y * speed;
		check_x = player->pos_x - player->dir_x * speed;
	}
	if (dir == UP)
	{
		check_y = player->pos_y + player->dir_y * speed;
		check_x = player->pos_x + player->dir_x * speed;
	}
	if (dir == RIGHT)
	{
		check_y = player->pos_y + player->dir_x * speed;
		check_x = player->pos_x - player->dir_y * speed;
	}
	if (dir == LEFT)
	{
		check_y = player->pos_y - player->dir_x * speed;
		check_x = player->pos_x + player->dir_y * speed;
	}
	return (distance_to_wall(player, saved_map, check_x, check_y));
}

void	move(t_player *player, char **saved_map, double move_speed, int dir)
{
	if (!check_collision(player, saved_map, move_speed, dir))
		return ;
	if (dir == DOWN)
	{
		player->pos_y -= player->dir_y * move_speed;
		player->pos_x -= player->dir_x * move_speed;
	}
	if (dir == UP)
	{
		player->pos_y += player->dir_y * move_speed;
		player->pos_x += player->dir_x * move_speed;
	}
	if (dir == RIGHT)
	{
		player->pos_y += player->dir_x * move_speed;
		player->pos_x -= player->dir_y * move_speed;
	}
	if (dir == LEFT)
	{
		player->pos_y -= player->dir_x * move_speed;
		player->pos_x += player->dir_y * move_speed;
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
	else if (keydata.key == MLX_KEY_ESCAPE)
	{
		free_game(game);
		exit(EXIT_SUCCESS);
	}
}

void	key_press(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move(&game->player, game->map.saved_map, game->move_speed, DOWN);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move(&game->player, game->map.saved_map, game->move_speed, UP);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move(&game->player, game->map.saved_map, game->move_speed, RIGHT);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move(&game->player, game->map.saved_map, game->move_speed, LEFT);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotation(&game->player, ROTATION_SPEED);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotation(&game->player, -ROTATION_SPEED);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_TAB))
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
