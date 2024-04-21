/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:28:58 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/21 21:21:31 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void error_map_exit_game(t_game *game, char *error_msg)
{
	int len_error_msg;

	len_error_msg = ft_strlen(error_msg);
	write(2, "ERROR\n", 6);
	write(2, error_msg, len_error_msg);
	write(2, "\n", 1);
	if (game->map.fd_open)
	{
		while (TRUE)
		{
			game->map.tmp_line = get_next_line(game->map.fd);
			gnl_free_tmp_line_set_null(game);
			if (game->map.tmp_line == NULL)
				break ;
			free(game->map.tmp_line);
			game->map.tmp_line = NULL;
		}
		close(game->map.fd);
		game->map.fd_open = FALSE;
	}
	//IF TMP_LINE pointer without malloc -not free. just set to NULL
	free_map_struct(game);
	exit(EXIT_FAILURE);
}

void error_game_exit(t_game *game, char *error_msg)
{
	int len_error_msg;

	len_error_msg = ft_strlen(error_msg);
	write(2, "ERROR\n", 6);
	write(2, error_msg, len_error_msg);
	write(2, "\n", 1);
	free_game(game);
	exit(EXIT_FAILURE);
}
