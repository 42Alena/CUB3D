/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:47:01 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 08:40:32 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*
Prototype: 
	char *get_next_line(int fd);
Parameters:
	fd: The file descriptor to read from
Return value: 
	Read line: correct behavior
	NULL: there is nothing else to read, or an error occurred

External functs.:
	 read, malloc, free
Description:
	Write a function that returns a line read from a 
	file descriptor
	If there is nothing else to read or if an error occurred, it should return NULL.
	Please note that the returned line should include the terminating \n character,
	except if the end of file was reached and does not end with a \n character.
*/
char	*get_next_line(int fd);

/*
int		ft_gnl_check_newline(const char *s);
*ft_gnl_check_newline - (locate \n in string)
function returns an index of  the first occurrence of the
character \0  in the string s, or -1, if \n not found.
*/
int		ft_check_newline(const char *s);

/* 
char	*free_line(char **line);
free(line) and set line=NULL
 */
char	*free_line(char **line);

/* 
char	*read_file(int fd, int *pos_newline, char **line);
ft to read from file descriptor
 */
char	*read_file(int fd, int *pos_newline, char **line);

/* 
char	*cut_first_line(char **line, int pos_newline);
cut first line from text and return newline 
 */
char	*cut_first_line(char **line, int pos_newline);

/* 
size_t	ft_gnl_strlen(char const *str);
counts length of the string
 */
size_t	ft_gnl_strlen(char const *str);

/* 
char	*ft_gnl_strjcopy(char *str, int str_i, char const *s, int s_len);
copyfunction from strjoin
 */
char	*ft_gnl_strjcopy(char *str, int str_i, char const *s, int s_len);

/*
*ft_gnl_strjoin(char const *s1, char const *s2)
Parameters
	s1: The prefix string.
	s2: The suffix string.
Return value
	The new string.
	NULL if the allocation fails.
External functs.
	 malloc
Description
	Allocates (with malloc(3)) and returns a new string,
	which is the result of the concatenation of ’s1’ and ’s2’.
*/
char	*ft_gnl_strjoin(char const *s1, char const *s2);

/*
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
Parameters
	s: The string from which to create the substring.
	start: The start index of the substring in the string ’s’.
	len: The maximum length of the substring.
Return value
	The substring.
	NULL if the allocation fails.
External functs.
	 malloc
Description
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.
*/
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);

/*
*ft_gnl_strdup()
returns a pointer to a new string which is a duplicate of the string s.
Memory for the new string  is  obtained  with malloc(3),
and can be freed with free(3).
RETURN VALUE
On  success,  the strdup() function returns a pointer to the duplicated
string.
It returns NULL if insufficient memory was available,
with erno set to indicate the cause of the error.
 */
char	*ft_gnl_strdup(const char *s);

#endif
