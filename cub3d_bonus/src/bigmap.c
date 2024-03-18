/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:23:48 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/18 11:07:45 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	draw_bigwall(t_game *game, int *draw_x, int draw_y, u_int32_t color)
{
	int	y;
	int	x;

	y = 0;
	while (y < BIG_WALL_HEIGHT)
	{
		x = 0;
		while (x < BIG_WALL_WIDTH)
		{
			mlx_put_pixel(game->textures.image, *draw_x + x, draw_y + y, color);
			x++;
		}
		y++;
	}
	*draw_x += BIG_WALL_WIDTH;
}

static void	choose_color(t_game *game, int y_window, int x)
{
	int	y;
	int	x_window;

	y = (int)game->player.pos_x - 20;
	x_window = 0;
	while (y < (int)game->player.pos_x + 20)
	{
		if (x < 0 || x >= game->map.rows || y >= game->map.cols || y < 0)
			draw_bigwall(game, &x_window, y_window, 0xFF000000);
		else if ((int)game->player.pos_x == y && (int)game->player.pos_y == x)
			draw_bigwall(game, &x_window, y_window, 0xFFFF00FF);
		else if (game->map.saved_map[x][y] && game->map.saved_map[x][y] == '1')
			draw_bigwall(game, &x_window, y_window, 0x808090FF);
		else if (game->map.saved_map[x][y] && (game->map.saved_map[x][y] == '0' \
		|| game->map.saved_map[x][y] == ' '))
			draw_bigwall(game, &x_window, y_window, 0x737373FF);
		else if (game->map.saved_map[x][y] && (game->map.saved_map[x][y] == '2' \
		|| game->map.saved_map[x][y] == '3'))
			draw_bigwall(game, &x_window, y_window, 0x000000FF);
		else
			draw_bigwall(game, &x_window, y_window, 0xFF000000);
		y++;
	}
}

void	bigmap(t_game *game)
{
	int	y_window;
	int	x;

	y_window = 0;
	x = (int)game->player.pos_y - 15;
	while (x < (int)game->player.pos_y + 15)
	{
		choose_color(game, y_window, x);
		y_window += BIG_WALL_HEIGHT;
		x++;
	}
}
