/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:58:29 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/15 14:57:42 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s1;

	s1 = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			s1 = (char *)str;
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (s1);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%s\n", strrchr("noWayItWorks", 'W'));
    printf("%s\n", ft_strrchr("noWayItWorks", 'W'));
}*/