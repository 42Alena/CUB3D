/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:32:28 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/26 17:04:40 by dtolmaco         ###   ########.fr       */
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

// BIG ENDIAN
void	ft_mlx_put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t clr)
{
	size_t		pixel_offset;
	uint32_t	*pixel_ptr;
	uint32_t	new_color;

	new_color = ((clr >> 24) & 0xFF) \
	| ((clr << 8) & 0xFF0000) \
	| ((clr >> 8) & 0xFF00) \
	| ((clr << 24) & 0xFF000000);
	pixel_offset = (y * img->width + x) * sizeof(uint32_t);
	pixel_ptr = (uint32_t *)&img->pixels[pixel_offset];
	*pixel_ptr = new_color;
}

// LITTLE ENDIAN
// void	ft_mlx_put_pixel(mlx_image_t* img, uint32_t x, uint32_t y, uint32_t clr)
// {
//     size_t pixel_offset;
//     uint32_t* pixel_ptr;

//     pixel_offset = (y * image->width + x) * sizeof(uint32_t);
//     pixel_ptr = (uint32_t*)&image->pixels[pixel_offset];
//     *pixel_ptr = color;
// }