/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:20 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/08 13:54:44 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void map_file_read_save(t_game *game, char *filename)
{
	int fd;
	int x;
	int y;
	char *line;

	save_map_info_in_struct (game, filename);

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
		// while (x < game->map.cols)
		// {
		// 	game->map.saved_map[y][x] = ' ';
		// 	x++;
		// }
		game->map.saved_map[y][x] = '\0';
		free(line);
		y++;
	}
	close(fd);
}

void map_file_allocate_memory(t_game *game)
{
	int i;
	int j;

	i = -1;
	game->map.saved_map = (char **)malloc((game->map.rows + 1) * sizeof(char *));
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
1. finding map\s size (num_cols (width) and num_rows*(length))
first map check if:
-  <some_map>.ber can  be opened
-empty map (first line == 0)
- map is rectangular - all lines same length as first line;
- check if lines >=3(walls, signs, walls)
*/
void save_map_info_in_struct (t_game *game)
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
