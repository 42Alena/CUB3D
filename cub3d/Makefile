NAME  = cub3D
CC  = cc
CFLAGS  = -Wall -Wextra -Werror -ffast-math -I./include -I$(LIBMLX)/include
# FSANITIZE = -fsanitize=address
LIBMLX := ../lib_mlx42
LIBFT := ../libft
LIBGNL := ../lib_gnl
LIBS := $(LIBFT)/libft.a $(LIBGNL)/libgnl.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SOURCES_M  := \
	./parsing/map_file_check.c\
	./parsing/map_file_save.c\
	./parsing/map_game_save.c\
	./parsing/map_check.c\
	./parsing/map_check_walls.c\
	./parsing/map_player_save.c\
	./parsing/map_visuals.c\
	./parsing/map_colors.c\
	./parsing/map_utils.c\
	./parsing/map_free.c\
    ./src/main.c\
	./src/game_init.c\
	./src/game_play.c\
	./src/error.c\
	./src/free.c\
	./src/raycasting.c\
	./src/raycasting_calculations.c \
	./src/mouse.c\
	./src/key_press.c\
	./src/textures.c\
	./src/utils.c\
	./src/floor_ceiling.c\
	./src/movement.c

OBJECTS := $(SOURCES_M:.c=.o)

$(NAME): $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a $(LIBGNL)/libgnl.a  $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) $(LIBGNL)/libgnl.a $(FSANITIZE) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJECTS)

fclean: clean
		$(RM) $(NAME)  $(NAME)
		@make -C $(LIBFT) fclean
		@make -C $(LIBGNL) fclean
		@rm -rf ../lib_mlx42/build/

re: fclean all

$(LIBMLX):
		@echo "Downloading MLX42 library..."; \
		git clone https://github.com/codam-coding-college/MLX42.git ../lib_mlx42; \
		rm -rf ../lib_mlx42/.git;

$(LIBMLX)/build/libmlx42.a: $(LIBMLX)
		@echo "Building mlx42..."
		@cd ../lib_mlx42; cmake  -DDEBUG=1 -B build; cmake --build build;

$(LIBFT)/libft.a:
		@echo "Compiling libft..."
		@make -C $(LIBFT)

  

$(LIBGNL)/libgnl.a:
	@echo "Compiling libgnl..."
	@make -C $(LIBGNL)

norm :
	@norminette ./include/cub3D.h $(SOURCES) 

.PHONY: all clean fclean re bonus
