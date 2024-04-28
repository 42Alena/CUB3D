/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:31:02 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/04/26 17:05:05 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_floor_ceiling(t_game *game, int x)
{
	int			y;

	y = game->ray.draw_end + 1;
	while (y < game->window_height)
	{
		ft_mlx_put_pixel(game->textures.image, x, y, \
		game->map.floor_color_uint);
		ft_mlx_put_pixel(game->textures.image, x, \
		game->window_height - y, game->map.ceiling_color_uint);
		y++;
	}
}
