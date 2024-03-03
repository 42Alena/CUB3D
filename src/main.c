/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/03 10:02:48 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#define WIDTH 1920
#define HEIGHT 960

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, 1920, 960);

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
    ft_memset(img->pixels, 200, img->width * img->height * 4);

    // Draw the image at coordinate (0, 0).
    mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
