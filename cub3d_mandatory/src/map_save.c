/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:20 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/11 20:30:11 by akurmyza         ###   ########.fr       */
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

void get_first_map_line(t_game *game, char *map_first_line)
{
		//find first map line
		//skip newlines// emptylines
		int	x;
		int	y;
		char	c;

		y = *map_first_line;
		while (y < game->map.rows)
		{
			x = 0;
        	while (x < game->map.cols)
			{
				c = game->map.saved_map[y][x];
				if(c != ' ' && c == '\n')
					x++;
				else
				{
					//change &map_first_line
					*map_first_line = y;
					//TODO: add check hier if first line
					//exist only from ' ' and 1
					//ft_error(game, "Map not surrounded by walls");
					
					break ;	
				}
			}
			y++;
		}
}

t_bool check_map_first_last_line(char *first_last_line)
{
	
}

void load_map_configuration(t_game *game, char *filename)
{
	int fd;
	int x;
	int y;
	char *line;
	char	map_first_line;

	map_first_line = 0;
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
	/// new
	//TODO: I need to remember y array,
	// where starts map and give it back to
	save_map_textures_and_colors(game, &map_first_line);
	
	//TODO check map first line after visuals
	////////
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
