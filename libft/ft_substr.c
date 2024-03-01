/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:51:09 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/28 11:33:12 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*new;

	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	size = ft_strlen(start + (char *)s);
	if (size < len)
		len = size;
	new = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}
/*
#include <stdio.h>
int main()
{
	printf("%s\n",ft_substr("Red Hot Chili Peppers", 4, 12));
}*/
