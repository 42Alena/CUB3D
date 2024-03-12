/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:11:16 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/12 14:49:57 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_wall(t_game *game, int draw_x, int draw_y, int wall_width, int wall_height, u_int32_t color)
{
	int	y;
	int	x;

	y = 0;
	while (y < wall_height)
	{
		x = 0;
		while (x < wall_width)
		{
			mlx_put_pixel(game->textures.image, draw_x + x, draw_y + y, color);
			x++;
		}
		y++;
	}
}

void	minimap(t_game *game)
{
	int	y_window;
	int	x_window;
	int	wall_width;
	int	wall_height;
	int	x;
	int	y;

	//wall_width = 10;
	//wall_height = 10;
	wall_width = (game->window_height / 6) / game->map.cols;
	wall_height = (game->window_height / 5) / game->map.rows;
	y_window = game->window_height / 30;
	y = 0;
	printf("y:%d\n", y);
	while (y < game->map.rows)
	{
		x = 0;
		x_window = game->window_width / 30;
		printf("y:%d\n", y);
		while (x < game->map.cols)
		{
			if ((int)game->player.pos_x == y && \
			(int)game->player.pos_y == x)
			{
				draw_wall(game, x_window, y_window, wall_width, wall_height, 0xFFFF00FF);
				x_window += wall_width;
			}
			else if (game->map.saved_map[y][x] == '1')
			{
				draw_wall(game, x_window, y_window, wall_width, wall_height, 0xFF0000FF);
				x_window += wall_width;
			}
			else if (game->map.saved_map[y][x] == '0' || game->map.saved_map[y][x] == 'N' \
			|| game->map.saved_map[y][x] == ' ')
			{
				draw_wall(game, x_window, y_window, wall_width, wall_height, 0xFF000022);
				x_window += wall_width;
			}
			else if (game->map.saved_map[y][x] == '2')
			{
				draw_wall(game, x_window, y_window, wall_width, wall_height, 0xFF000066);
				x_window += wall_width;
			}
			x++;
		}
		y_window += wall_height;
		y++;
	}
	//draw_rectangle(game);
}
