/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:16:03 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/16 14:30:11 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*src1;

	src1 = (char *)src;
	i = 0;
	while (i < size && *dst)
	{
		dst++;
		i++;
	}
	if (i == size)
		return (i + ft_strlen((char *)src));
	j = 0;
	while (src1[j])
	{
		if (j < size - i - 1)
			*dst++ = src1[j];
		j++;
	}
	*dst = 0;
	return (j + i);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char dest[20];
    const char *src = "Hello";

    // Test 1: Normal case
    strcpy(dest, "Test ");
    size_t result1 = ft_strlcat(dest, src, sizeof(dest));
    printf("Result 1: %s, Length: %zu\n", dest, result1);

    // Test 2: Destination buffer too small
    strcpy(dest, "Short");
    size_t result2 = ft_strlcat(dest, src, 5);  // Only 5 characters available
    printf("Result 2: %s, Length: %zu\n", dest, result2);

    // Test 3: Empty destination
    dest[0] = '\0';
    size_t result3 = ft_strlcat(dest, src, sizeof(dest));
    printf("Result 3: %s, Length: %zu\n", dest, result3);

    // Test 4: Empty source
    strcpy(dest, "Test ");
    const char *emptySrc = "";
    size_t result4 = ft_strlcat(dest, emptySrc, sizeof(dest));
    printf("Result 4: %s, Length: %zu\n", dest, result4);
}*/