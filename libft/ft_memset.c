/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:35:57 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/13 14:43:22 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*new;

	new = (char *)str;
	i = 0;
	while (i < n)
	{
		new[i] = c;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char buffer[21];

    ft_memset(buffer, 'A', 21);
	printf("%s\n", buffer);
    memset(buffer, 'B', 21);
    printf("%s\n", buffer);

}*/