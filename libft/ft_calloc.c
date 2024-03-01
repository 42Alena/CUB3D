/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:05:58 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/15 18:06:34 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (n > 0 && SIZE_MAX / n < size)
	{
		return (NULL);
	}
	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
    int *ptr;
    int i;

    ptr = (int *)calloc(7, sizeof(int));
    for (i = 0; i < 9; ++i)
    {
        ptr[i] = i + 1;
    }
    printf("The elements of the array are: ");
    for (i = 0; i < 19; ++i)
    {
        printf("%d, ", ptr[i]);
    }
}*/