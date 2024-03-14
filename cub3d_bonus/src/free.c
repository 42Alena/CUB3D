/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 07:11:41 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/14 12:59:19 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_textures(t_game *game)
{
	if (game->textures.bottom_image)
		free(game->textures.bottom_image);
	else if (game->textures.c3po)
		free(game->textures.c3po);
	else if (game->textures.c3po2)
		free(game->textures.c3po2);
	else if (game->textures.ceiling)
		free(game->textures.ceiling);
	else if (game->textures.door)
		free(game->textures.door);
	else if (game->textures.door_open)
		free(game->textures.door_open);
	else if (game->textures.floor)
		free(game->textures.floor);
	else if (game->textures.east)
		free(game->textures.east);
	else if (game->textures.north)
		free(game->textures.north);
	else if (game->textures.south)
		free(game->textures.south);
	else if (game->textures.west)
		free(game->textures.west);
	else if (game->textures.win_image)
		free(game->textures.win_image);
	else if (game->textures.r2d2)
		free(game->textures.r2d2);
}

void	free_mlx(t_game *game)
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
	free_textures(game);
	mlx_delete_texture(game->textures.cursor);
	free(game->ray.z_buffer);
	free_double_array(game->map.saved_map);
	system("pkill aplay");
	if (game->mlx)
		mlx_terminate(game->mlx);
}
