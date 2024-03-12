/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visuals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:32:28 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/11 05:32:52 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

uint32_t *get_color(mlx_texture_t *texture)
{
	int i;
	unsigned int pos;
	uint8_t rgb[4];
	uint32_t *colors;

	i = 0;
	colors = malloc(sizeof(uint32_t) * (texture->width + 1) * (texture->height + 1));
	pos = 0;
	while (pos < texture->width * texture->height * texture->bytes_per_pixel)
	{
		rgb[0] = texture->pixels[pos];
		rgb[1] = texture->pixels[pos + 1];
		rgb[2] = texture->pixels[pos + 2];
		rgb[3] = texture->pixels[pos + 3];
		colors[i] = (rgb[0] << 24) + (rgb[1] << 16) + (rgb[2] << 8) + rgb[3];
		pos += texture->bytes_per_pixel;
		i++;
	}
	return (colors);
}

void load_textures(t_game *game)
{
	mlx_texture_t *wall;

	wall = mlx_load_png("./textures/wall.png");
	game->textures.north = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/wall2.png");
	game->textures.south = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/wall3.png");
	game->textures.west = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/wall4.png");
	game->textures.east = get_color(wall);
	mlx_delete_texture(wall);
}

/* 
save_map_texture:
	1. delete spaces on both sides

	2 check if .png
	2 check if can be opened/accesable
	4 load png in struct
 */

// 1. delete spaces on both sides
// 2. check if is no path or not  enougth place for valid path X.png
// check if .png extention
///TODO check if texture exist and not emptY
// void save_map_texture(t_game *game, char *struct_map_path, int y)
// {
// 	int		path_length;
// 	int		fd;
// 	char	*temp;

// 	game->map.saved_map[y] = ft_strtrim(game->map.saved_map[y], " ");
// 	path_length =  ft_strlen(game->map.saved_map[y]);
// 	if (path_length <= 5)
// 		ft_error(NULL, "Invalid path texture");
// 	temp = ft_substr(game->map.saved_map[y], path_length - 4, 4);
// 	if (ft_strncmp(".png", temp, 4) != 0)
// 	{
// 		free(temp);
// 		ft_error(NULL, "Invalid texture extension: .png expected");		
// 	}
// 	free(temp);
// 	printf("%s\n", game->map.saved_map[y]);
// 	fd = open(game->map.saved_map[y], O_RDONLY);
// 	if (fd == -1)
// 		ft_error(game, "Failure of opening texture");
// 	else
// 		struct_map_path = game->map.saved_map[y];
// }




t_bool safe_check_substring(char *substring, char *string, int start, int len)
{
	char	*temp;

	temp = ft_substr(string, start, len);
	if (ft_strncmp(substring, temp, len) != 0)
	{
		free(temp);
		return (FALSE);	
	}
	free(temp);
	return (TRUE);
}


// int get_rgba(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }
// TODO check if colors from 0 to 255
// void save_map_color(t_game *game, char *name_color, char *struct_map_color, int y)
// {
// 	int		color_length;
// 	int		fd;
// 	char	*temp_color;
	
// 	if (struct_map_color != -1)
// 		ft_error(NULL, "Double texture");
// 	temp_color = ft_strtrim(game->map.saved_map[y], " ");
// 	color_length =  ft_strlen(temp_color);
// 	if (color_length <= 6)
// 		ft_error(NULL, "Invalid color texture");
// 	if (!safe_check_substring(name_color, temp_color, 0, 2))
// 		return ;
// 	temp_color = ft_substr(temp_color, 0, 2);
// 	temp_color = ft_strtrim(temp_color, " ");

// 	// if (!safe_check_substring(".png", temp_color, color_length - 4, 4))
// 	// 	ft_error(NULL, "Invalid texture extension: .png expected");		
// 	printf("%s\n", temp_color);
// 	fd = open(temp_color, O_RDONLY);
// 	if (fd == -1)
// 		ft_error(game, "Failure of opening texture");
// 	else
// 		name_color = temp_color;



// 	// (r << 24 | g << 16 | b << 8 | a)
// }


