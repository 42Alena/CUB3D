/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:16:34 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 08:41:59 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/get_next_line.h"

int	ft_check_newline(const char *s)
{
	int	i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
	{
		return (i);
	}
	return (-1);
}

char	*free_line(char **line)
{
	free(*line);
	*line = NULL;
	return (NULL);
}

char	*read_file(int fd, int *pos_newline, char **line)
{
	char	*buf;
	int		read_bytes;
	char	*temp1;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	*pos_newline = ft_check_newline((const char *)*line);
	read_bytes = BUFFER_SIZE;
	while (*pos_newline == -1 && read_bytes == BUFFER_SIZE && fd >= 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		temp1 = ft_gnl_strjoin((const char *) *line, buf);
		free(*line);
		*line = temp1;
		*pos_newline = ft_check_newline((const char *)*line);
	}
	free(buf);
	return (*line);
}

char	*cut_first_line(char **line, int pos_newline)
{
	char	*newline;
	char	*temp;
	int		temp_len;

	newline = ft_gnl_substr(*line, 0, pos_newline + 1);
	temp_len = ft_gnl_strlen(*line) - pos_newline - 1;
	if (temp_len > 0)
	{
		temp = ft_gnl_substr(*line, pos_newline + 1, temp_len);
		free(*line);
		*line = ft_gnl_strdup(temp);
		free(temp);
	}
	else
		free_line(line);
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*temp;
	int			pos_newline;

	if (fd < 0)
		return (NULL);
	if (!line)
		line = ft_gnl_strdup("");
	if (BUFFER_SIZE <= 0 || read_file(fd, &pos_newline, &line) == NULL)
		return (free_line(&line));
	if (pos_newline >= 0)
		return (cut_first_line(&line, pos_newline));
	if (*line == 0)
		return (free_line(&line));
	temp = ft_gnl_strdup(line);
	free_line(&line);
	return (temp);
}
