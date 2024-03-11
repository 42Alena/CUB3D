/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 07:11:41 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/11 16:29:44 by dtolmaco         ###   ########.fr       */
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
	mlx_delete_texture(game->textures.cursor);
	mlx_delete_texture(game->textures.cursor_skeleton);
	free(game->ray.z_buffer);
	free_double_array(game->map.saved_map);
}