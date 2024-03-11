/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:28:58 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/11 11:05:46 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_error(t_game *game, char *error_msg)
{
	int	len_error_msg;

	len_error_msg = ft_strlen(error_msg);
	write(2, "ERROR\n", 6);
	write(2, error_msg, len_error_msg);
	write(2, "\n", 1);
	(void)game;
	exit(EXIT_FAILURE);
}
