/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:20 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/11 17:59:02 by akurmyza         ###   ########.fr       */
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
	while (count_lines < game->map.first_line - 1)
	{
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		free(game->map.tmp_line);
		count_lines++;
	}
	while (count_lines < game->map.last_line )
	{
		count_lines++;
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		x = -1;
		change_char_newline_to_space(game);
		while (game->map.tmp_line[++x])
			game->map.file_map[y][x] = game->map.tmp_line[x];
		while (x < game->map.cols)
		{
			game->map.file_map[y][x] = ' ';
			x++;
		}
		game->map.file_map[y][x] = '\0';
		// printf("%s\n", game->map.file_map[y]);
		free(game->map.tmp_line);
		y++;
	}
	game->map.file_map[y] = NULL;
	close(game->map.fd);
	game->map.fd_open = FALSE;
}

void save_map_info_in_struct(t_game *game)
{
	t_bool flag;

	flag = FALSE;
	game->map.fd = open(game->map.file_path, O_RDONLY);
	if (game->map.fd == -1)
		error_map_exit_game(game, "Can not open the map");
	game->map.fd_open = TRUE;
	while (is_map_settings_complete(game) == FALSE)
	{
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		new_save_map_info_lines_to_struct(game);
		free(game->map.tmp_line);
	}
	while (TRUE)
	{
		game->map.rows += 1;
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		change_char_newline_to_space(game);
		// if (is_map_first_last_line(game) && game->map.first_line == 0)
		// 	game->map.first_line = game->map.rows;
		if (game->map.first_line == 0)
		{
			if (is_empty_tmp_line(game))
			{
				free(game->map.tmp_line);
				continue ;
			}
			if (!is_map_first_last_line(game))
				 error_map_exit_game(game, "Map: first line error");
			else
			{	
				game->map.first_line = game->map.rows;
				game->map.last_line = game->map.rows;
			}
		}

		if (is_empty_tmp_line(game) && flag == FALSE)
		{
			flag = TRUE;
			game->map.first_empty_line = game->map.rows;
		}

		if (game->map.rows > game->map.first_line + 1 && is_map_first_last_line(game))
			game->map.last_line = game->map.rows;
		check_map_file_lines(game);	
		if (is_map_first_last_line(game))
				game->map.last_line = game->map.rows;
		printf("gnl:||%d||%s||\n", game->map.rows, game->map.tmp_line);
		free(game->map.tmp_line);
	}
    if(game->player.count != 1)
		error_map_exit_game(game, "Must be 1 Player with direction  N,S,E or W");
	if (game->map.first_line == 0 && game->map.last_line == 0)
		error_map_exit_game(game, "Map: No first/last line");
	if (game->map.first_empty_line > game->map.first_line  && game->map.first_empty_line < game->map.last_line)
		error_map_exit_game(game, "Map: Empte line in map");
	close(game->map.fd);
	game->map.fd_open = FALSE;
}


void change_char_newline_to_space(t_game *game)
{
	game->map.len_tmp_line = ft_strlen(game->map.tmp_line);
	if (game->map.len_tmp_line > 0)
	{
		if (game->map.tmp_line[game->map.len_tmp_line - 1] == '\n')
			game->map.tmp_line[game->map.len_tmp_line - 1] = ' ';
	}
}

// SAVE ALL INFORMATION TO STRUCT
// AFTER READING fule - check all together?
void new_save_map_info_lines_to_struct(t_game *game)
{
	//______new___start
	game->map.rows += 1;
	game->map.tmp_line = ft_strtrim(game->map.tmp_line, " ");
	change_char_newline_to_space(game);
	game->map.len_tmp_line = ft_strlen(game->map.tmp_line);
	
	//_____new___end
	
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


/*
it must beginn and end with 1   1
and have only map symbols
*/
void check_map_file_lines(t_game *game)
{
    int x;
    char c;

    x = 0;
	if (game->map.cols < game->map.len_tmp_line)
			game->map.cols = game->map.len_tmp_line;
//TODO: add save first and last row and empty line between first and last
	if (is_map_first_last_line(game))
	{}
    while (game->map.tmp_line[x])
    {
        c = game->map.tmp_line[x];
		//TODO:ADD CHECK for spaces with 0
        if((c == '0' && game->map.tmp_line[x - 1] && game->map.tmp_line[x - 1] == ' ') ||\
        	(c == '0' && game->map.tmp_line[x + 1] && game->map.tmp_line[x + 1] == ' '))
            error_map_exit_game(game, "Map: '0' with space");
		if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != '0' && c != '1' && c != ' ')
        {
            printf("line[x]: %c,\n", game->map.tmp_line[x]);
            error_map_exit_game(game, "Map: Not allowed symbol");
        }
        if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			game->player.count += 1;
			// printf("c = %c, game->player.count = %d\n", c, game->player.count);
		}
        x++;
    }
}

