/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:36:10 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/12 10:47:52 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_bool is_substring(char *substring, char *string, int start, int len)
{
    char *temp;
    t_bool  result;

    temp = ft_substr(string, start, len);
    // printf("is_substring:||%s||%s||%s||\n", substring, string,temp);
    if (temp == NULL)
        return FALSE;
    if (ft_strncmp(substring, temp, len) == 0)
        result = TRUE;
    else
        result = FALSE;
    if (temp)
        free(temp);
    return (result);
}
