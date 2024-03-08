/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:02:10 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/08 18:07:27 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_map_structure(t_game *game)
{
	game->map.saved_map = NULL;
	game->map.cols = 0;
	game->map.rows = 0;
	game->map.n_texture = 0;
	game->map.s_texture = 0;
	game->map.w_texture = 0;
	game->map.e_texture = 0;
	game->map.floor_color = 0;
	game->map.ceiling_color = 0;
}

void	init_player_structure(t_game *game)
{
	////// version for tests
	game->player.pos_x = 2.5;
	game->player.pos_y = 1.5;
	game->player.dir_x = 0;
	game->player.dir_y = 1;
	game->player.plane_x = -0.66;
	game->player.plane_y = 0;
	/////////

	//version original
	// game->player.pos_x = 0;
	// game->player.pos_y = 0;
	// game->player.dir_x = 0;
	// game->player.dir_y = 0;
	// game->player.plane_x = 0;
	// game->player.plane_y = 0.66;
}


void	init_game_struct(t_game *game)
{
	mlx_texture_t	*wall;

	init_map_structure(game);
	init_player_structure(game);
	wall = mlx_load_png("./textures/ceiling.png");
	game->textures.wall_tex = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/wall3.png");
	game->textures.wall_tex2 = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/door.png");
	game->textures.wall_tex = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/windowspace.png");
	game->textures.wall_tex3 = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/starwall.png");
	game->textures.wall_tex4 = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/floor_new.png");
	game->textures.floor = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/ceiling.png");
	game->textures.ceiling = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/barrel2.png");
	game->textures.barrel = get_color(wall);
	mlx_delete_texture(wall);
	wall = mlx_load_png("./textures/c3po.png");
	game->textures.c3po = get_color(wall);
	mlx_delete_texture(wall);
	game->textures.cursor = mlx_load_png("./textures/cursor.png");
	game->textures.image = NULL;
	game->is_menu = TRUE;
	game->mouse.mouse_x = 0;
	game->mouse.mouse_y = 0;
	game->mlx = mlx_init(1920, 1080, "CUB3D", true);
	if (!game->mlx)
		ft_error(game, "Could not initialize MLX");
	mlx_get_monitor_size(0, &game->window_width, &game->window_height);
	printf("w:%d h:%d\n", game->window_width, game->window_height);
	xpm_t *xpm42 = mlx_load_xpm42("./textures/PLAY.xpm42");
	game->textures.main_menu = mlx_texture_to_image(game->mlx, &xpm42->texture);
	mlx_image_to_window(game->mlx, game->textures.main_menu, 0, 0);
	mlx_delete_xpm42(xpm42);
}



// void init_game_struct(t_game *game)
// {
// 	mlx_texture_t *wall;

// 	init_map_structure(game);
// 	init_player_structure(game);
// 	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/door.png");
// 	game->wall_tex = get_color(wall);
// 	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/wall3.png");
// 	game->wall_tex2 = get_color(wall);
// 	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/windowspace.png");
// 	game->wall_tex3 = get_color(wall);
// 	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/wall2.png");
// 	game->wall_tex4 = get_color(wall);
// 	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/floor.png");
// 	game->floor = get_color(wall);
// 	wall = mlx_load_png("/home/dtolmaco/Desktop/cub3D/src/ceiling.png");
// 	game->ceiling = get_color(wall);
// 	game->image = NULL;
// 	game->mlx = mlx_init(game->window_width, game->window_height, "CUB3D", true);
// 	if (!game->mlx)
// 		ft_error(game, "Could not initialize MLX");
// }
