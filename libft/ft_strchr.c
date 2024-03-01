/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:58:29 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/15 17:16:42 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*s1;

	s1 = (char *)str;
	while (*s1)
	{
		if (*s1 == (unsigned char)c)
			return (s1);
		s1++;
	}
	if (c == 0)
		return (s1);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%s\n", strchr("noWayItWorks", 'W'));
    printf("%s\n", ft_strchr("noWayItWorks", 'W'));
}*/