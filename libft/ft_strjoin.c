/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:22:44 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/16 14:27:07 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		len1;
	int		len2;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		new[len1 + i] = s2[i];
		i++;
	}
	new[len1 + len2] = '\0';
	return (new);
}
/*
#include <stdio.h>
int main()
{
	printf("%s\n", ft_strjoin("Hello", "World!"));
}*/
