/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:11:04 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/04/26 12:25:32 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	load_doors(t_game *game)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./textures/door.png");
	game->textures.door = get_color(wall);
	game->textures.door_w = wall->width;
	game->textures.door_h = wall->height;
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/dooropen.png");
	game->textures.door_open = get_color(wall);
	game->textures.door_open_w = wall->width;
	game->textures.door_open_h = wall->height;
	mlx_delete_texture(wall);
}

void	extra_textures(t_game *game)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./textures/c3po.png");
	game->textures.c3po = get_color(wall);
	game->textures.c3po_w = wall->width;
	game->textures.c3po_h = wall->height;
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/c3po2.png");
	game->textures.c3po2 = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/win.png");
	game->textures.win_image = get_color(wall);
	game->textures.win_image_w = wall->width;
	game->textures.win_image_h = wall->height;
	mlx_delete_texture(wall);
	game->textures.cursor = mlx_load_png("./textures/cursor.png");
}

void	load_textures(t_game *game)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png(game->map.no_texture);
	game->textures.wall.north = get_color(wall);
	game->textures.wall.north_w = wall->width;
	game->textures.wall.north_h = wall->height;
	mlx_delete_texture(wall);
	wall = mlx_load_png(game->map.so_texture);
	game->textures.wall.south = get_color(wall);
	game->textures.wall.south_w = wall->width;
	game->textures.wall.south_h = wall->height;
	mlx_delete_texture(wall);
	wall = mlx_load_png(game->map.we_texture);
	game->textures.wall.west = get_color(wall);
	game->textures.wall.west_w = wall->width;
	game->textures.wall.west_h = wall->height;
	mlx_delete_texture(wall);
	wall = mlx_load_png(game->map.ea_texture);
	game->textures.wall.east = get_color(wall);
	game->textures.wall.east_w = wall->width;
	game->textures.wall.east_h = wall->height;
	mlx_delete_texture(wall);
	load_doors(game);
	extra_textures(game);
}

void	load_images(t_game *game)
{
	xpm_t	*xpm42;

	xpm42 = mlx_load_xpm42("./textures/PLAY.xpm42");
	game->textures.main_menu = mlx_texture_to_image(game->mlx, &xpm42->texture);
	mlx_image_to_window(game->mlx, game->textures.main_menu, 0, 0);
	mlx_delete_xpm42(xpm42);
	xpm42 = mlx_load_xpm42("./textures/settings1.xpm42");
	game->textures.settings1 = mlx_texture_to_image(game->mlx, &xpm42->texture);
	mlx_delete_xpm42(xpm42);
	xpm42 = mlx_load_xpm42("./textures/settings05.xpm42");
	game->textures.settings05 = \
	mlx_texture_to_image(game->mlx, &xpm42->texture);
	mlx_delete_xpm42(xpm42);
	xpm42 = mlx_load_xpm42("./textures/settings2.xpm42");
	game->textures.settings2 = mlx_texture_to_image(game->mlx, &xpm42->texture);
	mlx_delete_xpm42(xpm42);
	xpm42 = mlx_load_xpm42("./textures/no.xpm42");
	game->textures.end = mlx_texture_to_image(game->mlx, &xpm42->texture);
	mlx_delete_xpm42(xpm42);
	xpm42 = mlx_load_xpm42("./textures/congrats.xpm42");
	game->textures.congrats = mlx_texture_to_image(game->mlx, &xpm42->texture);
	mlx_delete_xpm42(xpm42);
}
