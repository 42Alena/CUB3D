/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:20 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/10 13:36:13 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void map_file_read_save(t_game *game)
{
	int x;
	int y;
	int count_lines;

	count_lines = 0;
	save_map_info_in_struct(game);

	map_file_allocate_memory(game);
	game->map.fd = open(game->map.file_path, O_RDONLY);
	if (game->map.fd == -1)
		error_map_exit_game(game, "Can not open the map");
	game->map.fd_open = TRUE;

	y = 0;
	while (count_lines < game->map.first_line)
	{
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		free(game->map.tmp_line);
		count_lines++;
	}
	while (TRUE)
	{
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		x = 0;
		while (game->map.tmp_line[x] && game->map.tmp_line[x] != '\n')
		{
			// printf("ENTERED\n");
			// printf("%s\n",game->map.tmp_line);

			game->map.saved_map[y][x] = game->map.tmp_line[x];
			// printf("%c",game->map.saved_map[y][x]);
			x++;
		}
		while (x < game->map.cols)
		{
			game->map.saved_map[y][x] = ' ';
			x++;
		}
		game->map.saved_map[y][x] = '\0';
		// printf("%s\n", game->map.saved_map[y]);
		free(game->map.tmp_line);
		y++;
	}
	game->map.saved_map[y] = NULL;
	close(game->map.fd);
	game->map.fd_open = FALSE;
}


void save_map_info_in_struct(t_game *game)
{
	int flag_map_start;
	char 	*line;
	// int flag_map_info_end;

	flag_map_start = FALSE;
	line = NULL;
	game->map.fd = open(game->map.file_path, O_RDONLY);
	if (game->map.fd == -1)
		error_map_exit_game(game, "Can not open the map");
	game->map.fd_open = TRUE;
	// while (is_map_settings_complete(game) == FALSE)
	// while (TRUE)
	// {
	while (is_map_settings_complete(game) == FALSE)
	{
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		game->map.tmp_line = ft_strtrim(game->map.tmp_line, " ");
		game->map.len_tmp_line = ft_strlen(game->map.tmp_line);
		if (game->map.len_tmp_line > 0 && game->map.tmp_line[game->map.len_tmp_line - 1] == '\n')
			game->map.tmp_line[game->map.len_tmp_line - 1] = ' ';

		new_save_map_info_lines_to_struct(game);
		printf ("WRITING _MAP_INFO\n");

		free(game->map.tmp_line);
		game->map.rows += 1;
		game->map.first_line = game->map.rows;
	}
	while (TRUE)
	{
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		printf ("NEW_LINE_AFTER_MAP_INFO\n");
		if (!is_empty_tmp_line(game))
			break ;
		free(game->map.tmp_line);
		game->map.rows += 1;
		game->map.first_line = game->map.rows;
	}

	// if(//firstline)
	while (TRUE)
	{
		// flag_map_info_end = is_map_settings_complete(game);
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		// if (!flag_map_info_end)
		// 	game->map.tmp_line = ft_strtrim(game->map.tmp_line, " ");
		game->map.len_tmp_line = ft_strlen(game->map.tmp_line);
		// if (game->map.tmp_line[game->map.len_tmp_line - 1] == '\n')
		if (game->map.len_tmp_line > 0 && game->map.tmp_line[game->map.len_tmp_line - 1] == '\n')
			game->map.tmp_line[game->map.len_tmp_line - 1] = ' ';

//_______new
		//TODO: add check for 1.line
		is_map_middle_lines(game);
		if (game->map.cols < game->map.len_tmp_line)
					game->map.cols = game->map.len_tmp_line;
		printf("gnl:||%d||%s||\n", game->map.rows, game->map.tmp_line);
//_____end__new




		// if (!flag_map_info_end)
		// {
		// 	new_save_map_info_lines_to_struct(game);
		// 	// printf ("WRITING _MAP_INFO\n");
		// }
		// else
		// {
			// if (!flag_map_start)
			// {
			// 	flag_map_start = TRUE;
			// 	game->map.first_line = game->map.rows;
			// }
			// else
			// {
			// 	is_map_middle_lines(game);
			// 	if (game->map.cols < game->map.len_tmp_line)
			// 		game->map.cols = game->map.len_tmp_line;
			// }
		// }
		game->map.rows += 1;
		free(game->map.tmp_line);
	}
	close(game->map.fd);
	game->map.fd_open = FALSE;
}

