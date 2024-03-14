/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:52:02 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/14 06:38:01 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


/* NEW_WORKING */
int	check_input(int argc, char **argv)
{
	int fd;
	int	len_argv1;

	if (argc != 2)
		ft_error(NULL, "Missing Map File: <map_name>.cub");
	argv[1] = ft_strtrim(argv[1], " ");
	len_argv1 = ft_strlen(argv[1]);
	if (len_argv1 <= 4)
		ft_error(NULL, "Error map: <map_name>.cub");
	if (safe_check_substring(".cub", argv[1], len_argv1 - 5, 5))
			ft_error(NULL, "Invalid file extension: .cub expected");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
			ft_error(NULL, "Failure of opening  game map");
	return (0);
}