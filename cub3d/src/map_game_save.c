/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_game_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:17:30 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/08 12:49:52 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"



/* 
row = first line of map
check if it firs_last_line(consisst only from spaces or 1)
 */
void extract_game_map_save(t_game *game, int first_line)
{
	int	last_line;
	// char *line;

	last_line = game->map.rows;
	// line = 
	// printf("game->map.saved_map[first_line]: ||%s||\n", game->map.saved_map[first_line]);
	if (is_map_first_last_line(game, first_line) == FALSE)
		error_map_exit_game(game, "Map: first line is not valid");

	//find last row (go from bottom to first line)
	while(is_empty_line(game->map.saved_map[last_line]))
		last_line -= 1;

	// printf(" first_line = %d,\n last_line = %d\n", first_line, last_line);
	if (last_line <= first_line + 1)
		error_map_exit_game(game, "Map: middle map is not valid");

	// printf("game->map.saved_map[last_line]: ||%s||\n", game->map.saved_map[last_line]);
	if ( is_map_first_last_line(game, last_line) == FALSE)
		error_map_exit_game(game, "Map: last line is not valid");
	// free_double_array(game->map.saved_map);

	//TODO: Here: start EXTRACTING GAME MAP
	extract_game_map(game, first_line, last_line);

}

void check_lines_game_map_file(t_game *game, int first_line, int last_line)
{
	int	x_start;
	int	x_end;
	char *temp_line;
	char	c;

	while(game->map.saved_map[first_line] && first_line < last_line)
	{
		temp_line = game->map.saved_map[first_line];
		if (is_empty_line(temp_line))
		{
			free (temp_line);
			error_map_exit_game(game, "Map: empty line");
		}
		x_start = 0;
		x_end = ft_strlen(temp_line);
		while (temp_line[x_start] && temp_line[x_start] == ' ')
				x_start++;
		while (temp_line[x_end] && temp_line[x_end] == ' ')
				x_start++;
		if (x_start != '1' && x_end != '1')
		{
			free (temp_line);
			error_map_exit_game(game, "Map: wall is missing");
		}
		//TODO: if in ow more thatn 1 outsie walls;
		// while (x_start  > x_end)
		// {
		// 	c = temp_line[x_start];
		// 	if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != 0 && c != 1)
		// 	{
		// 		free (temp_line);
		// 		error_map_exit_game(game, "Map: not allowed symbol in map");
		// 	}
		// 	x_start++;
		// }
		first_line++;
	}
}

int get_size_cols_game_map(t_game *game, int first_line, int last_line)
{
	int cols;
	int max_len;
	int start;

	cols = 0;
	max_len = 0;
	start = first_line;
	while(start <= last_line)
	{
		cols = ft_strmax_len(game->map.saved_map[start]);
		if (cols > max_len)
			max_len = cols;
		start++;
	}
	return(max_len);
}

void extract_game_map(t_game *game, int first_line, int last_line)
{
	int		start;
	int		cols;
	int		y;
	int		x;
	char	**temp_map;


	start = first_line;
	cols = get_size_cols_game_map(game, first_line, last_line);
	check_lines_game_map_file(game,  first_line, last_line);

	temp_map = (char **)malloc((last_line - first_line + 1) * sizeof(char *));
	if (temp_map == NULL)
		error_map_exit_game(game, "Map: memory allocation faled");
	while (start < last_line)
	{
		temp_map[start] = (char *)malloc((cols + 1) * sizeof(char));
		if (!temp_map[start])
		{
			y = -1;
			while (++y <= start)
				free(temp_map[y]);
			free(temp_map);
			error_map_exit_game(game, "Map: memory allocation failed");
		}
		temp_map[start][cols] = '\0';
		x = -1;
		while(game->map.saved_map[start][x])
		{
			temp_map[start][x] = game->map.saved_map[start][x];
			x++;
		}
		while(temp_map[start][x] && x < cols)
		{
			temp_map[start][x] = game->map.saved_map[start][x];
			x++;
		}
		start++;
		temp_map[start][x] =  '\0';
	}
	temp_map[start] = NULL;
	free_double_char_pointer_array(&game->map.saved_map);
	game->map.cols = cols;
	game->map.cols = last_line - first_line;

	//Copy from map
	game->map.saved_map = temp_map;
}