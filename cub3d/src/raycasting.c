/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:06:47 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/18 11:43:40 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

u_int32_t	*choose_texture(t_game *game)
{
	u_int32_t	*texture;

	game->ray.tex_num = game->map.saved_map[game->ray.map_y][game->ray.map_x];
	if ((char)game->ray.tex_num == '3')
		texture = game->textures.win_image;
	else if ((char)game->ray.tex_num == '2' && game->is_opened == FALSE)
		texture = game->textures.door;
	else if ((char)game->ray.tex_num == '2' && game->is_opened == TRUE)
		texture = game->textures.door_open;
	else if (game->ray.side == 0 && game->ray.ray_dir_x > 0)
		texture = game->textures.north;
	else if (game->ray.side == 0 && game->ray.ray_dir_x < 0)
		texture = game->textures.south;
	else if (game->ray.side == 1 && game->ray.ray_dir_y > 0)
		texture = game->textures.west;
	else
		texture = game->textures.east;
	return (texture);
}

void	draw_walls(t_game *game, int x)
{
	int			tex_y;
	int			y;
	double		tex_pos;
	uint32_t	color;
	u_int32_t	*texture;

	texture = choose_texture(game);
	tex_pos = (game->ray.draw_start - game->window_height / 2 \
	+ game->ray.line_height / 2) * game->ray.step;
	y = game->ray.draw_start;
	while (y < game->ray.draw_end)
	{
		tex_y = (int)tex_pos & (IMAGE_HEIGHT - 1);
		tex_pos += game->ray.step;
		color = texture[IMAGE_HEIGHT * tex_y - game->ray.tex_x];
		mlx_put_pixel(game->textures.image, x, y++, color);
	}
	game->ray.z_buffer[x] = game->ray.perp_wall_dist;
}

int	is_near(t_game *game, char c)
{
	int	y;
	int	x;

	x = (int)game->player.pos_x;
	y = (int)game->player.pos_y;
	if (game->player.dir_x > 0.5 && game->player.dir_x < 1 && \
	game->player.dir_y > -0.5 && game->player.dir_y < 0.5 && \
	game->map.saved_map[y][x + 1] == c)
		return (TRUE);
	else if (game->player.dir_x < -0.5 && game->player.dir_x > -1 && \
	game->player.dir_y > -0.5 && game->player.dir_y < 0.5 && \
	game->map.saved_map[y][x - 1] == c)
		return (TRUE);
	else if (game->player.dir_y > 0.5 && game->player.dir_y < 1 && \
	game->player.dir_x > -0.5 && game->player.dir_x < 0.5 && \
	game->map.saved_map[y + 1][x] == c)
		return (TRUE);
	else if (game->player.dir_y < -0.5 && game->player.dir_y > -1 && \
	game->player.dir_x > -0.5 && game->player.dir_x < 0.5 && \
	game->map.saved_map[y - 1][x] == c)
		return (TRUE);
	return (FALSE);
}

void	door_open_or_closed(t_game *game)
{
	game->ray.tex_num = game->map.saved_map[game->ray.map_y][game->ray.map_x];
	if (game->ray.tex_num == '3' && is_near(game, '3'))
		game->is_win = TRUE;
	if ((char)game->ray.tex_num == '2' && !is_near(game, '2'))
		game->is_opened = FALSE;
	else if ((char)game->ray.tex_num == '2' && is_near(game, '2'))
	{
		if (game->is_opened == FALSE)
			system("aplay -q ./music/door.wav &");
		game->is_opened = TRUE;
	}
}

void	raycasting(t_game	*game)
{
	int	x;

	x = 0;
	game->textures.image = \
	mlx_new_image(game->mlx, game->window_width, game->window_height);
	door_open_or_closed(game);
	while (x < game->window_width)
	{
		init_ray(game, x, game->window_width);
		calculate_step(game);
		hit_wall(game);
		distance_and_height(game);
		calculate_start_end(game);
		draw_walls(game, x);
		draw_floor_ceiling(game, x);
		x++;
	}
	mlx_image_to_window(game->mlx, game->textures.image, 0, 0);
}
