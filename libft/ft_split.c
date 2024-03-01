/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:31:55 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/15 12:42:15 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != c && str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static void	ft_allocate(char **str, char const *s, char sep)
{
	char		**tab1;
	char const	*tmp;

	tmp = s;
	tab1 = str;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			*tab1 = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tab1;
		}
	}
	*tab1 = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**str;

	if (!s)
		return (NULL);
	len = ft_count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_allocate(str, s, c);
	return (str);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
    (void)argc;
    char **s;
    s = ft_split(argv[1], ',');
    printf("%s", s[0]);
    printf("%s", s[1]);
}*/