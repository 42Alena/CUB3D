/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:31:36 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/15 17:14:46 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen((char *)src));
}
/*
#include <stdio.h>
int main(void)
{
    char dest[20];

    unsigned int len1 = ft_strlcpy(dest, "hello", 5);
    printf("Copy 5 - 1 char from hello = %s, len of hello is %d\n", dest, len1);

    unsigned int len2 = ft_strlcpy(dest, "terra", 3);
    printf("Copy 3 - 1 char from hello = %s, len of hello is %d\n", dest, len2);

    unsigned int len3 = ft_strlcpy(dest, "hello", 10);
    printf("Copy 10 - 1 char from hello = %s, len of hello is %d\n", dest, len3);
}*/