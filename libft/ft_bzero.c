/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:47:05 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/14 10:41:54 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    int i;
    char initial[] = "hello";
    ft_bzero(initial, 2);
    i = 0;
    while (i < 5)
    {
        if (initial[i] == 0)
            printf("0");
        else
            printf("%c", initial[i]);
        i++;
    }
    printf("\n");
    char test[] = "hello";
    bzero(test, 2);
    i = 0;
    while (i < 5)
    {
        if (test[i] == 0)
            printf("0");
        else
            printf("%c", test[i]);
        i++;
    }
}*/