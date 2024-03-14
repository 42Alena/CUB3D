/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:20 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/14 06:40:30 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"



void map_allocate_memory(t_game *game)
{
	int		i;
	int		j;
	
	i = -1;
	game->map.saved_map = (char **)malloc(game->map.rows * sizeof(char *));
	if (game->map.saved_map == NULL)
		ft_error (game, "Map: memory allocation faled");
    while (++i < game->map.rows) 
	{
        game->map.saved_map[i] = (char *)malloc(game->map.cols * sizeof(char));
		if (!game->map.saved_map[i])
		{
			j = -1;
            while (++j < i)
                free(game->map.saved_map[j]);
            free(game->map.saved_map);
			ft_error (game, "Map: memory allocation faled");
		}
	}
	game->map.saved_map[i] = NULL;
}

void	map_read_save(t_game *game, char *filename)
{
	int		fd;
	int		x;
	int		y;
	char	*line;

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
			break ;
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
