/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:20 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/28 11:45:52 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	map_file_read_save(t_game *game)
{
	save_map_info_in_struct(game);
	if (game->player.count != 1)
		error_map_exit_game(game, \
		"Must be 1 Player with direction  N,S,E or W");
	if (game->map.last_line <= (game->map.first_line + 3))
		error_map_exit_game(game, "Map: not enough lines");
	if (game->map.cols <= 3)
		error_map_exit_game(game, "Map: not enough columns");
	map_file_allocate_memory(game);
	fd_open(game);
	while (game->map.rows < game->map.first_line)
	{
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		gnl_free_tmp_line_set_null(game);
		game->map.rows++;
	}
	save_map_in_struct(game);
	fd_close(game);
}

void	change_char_newline_to_space(t_game *game)
{
	length_tmp_line(game);
	if (game->map.len_tmp_line > 0)
	{
		if (game->map.tmp_line[game->map.len_tmp_line - 1] == '\n')
			game->map.tmp_line[game->map.len_tmp_line - 1] = ' ';
	}
}

void	map_file_allocate_memory(t_game *game)
{
	int	i;
	int	len;

	i = -1;
	len = game->map.last_line - game->map.first_line - 1;
	game->map.saved_map = (char **)malloc((len + 1) * sizeof(char *));
	if (game->map.saved_map == NULL)
		error_map_exit_game(game, "Map: memory allocation faled");
	while (++i < len)
	{
		game->map.saved_map[i] = \
		(char *)malloc((game->map.cols + 1) * sizeof(char));
		if (!game->map.saved_map[i])
			cleanup_map_on_allocation_failure(game, i);
		game->map.saved_map[i][game->map.cols] = '\0';
	}
	game->map.saved_map[i] = NULL;
}

void	cleanup_map_on_allocation_failure(t_game *game, int i)
{
	int	j;

	j = -1;
	while (++j <= i)
	{
		if (game->map.saved_map[j])
			free(game->map.saved_map[j]);
	}
	if (game->map.saved_map)
		free(game->map.saved_map);
	game->map.saved_map = NULL;
	error_map_exit_game(game, "Map: memory allocation failed");
}

t_bool	is_map_settings_complete(t_game *game)
{
	if (game->map.no_texture != NULL && \
		game->map.so_texture != NULL && \
		game->map.we_texture != NULL && \
		game->map.ea_texture != NULL && \
		game->map.floor_color_str != NULL && \
		game->map.ceiling_color_str != NULL && \
		game->map.floor_color_uint != 256 && \
		game->map.ceiling_color_uint != 256)
		return (TRUE);
	else
		return (FALSE);
}
