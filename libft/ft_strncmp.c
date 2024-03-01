/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:46:13 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/15 17:18:15 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (i < n - 1 && s1[i] && s1[i] == s2[i])
		i++;
	if (n)
		return (s1[i] - s2[i]);
	else
		return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    printf("%d\n", ft_strncmp("hellb", "hella", 5));
    printf("%d\n", strncmp("hellb", "hella", 5));
}*/