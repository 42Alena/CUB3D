/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 03:30:13 by W2Wizard          #+#    #+#             */
/*   Updated: 2024/04/26 16:42:24 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"

// BUG: Linux may experience a red hue instead due to endianness
void mlx_draw_pixel(uint8_t* pixel, uint32_t color)
{
	 // Determine the system's endianness
    uint32_t endian_test = 1;
    uint8_t* endian_test_ptr = (uint8_t*)&endian_test;
    bool is_little_endian = (*endian_test_ptr == 1); // true if little endian

    // Store the color components into the pixel buffer based on endianness
    if (is_little_endian)
    {
        *(pixel++) = (uint8_t)(color >> 24); // Alpha
        *(pixel++) = (uint8_t)(color >> 16); // Red
        *(pixel++) = (uint8_t)(color >> 8);  // Green
        *(pixel++) = (uint8_t)(color & 0xFF); // Blue
    }
    else // Big endian
    {
        *(pixel++) = (uint8_t)(color & 0xFF); // Blue
        *(pixel++) = (uint8_t)(color >> 8);  // Green
        *(pixel++) = (uint8_t)(color >> 16); // Red
        *(pixel++) = (uint8_t)(color >> 24); // Alpha
    }
}

//= Public =//

void mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color)
{
	MLX_NONNULL(image);
	MLX_ASSERT(x < image->width, "Pixel is out of bounds");
	MLX_ASSERT(y < image->height, "Pixel is out of bounds");

	uint8_t* pixelstart = &image->pixels[(y * image->width + x) * BPP];
	mlx_draw_pixel(pixelstart, color);
}
