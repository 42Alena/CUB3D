/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:31:02 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/18 11:08:42 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_floor_ceiling(t_game *game, int x)
{
	uint32_t	color;
	int			y;

	y = game->ray.draw_end + 1;
	while (y < game->window_height)
	{
		color = get_rgba(200, 200, 200, 255);
		mlx_put_pixel(game->textures.image, x, y, color);
		color = get_rgba(0, 0, 0, 255);
		mlx_put_pixel(game->textures.image, x, game->window_height - y, color);
		y++;
	}
}