/* 
FOR CHECK 1. and last wall
    // char *line;
    // int len;

    // line = ft_strtrim(game->map.tmp_line, " ");
    // len = ft_strlen(line);
    if (len > 0 && line[0] != '1' && line[len - 1] != '1')
    {
        printf("line[x]: %c,\n", line[x]);
        error_map_exit_game(game, "Map: middlerow: no outside wall");
    }
    if (line[x] != 1 && line[len - 1] != 1)
        error_map_exit_game(game, "Map: middlerow: no outside wall");
    return (TRUE);
 */

// void map_allocate_memory(t_game *game, char **map)
void map_file_allocate_memory(t_game *game)
{
	int i;
	int j;

	i = -1;
	game->map.file_map = (char **)malloc((game->map.rows - game->map.first_line + 1) * sizeof(char *));
	if (game->map.file_map == NULL)
		error_map_exit_game(game, "Map: memory allocation faled");
	while (++i < game->map.rows)
	{
		game->map.file_map[i] = (char *)malloc((game->map.cols + 1) * sizeof(char));
		if (!game->map.file_map[i])
		{
			j = -1;
			while (++j <= i)
				free(game->map.file_map[j]);
			free(game->map.file_map);
			error_map_exit_game(game, "Map: memory allocation failed");
		}
		game->map.file_map[i][game->map.cols] = '\0';
	}
	game->map.file_map[i] = NULL;
}













//11.04
// void map_file_allocate_memory(t_game *game)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	game->map.saved_map = (char **)malloc((game->map.rows - game->map.first_line + 1) * sizeof(char *));
// 	if (game->map.saved_map == NULL)
// 		error_map_exit_game(game, "Map: memory allocation faled");
// 	while (++i < game->map.rows)
// 	{
// 		game->map.saved_map[i] = (char *)malloc((game->map.cols + 1) * sizeof(char));
// 		if (!game->map.saved_map[i])
// 		{
// 			j = -1;
// 			while (++j <= i)
// 				free(game->map.saved_map[j]);
// 			free(game->map.saved_map);
// 			error_map_exit_game(game, "Map: memory allocation failed");
// 		}
// 		game->map.saved_map[i][game->map.cols] = '\0';
// 	}
// 	game->map.saved_map[i] = NULL;
// }














/* 11.04


void save_map_info_in_struct(t_game *game)
{
	char 	*line;
	int		flag_map_start;
	int		flag_map_end;

	line = NULL;
	flag_map_start = FALSE;
	flag_map_end = FALSE;

	game->map.fd = open(game->map.file_path, O_RDONLY);
	if (game->map.fd == -1)
		error_map_exit_game(game, "Can not open the map");
	game->map.fd_open = TRUE;
	while (is_map_settings_complete(game) == FALSE)
	{
		game->map.rows += 1;
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
		game->map.tmp_line = ft_strtrim(game->map.tmp_line, " ");
		game->map.len_tmp_line = ft_strlen(game->map.tmp_line);
		if (game->map.len_tmp_line > 0 && game->map.tmp_line[game->map.len_tmp_line - 1] == '\n')
			game->map.tmp_line[game->map.len_tmp_line - 1] = ' ';
		new_save_map_info_lines_to_struct(game);
		free(game->map.tmp_line);
	}
	while (TRUE)
	{
		game->map.rows += 1;
		game->map.tmp_line = get_next_line(game->map.fd);
		if (game->map.tmp_line == NULL)
			break ;
			
		game->map.len_tmp_line = ft_strlen(game->map.tmp_line);
		if (game->map.len_tmp_line > 0 && game->map.tmp_line[game->map.len_tmp_line - 1] == '\n')
			game->map.tmp_line[game->map.len_tmp_line - 1] = ' ';
		if (game->map.first_line == 0)
		{
			if (is_empty_tmp_line(game))
			{
				free(game->map.tmp_line);
				continue ;
			}
			else
			{
				game->map.first_line == game->map.rows;
				game->map.last_line == game->map.rows;
			}
			
		}
		else
		{
			if (is_empty_tmp_line(game))
			 	error_map_exit_game(game, "Map: empty line");
				
			game->map.last_line == game->map.rows;
		}
		// else if (is_empty_tmp_line(game) && game->map.first_line == 0)
			// game->map.last_line = game->map.rows;
		// else if ()
		//TODO: add check for 1.line
		// is_map_middle_lines(game);
		if (game->map.cols < game->map.len_tmp_line)
					game->map.cols = game->map.len_tmp_line;
		printf("gnl:||%d||%s||\n", game->map.rows, game->map.tmp_line);
		free(game->map.tmp_line);
	}
	close(game->map.fd);
	game->map.fd_open = FALSE;
}

 */