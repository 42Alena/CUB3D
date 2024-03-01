/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:22:39 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/15 17:34:52 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen((char *)s))
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
