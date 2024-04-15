/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:37:52 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/14 10:56:26 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../../libft/libft.h"
#include "../../lib_gnl/include/get_next_line.h"
#include "../../lib_mlx42/include/MLX42/MLX42.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// minimap and bigmap //
#define WALL_WIDTH 15
#define WALL_HEIGHT 15
#define BIG_WALL_WIDTH 10
#define BIG_WALL_HEIGHT 10
//------------------------//

// game speed                  //
#define INITIAL_MOVE_SPEED 0.05
#define ROTATION_SPEED 0.1
#define TIMER_SPEED 20
//------------------------------//

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define VMOVE 128.0

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
} t_bool;

typedef struct s_mouse
{
	double mouse_x;
	double mouse_y;
} t_mouse;

typedef struct s_map
{
	char **saved_map;
	int cols;
	int rows;

//__________new
	char	*file_path;
	t_bool	fd_open;
	int		fd;
	char	*tmp_line;
	int		len_tmp_line;
	int		first_line;
	int		middle_line;
	int		last_line;
	int		count_player;
//_end new


	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	char *floor_color_str;
	uint32_t floor_color_uint;
	char *ceiling_color_str;
	uint32_t ceiling_color_uint;
} t_map;

typedef struct s_sprite
{
	double transform_x;
	double transform_y;
	double sprite_x;
	double sprite_y;
	double inv_det;
	int v_move_screen;
	int sprite_screen_x;
	int sprite_height;
	int sprite_width;
	int draw_start_y;
	int draw_start_x;
	int draw_end_y;
	int draw_end_x;
	int d;
	int tex_y;
	int tex_x;
} t_sprite;

typedef struct s_ray
{
	int map_x;
	int map_y;
	double camera_x;
	double step_x;
	double step_y;
	double side_dist_x;
	double side_dist_y;
	double ray_dir_x;
	double ray_dir_y;
	double delta_dist_x;
	double delta_dist_y;
	double perp_wall_dist;
	int hit;
	int side;
	int line_height;
	double draw_start;
	double draw_end;
	double wall_x;
	int tex_x;
	double step;
	double *z_buffer;
	int tex_num;
} t_ray;

typedef struct s_wall
{
	u_int32_t *north;
	int north_w;
	int north_h;
	u_int32_t *south;
	int south_w;
	int south_h;
	u_int32_t *west;
	int west_w;
	int west_h;
	u_int32_t *east;
	int east_w;
	int east_h;
} t_wall;

typedef struct so_textures
{
	mlx_image_t *image;
	u_int32_t *door;
	int door_w;
	int door_h;
	u_int32_t *door_open;
	int door_open_w;
	int door_open_h;
	u_int32_t *win_image;
	int win_image_w;
	int win_image_h;
	u_int32_t *c3po;
	int c3po_w;
	int c3po_h;
	u_int32_t *c3po2;
	u_int32_t *r2d2;
	mlx_texture_t *cursor;
	mlx_image_t *main_menu;
	mlx_image_t *end;
	mlx_image_t *congrats;
	mlx_image_t *settings05;
	mlx_image_t *settings1;
	mlx_image_t *settings2;
	t_wall wall;
} t_textures;

typedef struct s_player
{
	int count;
	char map_start_dir;
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
} t_player;

typedef struct s_game
{
	mlx_t *mlx;
	int window_width;
	int window_height;
	int is_menu;
	int is_settings;
	int is_map;
	int is_opened;
	int dead_cursor;
	int is_win;
	int end;
	double move_speed;
	t_textures textures;
	t_mouse mouse;
	t_map map;
	t_player player;
	t_sprite sprite;
	t_ray ray;
} t_game;

//___________TEST___FUNCTIONS___DELETE BEFORE PUSH__________
// map_prints_delete_for_intra.c 
void print_map_structure(t_game *game);
void print_map_pos_x_y(t_game *game);
void print_map(t_game *game);
//-------------END_TO TEST-------------------------------------------



// in main.c only main

