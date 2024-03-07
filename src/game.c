/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:32:28 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/07 12:21:54 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static uint32_t	*get_color(mlx_texture_t *texture)
{
	int				i;
	unsigned int	pos;
	uint8_t			rgb[4];
	uint32_t		*colors;

	i = 0;
	colors = malloc(sizeof(uint32_t) * (texture->width + 1)
			* (texture->height + 1));
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

void init_game_struct(t_game *game)
{
	mlx_texture_t *wall;

	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/door.png");
	game->wall_tex = get_color(wall);
	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/wall3.png");
	game->wall_tex2 = get_color(wall);
	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/windowspace.png");
	game->wall_tex3 = get_color(wall);
	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/wall2.png");
	game->wall_tex4 = get_color(wall);
	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/floor.png");
	game->floor = get_color(wall);
	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/ceiling.png");
	game->ceiling = get_color(wall);
	game->player.player_x = 2.5;
	game->player.player_y = 2.5;
	game->player.dir_x = 0;
	game->player.dir_y = -1;
	game->player.plane_x = -0.66;
	game->player.plane_y = 0;
	game->image = NULL;
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", true);
	if (!game->mlx)
		ft_error(game, "Could not initialize MLX");
}
