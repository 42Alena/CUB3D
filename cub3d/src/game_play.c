/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:37:23 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/28 10:51:49 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	gameplay(t_game *game)
{
	if (game->textures.image)
		mlx_delete_image(game->mlx, game->textures.image);
	raycasting(game);
	key_press(game);
	if (game->mouse.mouse_x > game->window_width / 1.1)
		rotation(&game->player, ROTATION_SPEED / 2);
	else if (game->mouse.mouse_x < game->window_width * 1.1 \
	- game->window_width)
		rotation(&game->player, -ROTATION_SPEED / 2);
}

void	ft_hook(void *param)
{
	t_game	*game;

	game = param;
	gameplay(game);
}