// game_play.c (other functions from main)
void game_over(mlx_image_t *end, mlx_t *mlx, int *dead_cursor);
void win_screen(mlx_image_t *congrats, mlx_t *mlx, int *dead_cursor);
void gameplay(t_game *game, double time);
void ft_hook(void *param);



//___________map_file_save.c_______________
void	map_file_read_save(t_game *game);
void	change_char_newline_to_space(t_game *game);
void	map_file_allocate_memory(t_game *game);
t_bool	is_map_settings_complete(t_game *game);


//______map_game_save.c
void	save_map_in_struct(t_game *game);
void	save_map_info_in_struct(t_game *game);
void	check_map_file_characters(t_game *game);
void	save_map_info_lines_to_struct(t_game *game);


//______map_file_check.c
void	map_file_check(t_game *game, int argc, char **argv);
t_bool	is_valid_file(t_game *game, char *file_path);
void	fd_open(t_game *game);
void	fd_close(t_game *game);
void	gnl_free_tmp_line_set_null(t_game *game);


//______map_check.c______________
void	check_map(t_game *game);
void	check_maps_characters(t_game *game, int row);


//_________map_check_lines.c___________ 
t_bool	is_empty_tmp_line(t_game *game);
void	map_check_middle_lines(t_game *game); //WORKING HERE


//___________map_check_walls.c____________
void 	walls_check_save_in_struct(t_game *game);
t_bool	is_map_north_south_wall(t_game *game);


//______map_player_save.c________
void check_save_player(t_game *game, char c, int x, int y);
void save_player_pos_dir(t_game *game, int x, int y);
void save_player_struct(t_game *game, int x, int y);

//_______map_utils.c_______
t_bool is_substring(char *substring, char *string, int start, int len);
void length_tmp_line(t_game *game);

//_______game_init.c_________
void init_map_structure(t_game *game);
void init_player_structure(t_game *game);
void init_game_struct(t_game *game);

// map_visuals.c
void	draw_floor_ceiling(t_game *game, int x);
void wall_file_check_save(t_game *game, char **name_txtr);

// map_colors.c  
void save_map_color(t_game *game, char **name_color, char c_f);
uint32_t	get_rgb_from_string(t_game *game, char *rgb_string);
int get_color_from_string(t_game *game, char **splited_colors, int i);

//___free.c
// void free_double_char_pointer_array(char ***array);
void free_saved_map(t_game *game);
void free_double_array(char **array);
void free_map_struct(t_game *game);
void free_game(t_game *game);
void free_textures(t_game *game);
void free_mlx_img_txtr(t_game *game);

// error.c
void error_game_exit(t_game *game, char *error_msg);
void error_map_exit_game(t_game *game, char *error_msg);

// raycasting.c
void draw_floor_ceiling(t_game *game, int x);
void raycasting(t_game *game);

// raycasting_calculations.c
void calculate_start_end(t_game *game, int tex_height, int tex_width);
void hit_wall(t_game *game);
void calculate_step(t_game *game);
void init_ray(t_game *game, int i, int w);
void distance_and_height(t_game *game);

// textures.c
void load_images(t_game *game);
void load_textures(t_game *game);
void extra_textures(t_game *game);

// main_menu.c
void launch_game(t_game *game);
void back_to_main_menu(t_game *game);
void settings(t_game *game);
int move_speed(t_game *game);

// bigmap.c
void bigmap(t_game *game);

// minimap.c
void minimap(t_game *game);

// sprites.c
void draw_sprites(t_game *game);

// mouse.c
void cursor(double xpos, double ypos, void *param);
void mouse(mouse_key_t button, action_t action, modifier_key_t mods, void *param);

// utils.c
uint32_t *get_color(mlx_texture_t *texture);
int distance_to_wall(t_player *player, char **saved_map, double x, double y);
void timer(mlx_image_t *image, int height, int width, double time);

// key_press
void key_press(t_game *game);
void key_hook(mlx_key_data_t keydata, void *param);
void rotation(t_player *player, double rot_speed);

#endif
