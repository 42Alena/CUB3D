/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:06:47 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/10 15:40:57 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

u_int32_t	*choose_texture(t_game *game)
{
	u_int32_t	*texture;

	game->ray.tex_num = game->map.saved_map[game->ray.mapX][game->ray.mapY];
	if (game->ray.side == 0 && game->ray.rayDirX > 0)
		texture = game->textures.textures[0];
	else if (game->ray.side == 0 && game->ray.rayDirX < 0)
		texture = game->textures.textures[1];
	else if (game->ray.side == 1 && game->ray.rayDirY > 0)
		texture = game->textures.textures[2];
	else
		texture = game->textures.textures[3];
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
		tex_y = (int)tex_pos;
		tex_pos += game->ray.step;
		color = texture[IMAGE_HEIGHT * tex_y + game->ray.tex_x];
		if ((color & 0x00FFFFFF) != 0)
			mlx_put_pixel(game->textures.image, x, y++, color);
	}
}

void	raycasting(t_game	*game)
{
	int	x;

	x = 0;
	game->textures.image = \
	mlx_new_image(game->mlx, game->window_width, game->window_height);
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
