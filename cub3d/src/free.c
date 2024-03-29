/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 07:11:41 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/28 20:36:56 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int free_string_and_return_value(char *str_to_free, int ret_value)
{
    if (str_to_free != NULL)
        free(str_to_free);
    return ret_value;
}

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
	if (game->textures.c3po)
		free(game->textures.c3po);
	else if (game->textures.c3po2)
		free(game->textures.c3po2);
	else if (game->textures.door)
		free(game->textures.door);
	else if (game->textures.door_open)
		free(game->textures.door_open);
	else if (game->textures.wall.east)
		free(game->textures.wall.east);
	else if (game->textures.wall.north)
		free(game->textures.wall.north);
	else if (game->textures.wall.south)
		free(game->textures.wall.south);
	else if (game->textures.wall.west)
		free(game->textures.wall.west);
	else if (game->textures.win_image)
		free(game->textures.win_image);
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
