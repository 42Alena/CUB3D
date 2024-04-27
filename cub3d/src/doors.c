/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:31:58 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/04/27 12:09:09 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	is_near(t_game *game, char c)
{
	int	y;
	int	x;

	x = (int)game->player.pos_x;
	y = (int)game->player.pos_y;
	if (game->player.dir_x > 0.5 && game->player.dir_x < 1 && \
	game->player.dir_y > -0.5 && game->player.dir_y < 0.5 && \
	game->map.saved_map[y][x + 1] == c)
		return (TRUE);
	else if (game->player.dir_x < -0.5 && game->player.dir_x > -1 && \
	game->player.dir_y > -0.5 && game->player.dir_y < 0.5 && \
	game->map.saved_map[y][x - 1] == c)
		return (TRUE);
	else if (game->player.dir_y > 0.5 && game->player.dir_y < 1 && \
	game->player.dir_x > -0.5 && game->player.dir_x < 0.5 && \
	game->map.saved_map[y + 1][x] == c)
		return (TRUE);
	else if (game->player.dir_y < -0.5 && game->player.dir_y > -1 && \
	game->player.dir_x > -0.5 && game->player.dir_x < 0.5 && \
	game->map.saved_map[y - 1][x] == c)
		return (TRUE);
	return (FALSE);
}

void	door_open_or_closed(t_game *game)
{
	game->ray.tex_num = game->map.saved_map[game->ray.map_y][game->ray.map_x];
	if (game->ray.tex_num == '3' && is_near(game, '3'))
		game->is_win = TRUE;
	if ((char)game->ray.tex_num == '2' && !is_near(game, '2'))
		game->is_opened = FALSE;
	else if ((char)game->ray.tex_num == '2' && is_near(game, '2'))
	{
		if (game->is_opened == FALSE)
			if (!game->sound_effects_off)
				system("aplay -q ./music/door.wav &");
		game->is_opened = TRUE;
	}
}
