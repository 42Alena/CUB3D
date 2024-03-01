/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:16:25 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/13 18:19:05 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	int		len;
	int		i;
	char	*new;

	len = ft_strlen((char *)str1);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = str1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    printf("%s\n", ft_strdup("hello"));
    printf("%s\n", strdup("hello"));
}*/