// SAVE ALL INFORMATION TO STRUCT
// AFTER READING fule - check all together?
void new_save_map_info_lines_to_struct(t_game *game)
{
	char *line;
	int len;

	line = game->map.tmp_line;
	len = game->map.len_tmp_line;

	if (is_substring("NO ", line, 0, 3))
		wall_file_check_save(game, &(game->map.no_texture), line);
	else if (is_substring("SO ", line, 0, 3))
		wall_file_check_save(game, &(game->map.so_texture), line);
	else if (is_substring("WE ", line, 0, 3))
		wall_file_check_save(game, &(game->map.we_texture), line);
	else if (is_substring("EA ", line, 0, 3))
		wall_file_check_save(game, &(game->map.ea_texture), line);
	else if (is_substring("F ", line, 0, 2))
	{
		save_map_color(game, &(game->map.floor_color_str), line);
		game->map.floor_color_uint = get_rgb_from_string(game, game->map.floor_color_str);
	}
	else if (is_substring("C ", line, 0, 2))
	{
		save_map_color(game, &(game->map.ceiling_color_str), line);
		game->map.ceiling_color_uint = get_rgb_from_string(game, game->map.ceiling_color_str);
	}
	else if (game->map.len_tmp_line)
	{
		error_map_exit_game(game, "Map info is not complete");
	}
}

void map_file_allocate_memory(t_game *game)
{
	int i;
	int j;

	i = -1;
	game->map.saved_map = (char **)malloc((game->map.rows - game->map.first_line + 1) * sizeof(char *));
	if (game->map.saved_map == NULL)
		error_map_exit_game(game, "Map: memory allocation faled");
	while (++i < game->map.rows)
	{
		game->map.saved_map[i] = (char *)malloc((game->map.cols + 1) * sizeof(char));
		if (!game->map.saved_map[i])
		{
			j = -1;
			while (++j <= i)
				free(game->map.saved_map[j]);
			free(game->map.saved_map);
			error_map_exit_game(game, "Map: memory allocation failed");
		}
		game->map.saved_map[i][game->map.cols] = '\0';
	}
	game->map.saved_map[i] = NULL;
}

















/* 
//10.04. WORKING VERSIONs

void map_file_read_save(t_game *game)
{
	int x;
	int y;
	int count_lines;

	count_lines = 0;
	save_map_info_in_struct(game);

	map_file_allocate_memory(game);
	game->map.fd = open(game->map.file_path, O_RDONLY);
	if (game->map.fd == -1)
		error_map_exit_game(game, "Can not open the map");
	game->map.fd_open = TRUE;

	y = 0;
	while (count_lines < game->map.first_line)
	{
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		free(game->map.tmp_line);
		count_lines++;
	}
	while (TRUE)
	{
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		x = 0;
		while (game->map.tmp_line[x] && game->map.tmp_line[x] != '\n')
		{
			// printf("ENTERED\n");
			// printf("%s\n",game->map.tmp_line);

			game->map.saved_map[y][x] = game->map.tmp_line[x];
			// printf("%c",game->map.saved_map[y][x]);
			x++;
		}
		while (x < game->map.cols)
		{
			game->map.saved_map[y][x] = ' ';
			x++;
		}
		game->map.saved_map[y][x] = '\0';
		// printf("%s\n", game->map.saved_map[y]);
		free(game->map.tmp_line);
		y++;
	}
	game->map.saved_map[y] = NULL;
	close(game->map.fd);
	game->map.fd_open = FALSE;
}

void save_map_info_in_struct(t_game *game)
{
	int flag_map_start;
	int flag_map_info_end;

	flag_map_start = FALSE;
	game->map.fd = open(game->map.file_path, O_RDONLY);
	if (game->map.fd == -1)
		error_map_exit_game(game, "Can not open the map");
	game->map.fd_open = TRUE;
	while (TRUE)
	{
		flag_map_info_end = is_map_settings_complete(game);
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break;
		if (!flag_map_info_end)
			game->map.tmp_line = ft_strtrim(game->map.tmp_line, " ");
		game->map.len_tmp_line = ft_strlen(game->map.tmp_line);
		if (game->map.tmp_line[game->map.len_tmp_line - 1] == '\n')
			game->map.tmp_line[game->map.len_tmp_line - 1] = ' ';

		// printf("gnl:||%d||%s||\n", game->map.rows, game->map.tmp_line);

		if (!flag_map_info_end)
		{
			new_save_map_info_lines_to_struct(game);
			// printf ("WRITING _MAP_INFO\n");
		}
		else
		{
			if (!flag_map_start)
			{
				flag_map_start = TRUE;
				game->map.first_line = game->map.rows;
			}
			else
			{
				is_map_middle_lines(game);
				if (game->map.cols < game->map.len_tmp_line)
					game->map.cols = game->map.len_tmp_line;
			}
		}
		game->map.rows += 1;
		free(game->map.tmp_line);
	}
	close(game->map.fd);
	game->map.fd_open = FALSE;
}



 */