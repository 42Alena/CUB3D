/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:36:10 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/08 20:07:40 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_bool is_substring(char *substring, char *string, int start, int len)
{
    char *temp;

    temp = ft_substr(string, start, len);
    // printf("is_substring:||%s||%s||%s||\n", substring, string,temp);
    if (temp == NULL)
        return FALSE;
    if (ft_strncmp(substring, temp, len) != 0)
    {
        free(temp);
        return FALSE;
    }
    if (temp != NULL)
        free(temp);
    return TRUE;
}
