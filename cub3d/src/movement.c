/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:38:29 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/04/27 12:04:04 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

void	wasd(t_game *game, double time)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		move(&game->player, game->map.saved_map, game->move_speed, DOWN);
		footstep_sound(&game->last_step_time, time, game->move_speed);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		move(&game->player, game->map.saved_map, game->move_speed, UP);
		footstep_sound(&game->last_step_time, time, game->move_speed);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		move(&game->player, game->map.saved_map, game->move_speed, RIGHT);
		footstep_sound(&game->last_step_time, time, game->move_speed);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		move(&game->player, game->map.saved_map, game->move_speed, LEFT);
		footstep_sound(&game->last_step_time, time, game->move_speed);
	}
}
