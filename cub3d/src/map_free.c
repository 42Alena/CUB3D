/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 07:11:41 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/24 09:57:07 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	free_saved_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.saved_map == NULL)
		return ;
	while (game->map.saved_map[i])
	{
		free(game->map.saved_map[i]);
		game->map.saved_map[i] = NULL;
		i++;
	}
	free(game->map.saved_map);
	game->map.saved_map = NULL;
}

void	free_map_struct(t_game *game)
{
	if (game->map.file_path)
		free(game->map.file_path);
	if (game->map.no_texture)
		free(game->map.no_texture);
	if (game->map.so_texture)
		free(game->map.so_texture);
	if (game->map.we_texture)
		free(game->map.we_texture);
	if (game->map.ea_texture)
		free(game->map.ea_texture);
	if (game->map.floor_color_str)
		free(game->map.floor_color_str);
	if (game->map.ceiling_color_str)
		free(game->map.ceiling_color_str);
	free_saved_map(game);
}
