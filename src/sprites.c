/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:28:06 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/09 16:03:21 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	sprite_height_width(t_game *game, int scale)
{
	game->sprite.sprite_height = abs((int)(game->window_height / (game->sprite.transform_y)) / scale);
	game->sprite.draw_start_y = -game->sprite.sprite_height / 2\
	 + game->window_height / 2 + game->sprite.vMoveScreen;
	if(game->sprite.draw_start_y < 0)
		game->sprite.draw_start_y = 0;
	game->sprite.draw_end_y = game->sprite.sprite_height / 2\
	 + game->window_height / 2 + game->sprite.vMoveScreen;
	if(game->sprite.draw_end_y >= game->window_height)
		game->sprite.draw_end_y = game->window_height - 1;
	game->sprite.sprite_width = abs((int)(game->window_height / (game->sprite.transform_y)) / scale);
	game->sprite.draw_start_x = -game->sprite.sprite_width /\
	 2 + game->sprite.sprite_screen_x;
	if(game->sprite.draw_start_x < 0)
		game->sprite.draw_start_x = 0;
	game->sprite.draw_end_x = game->sprite.sprite_width /\
	 2 + game->sprite.sprite_screen_x;
	if(game->sprite.draw_end_x >= game->window_width)
		game->sprite.draw_end_x = game->window_width - 1;
}

void	calculate_sprite(t_game *game, int index)
{
	if (index == 0)
	{
		game->sprite.sprite_x = 3.5 - game->player.pos_x;
		game->sprite.sprite_y = 3.5 - game->player.pos_y;
		game->sprite.vMoveScreen = (int)(VMOVE / game->sprite.transform_y);
	}
	else if (index == 1)
	{
		game->sprite.sprite_x = 5.5 - game->player.pos_x;
		game->sprite.sprite_y = 3.5 - game->player.pos_y;
		game->sprite.vMoveScreen = (int)((VMOVE * 1.5) / game->sprite.transform_y);
	}
	game->sprite.inv_det = 1.0 / (game->player.plane_x * game->player.dir_y\
	- game->player.dir_x* game->player.plane_y);
	game->sprite.transform_x = game->sprite.inv_det * (game->player.dir_y\
	 * game->sprite.sprite_x - game->player.dir_x * game->sprite.sprite_y);
	game->sprite.transform_y = game->sprite.inv_det * (-game->player.plane_y\
	 * game->sprite.sprite_x + game->player.plane_x * game->sprite.sprite_y);
	game->sprite.sprite_screen_x= (int)((game->window_width / 2)\
	 * (1 + game->sprite.transform_x / game->sprite.transform_y));
	if (index == 0)
		sprite_height_width(game, 2);
	else if (index == 1)
		sprite_height_width(game, 3);
}

void	draw_sprites(t_game *game)
{
	uint32_t	color;
	int			stripe;
	int 		y;
	int			i;
	
	i = 0;
	while (i < 2)
	{
		calculate_sprite(game, i);
		stripe = game->sprite.draw_start_x;
		y = game->sprite.draw_start_y;
		while (stripe < game->sprite.draw_end_x)
		{
			game->sprite.tex_x = (int)(256 * (stripe - (-game->sprite.sprite_width\
			/ 2 + game->sprite.sprite_screen_x)) * 128 / game->sprite.sprite_width) / 256;
			if(game->sprite.transform_y > 0 && stripe > 0 && stripe < game->window_width\
			&& game->sprite.transform_y < game->ray.ZBuffer[stripe])
			y = game->sprite.draw_start_y;
			while (y < game->sprite.draw_end_y)
			{
				game->sprite.d = (y-game->sprite.vMoveScreen)\
				* 256 - game->window_height * 128 + game->sprite.sprite_height * 128;
				game->sprite.tex_y = ((game->sprite.d * SPRITE_HEIGHT) / game->sprite.sprite_height) / 256;
				if (i == 0)
					color = game->textures.c3po[SPRITE_WIDTH * game->sprite.tex_y + game->sprite.tex_x];
				else if (i == 1)
					color = game->textures.r2d2[SPRITE_WIDTH * game->sprite.tex_y + game->sprite.tex_x];
				if ((color & 0x00FFFFFF) != 0)
					mlx_put_pixel(game->textures.image, stripe, y, color);
				y++;
			}
			stripe++;
		}
		i++;
	}
}