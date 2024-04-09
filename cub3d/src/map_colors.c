/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:00:39 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/04 17:41:38 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void save_map_color(t_game *game, char **name_color, char *line)
{
	int length_color_str;

	if (*name_color != NULL)
	{
		free(line);
		error_map_exit_game(game, "Map: double map settings for color");
	}
	length_color_str = ft_strlen(line) - 2;
	*name_color = ft_substr(line, 2, length_color_str);
	*name_color = ft_strtrim(*name_color, " ");
	if (*name_color == NULL)
		error_map_exit_game(game, "Missing map settings for color");
	length_color_str = ft_strlen(*name_color);
	if (length_color_str <= 6)
	{
		free(line);
		error_map_exit_game(game, "Invalid color texture");
	}
}

uint32_t	get_rgb_from_string(t_game *game, char *rgb_string)
{
	int	i;
	char **splited_colors;
	int	red;
	int	green;
	int blue;

	i = 0;
    splited_colors = ft_split(rgb_string, ',');
	while (splited_colors[i])
	{
		// printf("\nsplited_colors||%s||\n", splited_colors[i]);
		
		if (i >= 3)
			error_map_exit_game(game, "Not valid color");
		splited_colors[i] = ft_strtrim(splited_colors[i], " ");
		i++;
	}
	red =  get_color_from_string(game, splited_colors, 0);
	green =  get_color_from_string(game, splited_colors, 1);
	blue =  get_color_from_string(game, splited_colors, 2);
	free_double_array(splited_colors);
	return ((uint32_t)(red << 16| green << 8 | blue));
}


int get_color_from_string(t_game *game, char **splited_colors, int i)
{
	int	j;
	int color;
	
	j = 0;
	while (splited_colors[i][j])
	{
		if (!ft_isdigit(splited_colors[i][j]))
		{
			free_double_array(splited_colors);
			error_map_exit_game(game, "Not valid color");
		}
		j++;
	}
	color = ft_atoi(splited_colors[i]);
	if (color > 255)
	{
		free_double_array(splited_colors);	
		error_map_exit_game(game, "Not valid color");
	}
	return (color);
}