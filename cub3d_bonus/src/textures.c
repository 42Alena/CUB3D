/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:11:04 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/18 11:11:12 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	extra_textures(t_game *game)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./textures/c3po.png");
	game->textures.c3po = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/c3po2.png");
	game->textures.c3po2 = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/door.png");
	game->textures.door = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/dooropen.png");
	game->textures.door_open = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/warning.png");
	game->textures.bottom_image = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/win.png");
	game->textures.win_image = get_color(wall);
	mlx_delete_texture(wall);
	game->textures.cursor = mlx_load_png("./textures/cursor.png");
}

void	load_textures(t_game *game)
{
	mlx_texture_t	*wall;

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
	wall = mlx_load_png("./textures/floor_new.png");
	game->textures.floor = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/ceiling.png");
	game->textures.ceiling = get_color(wall);
	mlx_delete_texture(wall);
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
