/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:28:06 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/18 11:44:25 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	sprite_height_width(t_game *game, int scale)
{
	game->sprite.sprite_height = \
	abs((int)(game->window_height / (game->sprite.transform_y)) / scale);
	game->sprite.draw_start_y = -game->sprite.sprite_height / 2 \
	+ game->window_height / 2 + game->sprite.v_move_screen;
	if (game->sprite.draw_start_y < 0)
		game->sprite.draw_start_y = 0;
	game->sprite.draw_end_y = game->sprite.sprite_height / 2 \
	+ game->window_height / 2 + game->sprite.v_move_screen;
	if (game->sprite.draw_end_y >= game->window_height)
		game->sprite.draw_end_y = game->window_height - 1;
	game->sprite.sprite_width = \
	abs((int)(game->window_height / (game->sprite.transform_y)) / scale);
	game->sprite.draw_start_x = -game->sprite.sprite_width / \
	2 + game->sprite.sprite_screen_x;
	if (game->sprite.draw_start_x < 0)
		game->sprite.draw_start_x = 0;
	game->sprite.draw_end_x = game->sprite.sprite_width / \
	2 + game->sprite.sprite_screen_x;
	if (game->sprite.draw_end_x >= game->window_width)
		game->sprite.draw_end_x = game->window_width - 1;
}

void	sprite_movement(t_game *game)
{
	game->sprite.sprite_x = 3.5 - game->player.pos_x;
	game->sprite.sprite_y = 3.5 - game->player.pos_y;
}

void	calculate_sprite(t_game *g)
{
	sprite_movement(g);
	g->sprite.v_move_screen = (int)((VMOVE * 1.5) / g->sprite.transform_y);
	g->sprite.inv_det = 1.0 / (g->player.plane_x * g->player.dir_y \
	- g->player.dir_x * g->player.plane_y);
	g->sprite.transform_x = g->sprite.inv_det * (g->player.dir_y \
	* g->sprite.sprite_x - g->player.dir_x * g->sprite.sprite_y);
	g->sprite.transform_y = g->sprite.inv_det * (-g->player.plane_y \
	* g->sprite.sprite_x + g->player.plane_x * g->sprite.sprite_y);
	g->sprite.sprite_screen_x = (int)((g->window_width / 2) \
	* (1 + g->sprite.transform_x / g->sprite.transform_y));
	sprite_height_width(g, 2);
}

void	draw_stripe(t_game *game, int stripe, int animation)
{
	uint32_t	color;
	int			y;

	y = game->sprite.draw_start_y;
	while (y < game->sprite.draw_end_y)
	{
		game->sprite.d = (y - game->sprite.v_move_screen) \
		* 256 - game->window_height * 128 + game->sprite.sprite_height * 128;
		game->sprite.tex_y = \
		((game->sprite.d * SPRITE_HEIGHT) / game->sprite.sprite_height) / 256;
		if (animation == 0)
			color = game->textures.c3po[SPRITE_WIDTH \
			* game->sprite.tex_y + game->sprite.tex_x];
		else if (animation == 1)
			color = game->textures.c3po2[SPRITE_WIDTH \
			* game->sprite.tex_y + game->sprite.tex_x];
		if ((color & 0x00FFFFFF) != 0)
			mlx_put_pixel(game->textures.image, stripe, y, color);
		y++;
	}
}

void	draw_sprites(t_game *game)
{
	int			stripe;
	int			animation;

	animation = 0;
	if ((int)mlx_get_time() % 2 == 0)
		animation = 1;
	calculate_sprite(game);
	stripe = game->sprite.draw_start_x;
	while (stripe < game->sprite.draw_end_x)
	{
		game->sprite.tex_x = (int)(256 * (stripe - (-game->sprite.sprite_width \
		/ 2 + game->sprite.sprite_screen_x)) \
		* 128 / game->sprite.sprite_width) / 256;
		if (game->sprite.transform_y > 0 && stripe > 0 && \
		stripe < game->window_width && \
		game->sprite.transform_y < game->ray.z_buffer[stripe])
			draw_stripe(game, stripe, animation);
		stripe++;
	}
}
