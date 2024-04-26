/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:11:16 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/04/26 12:13:23 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	draw_wall(t_game *game, int *draw_x, int draw_y, u_int32_t color)
{
	int	y;
	int	x;

	y = 0;
	while (y < WALL_HEIGHT)
	{
		x = 0;
		while (x < WALL_WIDTH)
		{
			mlx_put_pixel(game->textures.image, *draw_x + x, draw_y + y, color);
			x++;
		}
		y++;
	}
	*draw_x += WALL_WIDTH;
}

static void	choose_color(t_game *game, int x, int y_window)
{
	int	y;
	int	x_window;

	y = (int)game->player.pos_x - 8;
	x_window = game->window_width / 50;
	while (y < (int)game->player.pos_x + 8)
	{
		if (x < 0 || x >= game->map.rows || y >= game->map.cols || y < 0)
			x_window += WALL_WIDTH;
		else if ((int)game->player.pos_x == y && (int)game->player.pos_y == x)
			draw_wall(game, &x_window, y_window, 0xFFFF00FF);
		else if (game->map.saved_map[x][y] && game->map.saved_map[x][y] == '1')
			draw_wall(game, &x_window, y_window, 0x808090FF);
		else if (game->map.saved_map[x][y] && (game->map.saved_map[x][y] == '0' \
		|| game->map.saved_map[x][y] == ' '))
			x_window += WALL_WIDTH;
		else if (game->map.saved_map[x][y] && (game->map.saved_map[x][y] == '2' \
		|| game->map.saved_map[x][y] == '3'))
			draw_wall(game, &x_window, y_window, 0x000000FF);
		else
			x_window += WALL_WIDTH;
		y++;
	}
}

void	minimap(t_game *game)
{
	int	y_window;
	int	x;

	if (game->is_map)
		return (bigmap(game));
	y_window = game->window_height / 50;
	x = (int)game->player.pos_y - 5;
	while (x < (int)game->player.pos_y + 5)
	{
		choose_color(game, x, y_window);
		y_window += WALL_HEIGHT;
		x++;
	}
}
