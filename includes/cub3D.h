/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:37:52 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/04 15:10:52 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
// libft
# include "../libft/libft.h"
//MLX42
# include "../lib_mlx42/include/MLX42/MLX42.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define WIDTH 1920
#define HEIGHT 960

# define TRUE 1
# define FALSE 0

typedef struct s_game
{
	mlx_t*	mlx;
	mlx_image_t *image;
	double	player_x;
	double	player_y;
}	t_game;


//main


#endif