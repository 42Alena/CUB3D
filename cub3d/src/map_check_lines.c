/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:35 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/15 18:23:36 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_bool is_empty_tmp_line(t_game *game)
{
    int i;

    i = 0;
    if (game->map.tmp_line == NULL)
        return (TRUE);
    while (game->map.tmp_line[i])
    {
        if (game->map.tmp_line[i] != ' ' && game->map.tmp_line[i]!= '\n')
            return (FALSE);
        i++;
    }
    return (TRUE);
}
