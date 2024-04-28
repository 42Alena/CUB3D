/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:00:39 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/26 12:20:55 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	save_map_color(t_game *game, char **name_color, char c_f)
{
	char	*tmp;

	if (*name_color != NULL)
		error_map_exit_game(game, "Map: double map settings for color");
	*name_color = ft_substr(game->map.tmp_line, 2, game->map.len_tmp_line - 2);
	tmp = ft_strtrim(*name_color, " ");
	free(*name_color);
	*name_color = tmp;
	if (*name_color == NULL)
		error_map_exit_game(game, "Missing map settings for color");
	game->map.len_tmp_line = ft_strlen(*name_color);
	if (game->map.len_tmp_line <= 4)
		error_map_exit_game(game, "Invalid color texture");
	if (c_f == 'c')
		game->map.ceiling_color_uint = \
		get_rgb_from_string(game, game->map.ceiling_color_str);
	else if (c_f == 'f')
		game->map.floor_color_uint = \
		get_rgb_from_string(game, game->map.floor_color_str);
}

uint32_t	get_final_color(t_game *game, char **splitted_colors)
{
	uint32_t	rgb_uint;

	rgb_uint = get_rgba(get_color_from_string(game, splitted_colors, 0), \
	get_color_from_string(game, splitted_colors, 1), \
	get_color_from_string(game, splitted_colors, 2), 255);
	free_double_array(splitted_colors);
	return (rgb_uint);
}

uint32_t	get_rgb_from_string(t_game *game, char *rgb_string)
{
	int			i;
	char		*tmp;
	char		**splitted_colors;

	i = -1;
	splitted_colors = ft_split(rgb_string, ',');
	while (splitted_colors[++i])
	{
		if (i >= 3)
		{
			free_double_array(splitted_colors);
			error_map_exit_game(game, "Not valid color");
		}
		tmp = ft_strtrim(splitted_colors[i], " ");
		free(splitted_colors[i]);
		splitted_colors[i] = tmp;
	}
	if (i != 3)
	{
		free_double_array(splitted_colors);
		error_map_exit_game(game, "Not valid color");
	}
	return (get_final_color(game, splitted_colors));
}

int	get_color_from_string(t_game *game, char **splited_colors, int i)
{
	int	j;
	int	color;

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
