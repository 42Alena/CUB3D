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
	0 skip spaces till textr.png and after *strchr
	1 check if .png
	2 check if can be opened/accesable
	3 load png in struct
 */
void save_map_texture(t_game *game, char name_txtr, char x, char y)
{
	char *texture_path;
	int	path_start;
	int path_end;
	char	c;
	int	fd;

	texture_path = NULL;
	path_start = 0;
	path_end = game->map.cols;
	while (game->map.saved_map[y][path_end] == ' ')
			path_end--;
	if (path_end > game->map.cols - 4)
			ft_error(NULL, "Invalid path texture");
	else if ((game->map.saved_map[y][path_end - 3] != '.') && \
		(game->map.saved_map[y][path_end - 2] != 'p') && \
		(game->map.saved_map[y][path_end - 1] != 'n') && \
		(game->map.saved_map[y][path_end] != 'g'))
		ft_error(NULL, "Invalid texture extension: .png expected");		
	while (game->map.saved_map[y][x] == ' ')
			x++;
	path_start = x;
	while (x < game->map.cols)
	{
		c = game->map.saved_map[y][x];
		if (c != ' ' && c != '\n')
			ft_error(NULL, "Invalid path texture");		
		x++;
	}
	//save texture in string
	//TODO save texture_path from path_start till path_end
	texture_path = 

	///TODO check if texture exist and not emptY
	fd = open(texture_path, O_RDONLY);
	if (fd == -1)
		ft_error(game, "Failure of opening texture");

	//TODO save structure in struct
	if (name_txtr == )


}

void save_map_color(t_game *game, char *name_color, char x, char y)
{
	//add check  color converter	
	//skip spaces till textr.png and after *strchr



}

void	save_map_textures_and_colors(t_game *game, char *map_first_line)
{
	int		x;
	int		y;
	char	c;
	char	next_c;
	t_bool	check_space;

	y = 0;
	check_space = TRUE;
    while (y < game->map.rows - 6)
	{
        x = 0;
        while (x < game->map.cols)
		{
			while (game->map.saved_map[y][x] == ' ' && check_space)
				x++;
			c = game->map.saved_map[y][x];
			if (x + 1 < game->map.cols)
				next_c = game->map.saved_map[y][x + 1];		
			if (c == 'N' && next_c == 'O')
				save_texture_struct(game, "n_texture", x, y);
			else if (c == 'S' && next_c == 'O')
				save_texture_struct(game, "s_texture", x, y);
			else if (c == 'W' && next_c == 'E')
				save_texture_struct(game, "w_texture", x, y);
			else if (c == 'E' && next_c == 'A')
				save_texture_struct(game, "e_texture", x, y);
			else if (c == 'F' && next_c == ' ')
				save_map_color(game, "floor_color", x, y);
			else if (c == 'C' && next_c == ' ')
				save_map_color(game, "ceiling_color", x, y);
			else
				ft_error(NULL, "Failure load map visuals");	
            x++;
        }
        y++;
    }
	if (game->map.n_texture == NULL || game->map.s_texture == NULL || \
		game->map.w_texture == NULL || game->map.e_texture == NULL || \
		game->map.floor_color == NULL || game->map.ceiling_color == NULL)
		ft_error(game, "Map's requirements: Texture or color information is missing");
	*map_first_line = y;
}
