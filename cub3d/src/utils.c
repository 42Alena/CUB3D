/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:32:28 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/26 13:38:30 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

uint32_t	*get_color(mlx_texture_t *texture)
{
	int				i;
	unsigned int	pos;
	uint8_t			rgb[4];
	uint32_t		*colors;

	i = 0;
	colors = malloc(sizeof(uint32_t) * (texture->width + 1)
			* (texture->height + 1));
	pos = 0;
	while (pos < texture->width * texture->height * texture->bytes_per_pixel)
	{
		rgb[0] = texture->pixels[pos];
		rgb[1] = texture->pixels[pos + 1];
		rgb[2] = texture->pixels[pos + 2];
		rgb[3] = texture->pixels[pos + 3];
		colors[i] = (rgb[0] << 24) + (rgb[1] << 16) + (rgb[2] << 8) + rgb[3];
		pos += texture->bytes_per_pixel;
		i++;
	}
	return (colors);
}

int	distance_to_wall(t_player *player, char **saved_map, double x, double y)
{
	if (saved_map[(int)player->pos_y][(int)x] == '1' \
	|| saved_map[(int)y][(int)player->pos_x] == '1' \
	|| saved_map[(int)y][(int)player->pos_x] == '3' \
	|| saved_map[(int)player->pos_y][(int)x] == '3')
		return (FALSE);
	return (TRUE);
}

void	timer(mlx_image_t *image, int height, int width, double time)
{
	int			y;
	int			x;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			if (x < 1700 - time * TIMER_SPEED && x > 1000 && y > 50 && y < 100)
			{
				if (time * TIMER_SPEED > 500)
					mlx_put_pixel(image, x, y, 0xFF000099);
				else
					mlx_put_pixel(image, x, y, 0xFF000044);
			}
		}
	}
}

void	delete_player_from_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.saved_map[i])
	{
		j = 0;
		while (game->map.saved_map[i][j])
		{
			if (game->map.saved_map[i][j] == 'W' \
			|| game->map.saved_map[i][j] == 'E' \
			|| game->map.saved_map[i][j] == 'N' \
			|| game->map.saved_map[i][j] == 'S')
				game->map.saved_map[i][j] = '0';
			j++;
		}
		i++;
	}
}