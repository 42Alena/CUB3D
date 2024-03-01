/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:53:33 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/15 16:45:20 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}
/*
#include <stdio.h>
int main()
{
    char dest[] = "oldstring";
    const char src[] = "newstring";

    printf("Before memmove dest = %s, src = %s\n", dest, src);
    memmove(dest, src, 9);
    printf("After memmove dest = %s, src = %s\n", dest, src);

}*/