void	check_save_map_texture(t_game *game, char *name_txtr, char *struct_map_path, int y)
{
	int		path_length;
	int		fd;
	char	*temp_path;
	
	if (struct_map_path != NULL)
		ft_error(NULL, "Double texture");
	temp_path = ft_strtrim(game->map.saved_map[y], " ");
	path_length =  ft_strlen(temp_path);
	if (path_length <= 8)
		ft_error(NULL, "Invalid path texture");
	if (!safe_check_substring(name_txtr, temp_path, 0, 3))
		return ;
	temp_path = ft_substr(temp_path, 3, path_length - 3);
	temp_path = ft_strtrim(temp_path, " ");
	if (!safe_check_substring(".png", temp_path, ft_strlen(temp_path) - 4, 4))
		ft_error(NULL, "Invalid texture extension: .png expected");		
	fd = open(temp_path, O_RDONLY);
	if (fd == -1)
		ft_error(game, "Failure of opening texture");
	else
		struct_map_path = temp_path;
	printf("%s\n", temp_path);
}


void	save_map_textures_and_colors(t_game *game)
{
	int		y;
	char *temp_line;
	y = 0;
	
    while (y < game->map.rows - 2)
	{
		temp_line = ft_strtrim(game->map.saved_map[y], " ");
		if (!safe_check_substring("NO", temp_line, 0, 2) && game->map.n_texture == NULL)
        	check_save_map_texture(game, "NO ", game->map.n_texture, y);
		else if (!safe_check_substring("SO", temp_line, 0, 2) && game->map.s_texture == NULL)
        	check_save_map_texture(game, "SO ", game->map.s_texture, y);
		else if (!safe_check_substring("WE", temp_line, 0, 2) && game->map.w_texture == NULL)
        	check_save_map_texture(game, "WE ", game->map.s_texture, y);
		else if (!safe_check_substring("EA", temp_line, 0, 2) && game->map.e_texture == NULL)
        	check_save_map_texture(game, "WE ", game->map.s_texture, y);
		else
			ft_error(NULL, "Double texture");
		
		// 	check_save_map_texture(game, "SO ", game->map.s_texture, y);
        // // else if (y == 'W' && y + 1 == 'E' && y + 2 == ' ')
		// 	check_save_map_texture(game, "WE ", game->map.w_texture, y);
        // else if (y == 'E' && y + 1 == 'A' && y + 2 == ' ')
		// 	check_save_map_texture(game, "EA ", game->map.e_texture, y);
		//TODO add color finder and check
			// else if (c == 'F' && next_c == ' ')
			// 	save_map_color(game, game->map.floor_color, y);
			// else if (c == 'C' && next_c == ' ')
			// 	save_map_color(game, game->map.ceiling_color, y);
        y++;
    }
	if (game->map.n_texture == NULL || game->map.s_texture == NULL || \
		game->map.w_texture == NULL || game->map.e_texture == NULL || \
		game->map.floor_color == NULL || game->map.ceiling_color == NULL)
			ft_error(game, "Map's requirements: Texture or color information is missing");
}

//FIRST VERSION
			//TODO: is it better to write struct path instaed of char name_txtr?
// void save_map_texture(t_game *game, char name_txtr, char x, char y)
// {
// 	int	path_start;
// 	int path_end;
// 	char	c;
// 	int	fd;

// 	path_start = 0;
// 	path_end = game->map.cols;
// 	// game->map.saved_map[y] = ft_strtrim(game->map.saved_map[y])
// 	while (game->map.saved_map[y][path_end] == ' ')
// 			path_end--;
// 	if (path_end > game->map.cols - 4)
// 			ft_error(NULL, "Invalid path texture");
// 	else if ((game->map.saved_map[y][path_end - 3] != '.') && \
// 		(game->map.saved_map[y][path_end - 2] != 'p') && \
// 		(game->map.saved_map[y][path_end - 1] != 'n') && \
// 		(game->map.saved_map[y][path_end] != 'g'))
// 		ft_error(NULL, "Invalid texture extension: .png expected");		
// 	while (game->map.saved_map[y][x] == ' ')
// 			x++;
// 	path_start = x;
// 	while (x < game->map.cols)
// 	{
// 		c = game->map.saved_map[y][x];
// 		if (c != ' ' && c != '\n')
// 			ft_error(NULL, "Invalid path texture");		
// 		x++;
// 	}
// 	//save texture in string
// 	//TODO save texture_path from path_start till path_end
// 	game->map.saved_map[y] = ft_substr(game->map.saved_map[y], path_start, path_end - path_start + 1);

// 	///TODO check if texture exist and not emptY
// 	fd = open(game->map.saved_map[y], O_RDONLY);
// 	if (fd == -1)
// 		ft_error(game, "Failure of opening texture");
// 	else
	


