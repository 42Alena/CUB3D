/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 07:11:41 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/12 21:33:07 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void free_double_array(char **array)
{
	int i;

	i = 0;
	if (array == NULL)
        return ;
	while (array[i])
	{	
		free(array[i]);
		array[i] = NULL;
		i++;		
	}
	free(array);
	array = NULL;
}

void free_saved_map(t_game *game)
{
	int i;

	i = 0;
	if (game->map.saved_map == NULL)
        return ;
	while (game->map.saved_map[i])
	{	
		// printf("free||i=%d||%s||\n", i, game->map.saved_map[i]);
		// free(game->map.saved_map[i]);
		game->map.saved_map[i] = NULL;
		i++;		
	}
	free(game->map.saved_map);
	game->map.saved_map = NULL;
}

void free_ptr_double_array(char ***array_ptr)
{
    char **array = *array_ptr;
    int i = 0;

    if (array == NULL)
        return;

    while (array[i] != NULL)
    {
		// printf("free||i=%d||%s||\n", i, array[i] );
        free(array[i]);
        array[i] = NULL;
        i++;
    }
    // free(array);
    *array_ptr = NULL; // Update the original pointer to NULL
}

void free_map_struct(t_game *game)
{
	// free_double_array(game); //must be pointer
	if (game->map.tmp_line)
		free(game->map.tmp_line);
	if (game->map.no_texture)
		free(game->map.no_texture);
	if (game->map.so_texture)
		free(game->map.so_texture);
	if (game->map.we_texture)
		free(game->map.we_texture);
	if (game->map.ea_texture)
		free(game->map.ea_texture);
	if (game->map.floor_color_str)
		free(game->map.floor_color_str);
	if (game->map.ceiling_color_str)
		free(game->map.ceiling_color_str);
	free_saved_map(game);
	// free_ptr_double_array(&(game->map.saved_map));
}


void free_game(t_game *game)
{
	free_map_struct(game);
	free_mlx_img_txtr(game);
	free_textures(game);
	free(game->ray.z_buffer);
	system("pkill aplay");
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void free_textures(t_game *game)
{
	if (game->textures.c3po)
		free(game->textures.c3po);
	if (game->textures.c3po2)
		free(game->textures.c3po2);
	if (game->textures.door)
		free(game->textures.door);
	if (game->textures.door_open)
		free(game->textures.door_open);
	if (game->textures.wall.east)
		free(game->textures.wall.east);
	if (game->textures.wall.north)
		free(game->textures.wall.north);
	if (game->textures.wall.south)
		free(game->textures.wall.south);
	if (game->textures.wall.west)
		free(game->textures.wall.west);
	if (game->textures.win_image)
		free(game->textures.win_image);
}

void free_mlx_img_txtr(t_game *game)
{
	if (game->textures.image)
		mlx_delete_image(game->mlx, game->textures.image);
	if (game->textures.main_menu)
		mlx_delete_image(game->mlx, game->textures.main_menu);
	if (game->textures.settings1)
		mlx_delete_image(game->mlx, game->textures.settings1);
	if (game->textures.settings05)
		mlx_delete_image(game->mlx, game->textures.settings05);
	if (game->textures.settings2)
		mlx_delete_image(game->mlx, game->textures.settings2);
	if (game->textures.end)
		mlx_delete_image(game->mlx, game->textures.end);
	if (game->textures.congrats)
		mlx_delete_image(game->mlx, game->textures.congrats);
	
	//TODO: add check if cursor exist
	mlx_delete_texture(game->textures.cursor);
}