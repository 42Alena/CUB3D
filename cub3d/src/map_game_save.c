/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_game_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:17:30 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/14 09:52:06 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void save_map_in_struct(t_game *game)
{
	int x;
	int	i;
	
	game->map.rows = 0;
	while (TRUE)
	{
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break;
		i = 0;
		x = 0;
		game->map.saved_map[game->map.rows][x] = ' ';
		change_char_newline_to_space(game);
		while (game->map.tmp_line[++x])
		{
			game->map.saved_map[game->map.rows][x] = game->map.tmp_line[i];
			i++;
		}
		x -= 1;
		while (++x < game->map.cols)
			game->map.saved_map[game->map.rows][x] = ' ';
		game->map.saved_map[game->map.rows][x] = '\0';
		gnl_free_tmp_line_set_null(game);
		// printf("%d||%s||\n", game->map.rows ,game->map.saved_map[game->map.rows]);
		game->map.rows += 1;
	}
	game->map.saved_map[game->map.rows] = NULL;
}

void save_map_info_in_struct(t_game *game)
{
	fd_open(game);
	while (is_map_settings_complete(game) == FALSE)
	{
		game->map.first_line += 1;
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break;
		save_map_info_lines_to_struct(game);
		gnl_free_tmp_line_set_null(game);
	}
	game->map.last_line = game->map.first_line;	
	while (TRUE)
	{
		game->map.last_line += 1;
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break;
		check_map_file_characters(game);
		length_tmp_line(game);
		if (game->map.cols < game->map.len_tmp_line)
			game->map.cols = game->map.len_tmp_line;
		gnl_free_tmp_line_set_null(game);
	}
	game->map.cols += 1;
	fd_close(game);
}

void check_map_file_characters(t_game *game)
{
	int		i;
	char	c;

	i = 0;
	change_char_newline_to_space(game);
	if (is_empty_tmp_line(game))
		return ;
	while (game->map.tmp_line[i])
	{
		c = game->map.tmp_line[i];
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			game->map.count_player += 1;
		else if (c != '0' && c != '1' && c != ' ')
			error_map_exit_game(game, "Map: Detected unsupported symbol");
		i++;
	}
}

void save_map_info_lines_to_struct(t_game *game)
{
	game->map.tmp_line = ft_strtrim(game->map.tmp_line, " ");
	change_char_newline_to_space(game);
	length_tmp_line(game);
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
