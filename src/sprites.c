/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:28:06 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/08 16:37:00 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	sprite_height_width(t_game *game)
{
	game->sprite.sprite_height = abs((int)(WINDOW_HEIGHT / (game->sprite.transform_y)) / 4);
	game->sprite.draw_start_y = -game->sprite.sprite_height / 2\
	 + WINDOW_HEIGHT / 2 + game->sprite.vMoveScreen;
	if(game->sprite.draw_start_y < 0)
		game->sprite.draw_start_y = 0;
	game->sprite.draw_end_y = game->sprite.sprite_height / 2\
	 + WINDOW_HEIGHT / 2 + game->sprite.vMoveScreen;
	if(game->sprite.draw_end_y >= WINDOW_HEIGHT)
		game->sprite.draw_end_y = WINDOW_HEIGHT - 1;
	game->sprite.sprite_width = abs((int)(WINDOW_HEIGHT / (game->sprite.transform_y)) / 4);
	game->sprite.draw_start_x = -game->sprite.sprite_width /\
	 2 + game->sprite.sprite_screen_x;
	if(game->sprite.draw_start_x < 0)
		game->sprite.draw_start_x = 0;
	game->sprite.draw_end_x = game->sprite.sprite_width /\
	 2 + game->sprite.sprite_screen_x;
	if(game->sprite.draw_end_x >= WINDOW_WIDTH)
		game->sprite.draw_end_x = WINDOW_WIDTH - 1;
}

void	calculate_sprite(t_game *game)
{
	game->sprite.sprite_x = 3.5 - game->player.pos_x;
	game->sprite.sprite_y = 3.5 - game->player.pos_y;
	game->sprite.inv_det = 1.0 / (game->player.plane_x * game->player.dir_y\
	- game->player.dir_x* game->player.plane_y);
	game->sprite.transform_x = game->sprite.inv_det * (game->player.dir_y\
	 * game->sprite.sprite_x - game->player.dir_x * game->sprite.sprite_y);
	game->sprite.transform_y = game->sprite.inv_det * (-game->player.plane_y\
	 * game->sprite.sprite_x + game->player.plane_x * game->sprite.sprite_y);
	game->sprite.vMoveScreen = (int)(VMOVE / game->sprite.transform_y);
	game->sprite.sprite_screen_x= (int)((WINDOW_WIDTH / 2)\
	 * (1 + game->sprite.transform_x / game->sprite.transform_y));
	sprite_height_width(game);
}

void	draw_sprites(t_game *game)
{
	uint32_t	color;
	int			stripe;
	int 		y;
	
	calculate_sprite(game);
	stripe = game->sprite.draw_start_x;
	y = game->sprite.draw_start_y;
	while (stripe < game->sprite.draw_end_x)
	{
		game->sprite.tex_x = (int)(256 * (stripe - (-game->sprite.sprite_width\
		 / 2 + game->sprite.sprite_screen_x)) * 128 / game->sprite.sprite_width) / 256;
		if(game->sprite.transform_y > 0 && stripe > 0 && stripe < WINDOW_WIDTH\
		 && game->sprite.transform_y < game->ray.ZBuffer[stripe])
		y = game->sprite.draw_start_y;
		while (y < game->sprite.draw_end_y)
		{
			game->sprite.d = (y-game->sprite.vMoveScreen)\
			 * 256 - WINDOW_HEIGHT * 128 + game->sprite.sprite_height * 128;
			game->sprite.tex_y = ((game->sprite.d * SPRITE_SIZE) / game->sprite.sprite_height) / 256;
			color = game->barrel[SPRITE_SIZE * game->sprite.tex_y + game->sprite.tex_x];
			if((color & 0x00FFFFFF) != 0)
				mlx_put_pixel(game->image, stripe, y, color);
			y++;
		}
		stripe++;
	}
}