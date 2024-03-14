/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:37:52 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/14 09:17:13 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/libft.h"
# include "../../lib_gnl/include/get_next_line.h"
# include "../../lib_mlx42/include/MLX42/MLX42.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
//open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define IMAGE_WIDTH 1024
# define IMAGE_HEIGHT 1024
// floor and ceiling size
# define F_WIDTH 512
# define F_HEIGHT 512
# define MOVE_SPEED 0.05
# define ROTATION_SPEED 0.1
# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3
# define VMOVE 128.0
# define SPRITE_WIDTH 128
# define SPRITE_HEIGHT 128

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_floor
{
	double	dist_wall;
	double	dist_player;
	double	current_dist;
	double	floor_x_wall;
	double	floor_y_wall;
	double	current_floor_x;
	double	current_floor_y;
	double	weight;
	int		tex_x;
	int		tex_y;

}	t_floor;

typedef struct s_map
{
	char	**saved_map;
	int		cols;
	int		rows;
	int		first_map_line;
	int		last_map_line;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	char	*floor_color;
	char	*ceiling_color;
}	t_map;

typedef struct s_ray
{
	int			map_x;
	int			map_y;
	double		camera_x;
	double		step_x;
	double		step_y;
	double		side_dist_x;
	double		side_dist_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			hit;
	int			side;
	int			line_height;
	double		draw_start;
	double		draw_end;
	double		wall_x;
	int			tex_x;
	double		step;
	int			tex_num;
}	t_ray;

typedef struct s_player
{
	int			count;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_player;

typedef struct s_textures
{
	mlx_image_t		*image;
	u_int32_t		*north;
	u_int32_t		*south;
	u_int32_t		*west;
	u_int32_t		*east;
}	t_textures;

typedef struct s_game
{
	mlx_t			*mlx;
	int				window_width;
	int				window_height;
	t_textures		textures;
	t_map			map;
	t_player		player;
	t_ray			ray;
}	t_game;

//raycasting.c
void	raycasting(t_game *game);

void	free_double_array(char **array);

//calculations_raycasting.c
void	calculate_start_end(t_game *game);
void	hit_wall(t_game	*game);
void	calculate_step(t_game *game);
void	init_ray(t_game *game, int i, int w);
void	distance_and_height(t_game *game);

//floor_ceiling.c
void	draw_floor_ceiling(t_game *game, int x);

//raycasting.c
void	distance_and_height(t_game *game);
void	init_ray(t_game *game, int i, int w);
void	calculate_step(t_game *game);
void	hit_wall(t_game *game);
void	calculate_start_end(t_game *game);
void	calculate_floor_ceiling(t_game *game, t_floor *floor);
void	draw_floor_ceiling(t_game *game, int x);
void	draw_walls(t_game *game, int x);
void	raycasting(t_game *game);

//game.c
uint32_t	*get_color(mlx_texture_t *texture);

//check_input.c 
int		check_input(int argc, char **argv);

// game_init.c 
void	init_map_structure(t_game *game);
void	init_player_structure(t_game *game);
void	init_game_struct(t_game *game);

//player_save.c
void	check_save_player(t_game *game, char c, int x, int y);
void	save_player_pos_dir(t_game *game, char player_dir, int x, int y);
void	save_player_struct(t_game *game, char player_dir, int x, int y);

//error.c
void	ft_error(t_game *game, char *error_msg);

//key_press
void	key_press(t_game *game);
void	rotation(t_game *game, double rot_speed);


//map_utils
t_bool safe_check_substring(char *substring, char *string, int start, int len);
t_bool is_empty_line(char *line);
t_bool is_map_middle_lines(t_game *game, int y);
t_bool is_map_walls_first_last_line(char *line);

//map_check
//////TO TEST
void	print_map_pos_x_y(t_game *game);
void	print_map(t_game *game);
///END_TO TEST////////////////

//map_check
void find_first_last_line(t_game *game);
int		check_input(int argc, char **argv);
void	print_map(t_game *game);
void	check_maps_characters(t_game *game);

//map visuals
void load_textures(t_game *game);

//map_save.c
void	map_allocate_memory(t_game *game);
void	map_read_save(t_game *game, char *filename);
void	is_valid_map(t_game *game);
void	get_size_map(t_game *game, char *filename);

#endif
