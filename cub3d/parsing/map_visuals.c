/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visuals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:32:28 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/26 10:46:31 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	wall_file_check_save(t_game *game, char **name_txtr)
{
	char	*tmp;
	t_bool	is_png;

	if (*name_txtr != NULL)
		error_map_exit_game(game, "Map: double map settings for texture");
	*name_txtr = ft_substr(game->map.tmp_line, 3, game->map.len_tmp_line - 3);
	tmp = ft_strtrim(*name_txtr, " ");
	free (*name_txtr);
	*name_txtr = tmp;
	if (*name_txtr == NULL)
		error_map_exit_game(game, "Missing file: <wall>.png");
	game->map.len_tmp_line = ft_strlen(*name_txtr);
	if (game->map.len_tmp_line <= 4)
		error_map_exit_game(game, "Expected file:  <wall>.png");
	is_png = is_substring(".png", *name_txtr, game->map.len_tmp_line - 4, 4);
	if (is_png == FALSE)
		error_map_exit_game(game, "Invalid  file extension: .png expected");
	is_valid_file(game, *name_txtr);
}
