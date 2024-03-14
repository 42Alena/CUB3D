/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:28:58 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/13 23:16:40 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


void	ft_error(t_game *game, char *error_msg)
{
	int	len_error_msg;

	//TODO: add smth to emty in game
	(void)game;

	len_error_msg = ft_strlen(error_msg);
	write(2, "ERROR\n", 6);
	write(2, error_msg, len_error_msg);
	write(2, "\n", 1);

	//TODO: add smth to emty in game
	// if (&game->map != NULL)
	// {
    //     free_double_array(&game->map);
	// 	&game->map= NULL;
	// }

	exit(EXIT_FAILURE);
}

