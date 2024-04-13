/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_game_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:17:30 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/13 10:42:58 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


void save_map_in_struct(t_game *game)
{
	int x;
	
	game->map.rows = 0;
	while (TRUE)
	{
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break;
		x = -1;
		change_char_newline_to_space(game);
		while (game->map.tmp_line[++x])
			game->map.saved_map[game->map.rows][x] = game->map.tmp_line[x];
		x -= 1;
		while (++x < game->map.cols)
			game->map.saved_map[game->map.rows][x] = ' ';
		game->map.saved_map[game->map.rows][x] = '\0';
		if (game->map.tmp_line)
			free(game->map.tmp_line);
		printf("%d||%s||\n", game->map.rows ,game->map.saved_map[game->map.rows]);
		game->map.rows += 1;
	}
	game->map.saved_map[game->map.rows] = NULL;
}
//TODO: add precheck  for player and precheck for lines
void save_map_info_in_struct(t_game *game)
{
	fd_open(game);
	while (is_map_settings_complete(game) == FALSE)
	{
		game->map.first_line += 1;
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break;
		new_save_map_info_lines_to_struct(game);
		if (game->map.tmp_line)
			free(game->map.tmp_line);
	}
	game->map.last_line = game->map.first_line;	
	while (TRUE)
	{
		game->map.last_line += 1;
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break;
		change_char_newline_to_space(game);
		game->map.len_tmp_line = ft_strlen(game->map.tmp_line);
		if (game->map.cols < game->map.len_tmp_line)
			game->map.cols = game->map.len_tmp_line;
		if (game->map.tmp_line)
			free(game->map.tmp_line);
	}
	fd_close(game);
}

void new_save_map_info_lines_to_struct(t_game *game)
{
	game->map.tmp_line = ft_strtrim(game->map.tmp_line, " ");
	change_char_newline_to_space(game);
	game->map.len_tmp_line = ft_strlen(game->map.tmp_line);
	if (is_substring("NO ", game->map.tmp_line, 0, 3))
		wall_file_check_save(game, &(game->map.no_texture));
	else if (is_substring("SO ", game->map.tmp_line, 0, 3))
		wall_file_check_save(game, &(game->map.so_texture));
	else if (is_substring("WE ", game->map.tmp_line, 0, 3))
		wall_file_check_save(game, &(game->map.we_texture));
	else if (is_substring("EA ", game->map.tmp_line, 0, 3))
		wall_file_check_save(game, &(game->map.ea_texture));
	else if (is_substring("F ", game->map.tmp_line, 0, 2))
		save_map_color(game, &(game->map.floor_color_str), 'f');
	else if (is_substring("C ", game->map.tmp_line, 0, 2))
		save_map_color(game, &(game->map.ceiling_color_str), 'c');
	else if (!is_empty_tmp_line(game))
		error_map_exit_game(game, "Map info is not complete");
}
