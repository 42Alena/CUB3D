/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:20 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/04 10:03:04 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void map_allocate_memory(t_game *game)
{
	int i;
	int j;

	i = -1;
	game->map.saved_map = (char **)malloc((game->map.rows + 1) * sizeof(char *));
	if (game->map.saved_map == NULL)
		error_map_exit_game(game, "Map: memory allocation faled");
	while (++i < game->map.rows)
	{
		game->map.saved_map[i] = (char *)malloc(game->map.cols * sizeof(char));
		if (!game->map.saved_map[i])
		{
			j = -1;
			while (++j < i)
				free(game->map.saved_map[j]);
			free(game->map.saved_map);
			error_map_exit_game(game, "Map: memory allocation faled");
		}
	}
	game->map.saved_map[i] = NULL;
}

void map_read_save(t_game *game, char *filename)
{
	int fd;
	int x;
	int y;
	char *line;

	get_size_map(game, filename);
	if (game->map.rows <= 8 || game->map.cols <= 7)
		error_map_exit_game(game, "Map: not enough information");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_map_exit_game(game, "Can not open the map");
	y = 0;
	map_allocate_memory(game);
	while (TRUE)
	{
		x = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break;
		while (line[x] && line[x] != '\n')
		{
			game->map.saved_map[y][x] = line[x];
			x++;
		}
		game->map.saved_map[y][x] = '\0';
		free(line);
		y++;
	}
	close(fd);
}

/*
1. finding map\s size (num_cols (width) and num_rows*(length))
first map check if:
-  <some_map>.ber can  be opened
-empty map (first line == 0)
- map is rectangular - all lines same length as first line;
- check if lines >=3(walls, signs, walls)
*/
void get_size_map(t_game *game, char *filename)
{
	int fd;
	char *line;
	int max_len;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_map_exit_game(game, "Can not open the map");
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		max_len = ft_strlen(line);
		if (line == 0)
			break;
		if (line[max_len - 1] == '\n')
			max_len--;
		free(line);
		if (game->map.cols < max_len)
			game->map.cols = max_len;
		game->map.rows += 1;
	}
	close(fd);
}

/* 
row = first line of map
check if it firs_last_line(consisst only from spaces or 1)
 */
void extract_map_save(t_game *game, int first_line)
{
	int	last_line;

	last_line = game->map.rows;

	printf("game->map.saved_map[first_line]: ||%s||\n", game->map.saved_map[first_line]);
	if (is_map_first_last_line(game, first_line) == FALSE)
		error_map_exit_game(game, "Map: first line is not valid");

	//find last row (go from bottom to first line)
	while(is_empty_line(game->map.saved_map[last_line]))
		last_line -= 1;

	printf(" first_line = %d,\n last_line = %d\n", first_line, last_line);
	if (last_line <= first_line + 1)
		error_map_exit_game(game, "Map: middle map is not valid");

	printf("game->map.saved_map[last_line]: ||%s||\n", game->map.saved_map[last_line]);
	if ( is_map_first_last_line(game, last_line) == FALSE)
		error_map_exit_game(game, "Map: last line is not valid");
}

// t_bool check_line_walls(t_game *game, int row)
// {

// }