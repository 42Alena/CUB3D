/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:20 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 13:44:57 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void map_init(t_game *game)
{
	int		i;
	int		j;
	
	i = -1;
	game->map = (char **)malloc(game->map_info.rows * sizeof(char *));
	if (game->map == NULL)
		ft_error (game, "Map: memory allocation faled");
    while (++i < game->map_info.rows) 
	{
        game->map[i] = (char *)malloc(game->map_info.cols * sizeof(char));
		if (!game->map[i])
		{
			j = -1;
            while (++j < i)
                free(game->map[j]);
            free(game->map);
			ft_error (game, "Map: memory allocation faled");
		}
	}
	game->map[i] = NULL;
}

void	map_read(t_game *game, char *filename)
{
	int		fd;
	int		x;
	int		y;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(game, "Failure of opening map");
	y = 0;
	map_init(game);
	while (TRUE)
	{
		x = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line[x] && line[x] != '\n')
		{
			game->map[y][x] = line[x];
			x++;
		}
        game->map[y][x] = '\0';
		free(line);
		y++;
	}
	close(fd);
}

//save info before map in structure, not in map
//save max as for num rows
//save max as for num cols
void	check_maps_cols_rows(t_game *game, int fd)
{
	char	*line;
	int		len;

	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		len = ft_strlen(line);
		if (line == 0)
			break ;
		if (line[len - 1] == '\n')
			len--;
		free(line);
		if (game->map_info.cols < len)
			game->map_info.cols = len;
		game->map_info.rows += 1;
	}
	if (game->map_info.cols == 0 && game->map_info.rows == 0)
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
void	check_map(t_game *game, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	game->map_info.cols = 0;
	game->map_info.rows = 0;
	if (fd == -1)
		ft_error(game, "Failure of opening map");
	check_maps_cols_rows(game, fd);
	printf ("rows: %d, cols: %d\n", game->map_info.rows, game->map_info.cols);
	if (game->map_info.rows < 3)
		ft_error(game, "Map is not valid");
	close(fd);
}
