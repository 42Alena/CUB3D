/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocate_memory.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:20 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/11 05:00:52 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void map_allocate_memory(t_game *game)
{
	int i;
	int j;

	i = -1;
	game->map.saved_map = (char **)malloc(game->map.rows * sizeof(char *));
	if (game->map.saved_map == NULL)
		ft_error(game, "Map: memory allocation faled");
	while (++i < game->map.rows)
	{
		game->map.saved_map[i] = (char *)malloc(game->map.cols * sizeof(char));
		if (!game->map.saved_map[i])
		{
			j = -1;
			while (++j < i)
				free(game->map.saved_map[j]);
			free(game->map.saved_map);
			ft_error(game, "Map: memory allocation faled");
		}
	}
	game->map.saved_map[i] = NULL;
}

void load_map_configuration(t_game *game, char *filename)
{
	int fd;
	int x;
	int y;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "Failure of opening map");
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
check_maps_cols_rows(t_game *game, int fd) is partial function
from void	check_map(t_game *game, char *filename)
//save info before map in structure, not in map
//save max as for num rows
//save max as for num cols */
void check_maps_cols_rows(t_game *game, int fd)
{
	char *line;
	int max_len;

	line = NULL;
	max_len = 0;
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
	if (game->map.cols == 0 && game->map.rows == 0)
		ft_error(game, "Map is empty");
}

/*
1. finding map\s size (num_cols (width) and num_rows*(length))
first map check if:
-  <some_map>.ber can  be opened
-empty map (first line == 0)
- map is rectangular - all lines same length as first line;
- check if lines >=3(walls, signs, walls)
*/
void check_map(t_game *game, char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	game->map.cols = 0;
	game->map.rows = 0;
	if (fd == -1)
		ft_error(game, "Failure of opening map");
	check_maps_cols_rows(game, fd);
	printf("rows: %d, cols: %d\n", game->map.rows, game->map.cols);
	if (game->map.rows < 3)
		ft_error(game, "Map is not valid");
	close(fd);
}
