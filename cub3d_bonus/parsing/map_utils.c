/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:36:10 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/25 15:35:07 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_bool	is_substring(char *substring, char *string, int start, int len)
{
	char	*temp;
	t_bool	result;

	temp = ft_substr(string, start, len);
	if (temp == NULL)
		return (FALSE);
	if (ft_strncmp(substring, temp, len) == 0)
		result = TRUE;
	else
		result = FALSE;
	if (temp)
		free(temp);
	return (result);
}

void	length_tmp_line(t_game *game)
{
	game->map.len_tmp_line = 0;
	if (game->map.tmp_line == NULL)
		game->map.len_tmp_line = 0;
	while (game->map.tmp_line[game->map.len_tmp_line])
		game->map.len_tmp_line += 1;
}
