/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:06:47 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/04/28 11:58:07 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

u_int32_t	*choose_wall(t_game *game, int *tex_height, int *tex_width)
{
	if (game->ray.side == 0 && game->ray.ray_dir_x > 0)
	{
		*tex_height = game->textures.wall.east_h;
		*tex_width = game->textures.wall.east_w;
		return (game->textures.wall.east);
	}
	else if (game->ray.side == 0 && game->ray.ray_dir_x < 0)
	{
		*tex_height = game->textures.wall.west_h;
		*tex_width = game->textures.wall.west_w;
		return (game->textures.wall.west);
	}
	else if (game->ray.side == 1 && game->ray.ray_dir_y > 0)
	{
		*tex_height = game->textures.wall.south_h;
		*tex_width = game->textures.wall.south_w;
		return (game->textures.wall.south);
	}
	else
	{
		*tex_height = game->textures.wall.north_h;
		*tex_width = game->textures.wall.north_w;
		return (game->textures.wall.north);
	}
}

u_int32_t	*choose_texture(t_game *game, int *tex_height, int *tex_width)
{
	game->ray.tex_num = game->map.saved_map[game->ray.map_y][game->ray.map_x];
	if ((char)game->ray.tex_num == '3')
	{
		*tex_height = game->textures.win_image_h;
		*tex_width = game->textures.win_image_w;
		return (game->textures.win_image);
	}
	else if ((char)game->ray.tex_num == '2' && game->is_opened == FALSE)
	{
		*tex_height = game->textures.door_h;
		*tex_width = game->textures.door_w;
		return (game->textures.door);
	}
	else if ((char)game->ray.tex_num == '2' && game->is_opened == TRUE)
	{
		*tex_height = game->textures.door_open_h;
		*tex_width = game->textures.door_open_w;
		return (game->textures.door_open);
	}
	else
		return (choose_wall(game, tex_height, tex_width));
}

void	draw_walls(t_game *game, int x, u_int32_t *texture, int tex_height)
{
	int			tex_y;
	int			y;
	double		tex_pos;
	uint32_t	color;

	tex_pos = (game->ray.draw_start - game->window_height / 2 \
	+ game->ray.line_height / 2) * game->ray.step;
	y = game->ray.draw_start;
	while (y < game->ray.draw_end)
	{
		tex_y = (int)tex_pos & (tex_height - 1);
		tex_pos += game->ray.step;
		color = texture[tex_height * tex_y - game->ray.tex_x];
		ft_mlx_put_pixel(game->textures.image, x, y++, color);
	}
	game->ray.z_buffer[x] = game->ray.perp_wall_dist;
}

void	raycasting(t_game	*game)
{
	int			x;
	int			tex_height;
	int			tex_width;
	u_int32_t	*texture;

	x = 0;
	game->textures.image = \
	mlx_new_image(game->mlx, game->window_width, game->window_height);
	while (x < game->window_width)
	{
		texture = choose_texture(game, &tex_height, &tex_width);
		init_ray(game, x, game->window_width);
		calculate_step(game);
		hit_wall(game);
		distance_and_height(game);
		calculate_start_end(game, tex_height, tex_width);
		draw_floor_ceiling(game, x);
		draw_walls(game, x, texture, tex_height);
		x++;
	}
	mlx_image_to_window(game->mlx, game->textures.image, 0, 0);
}
