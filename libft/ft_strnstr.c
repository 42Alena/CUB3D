/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:57 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/15 16:05:45 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	if (*little == '\0')
		return ((char *)big);
	len_little = ft_strlen((char *)little);
	if (len_little == 0)
		return (0);
	while (*big && len_little <= len)
	{
		if (*big == *little && ft_strncmp(big, little, len_little) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
    printf("%s\n", ft_strnstr("noWayItWorks", "Way", 9));
}*/