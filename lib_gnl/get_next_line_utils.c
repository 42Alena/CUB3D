/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:17:38 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 08:39:17 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/get_next_line.h"

size_t	ft_gnl_strlen(char const *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_gnl_strjcopy(char *str, int str_i, char const *s, int s_len)
{
	int	s_i;

	s_i = 0;
	while (s_len)
	{
		str[str_i] = s[s_i];
		str_i++;
		s_i++;
		s_len--;
	}
	return (str);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_gnl_strlen(s1);
	s2_len = ft_gnl_strlen(s2);
	str = malloc(sizeof(char ) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	ft_gnl_strjcopy(str, 0, s1, s1_len);
	ft_gnl_strjcopy(str, s1_len, s2, s2_len);
	str[s1_len + s2_len] = 0;
	return (str);
}

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_gnl_strlen(s);
	if (start > s_len)
		return (ft_gnl_strdup(""));
	if (len > s_len - start)
		substr = (char *) malloc (s_len - start + 1);
	else
		substr = (char *) malloc (len + 1);
	if (!substr)
		return (NULL);
	while (s[i] && i < len)
		substr[i++] = s[start++];
	substr[i] = 0;
	return (substr);
}

char	*ft_gnl_strdup(const char *s)
{
	unsigned int					len_s;
	unsigned int					i;
	char							*ret;

	len_s = ft_gnl_strlen(s);
	ret = (char *) malloc(len_s + 1);
	i = 0;
	if (ret == NULL)
		return (NULL);
	while (i <= len_s)
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}
