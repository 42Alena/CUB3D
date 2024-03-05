/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:32:28 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 12:16:04 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void ft_hook(void* param)
{
	t_game* game = param;
	// if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	// 	calculate(game->mlx);
	//calculate(game);
	(void)game;
}

void init_game_struct(t_game *game)
{
	game->playable = FALSE;
	game->player_count = 0;
	game->map  = NULL;
	game->map_info.cols = 0;
	game->map_info.rows = 0;

	game->player_x = 1.5;
	game->player_y = 1.5;
	game->player_direction = FALSE;

	game->dir_x = -1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
	game->image = NULL;
}

void	game_init(t_game *game)
{
	init_game_struct(game);
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", true);
	if (!game->mlx)
		ft_error(NULL, "mlx_init");
}	
