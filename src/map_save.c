/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:20 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 12:06:57 by akurmyza         ###   ########.fr       */
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
		if (game->map == NULL)
		{
			j = -1;
            while (++j < i)
                free(game->map[j]);
            free(game->map);
			ft_error (game, "Map: memory allocation faled");
		}
	}
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
	printf("DONE: map_read \n");
}

//save info before map in structure, not in map
//save max as for num rows
//save max as for num cols
void	check_maps_cols_rows(t_game *game, int fd)
{
	char	*line;
	int		len;

	printf ("check_maps_cols_rows\n");
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
		// save maxim length of cols
		if (game->map_info.cols < len)
			game->map_info.cols = len;
		
		// if (len != game->map_info.cols)
		// 	ft_error(game, "Map is not rectangular");
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
	printf ("BEFORE check_maps_cols_rows\n");
	check_maps_cols_rows(game, fd);
	printf ("rows: %d, cols: %d\n", game->map_info.rows, game->map_info.cols);
	if (game->map_info.rows < 3)
		ft_error(game, "Map is not valid");
	close(fd);
}


// ???NOT WORKING CORRECT:
// static void map_init(t_game *game)
// {
//     int i = 0;
//     int j;

//     int rows = 0;
//     int max_cols = 0;
//     game->map = (char **)malloc(rows * sizeof(char *));
//     if (game->map == NULL)
//         ft_error(game, "Map: memory allocation failed");
//     while (game->map[i] != NULL)
//     {
//         int len = ft_strlen(game->map[i]);
//         if (len > max_cols)
//             max_cols = len;
//         rows++;
//         i++;
//     }

//     i = 0;
//     while (i < rows)
//     {
//         game->map[i] = (char *)malloc((max_cols + 1) * sizeof(char));
//         if (game->map[i] == NULL)
//         {
//             j = 0;
//             while (j < i)
//                 free(game->map[j++]);
//             free(game->map);
//             ft_error(game, "2Map: memory allocation failed");
//         }
//         i++;
//     }
// }
