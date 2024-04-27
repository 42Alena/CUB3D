/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 07:11:41 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/27 11:08:06 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_game(t_game *game)
{
	free_map_struct(game);
	free_mlx_img_txtr(game);
	free_textures(game);
	free(game->ray.z_buffer);
	system("screen -S music_session -X quit ");
	system("pkill aplay");
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	free_textures(t_game *game)
{
	if (game->textures.c3po)
		free(game->textures.c3po);
	if (game->textures.c3po2)
		free(game->textures.c3po2);
	if (game->textures.door)
		free(game->textures.door);
	if (game->textures.door_open)
		free(game->textures.door_open);
	if (game->textures.wall.east)
		free(game->textures.wall.east);
	if (game->textures.wall.north)
		free(game->textures.wall.north);
	if (game->textures.wall.south)
		free(game->textures.wall.south);
	if (game->textures.wall.west)
		free(game->textures.wall.west);
	if (game->textures.win_image)
		free(game->textures.win_image);
}

void	free_mlx_img_txtr(t_game *game)
{
	if (game->textures.image)
		mlx_delete_image(game->mlx, game->textures.image);
	if (game->textures.main_menu)
		mlx_delete_image(game->mlx, game->textures.main_menu);
	if (game->textures.settings1)
		mlx_delete_image(game->mlx, game->textures.settings1);
	if (game->textures.settings05)
		mlx_delete_image(game->mlx, game->textures.settings05);
	if (game->textures.settings2)
		mlx_delete_image(game->mlx, game->textures.settings2);
	if (game->textures.end)
		mlx_delete_image(game->mlx, game->textures.end);
	if (game->textures.congrats)
		mlx_delete_image(game->mlx, game->textures.congrats);
	mlx_delete_texture(game->textures.cursor);
}
