NAME  = cub3D
CC  = cc
CFLAGS  = -Wall -Wextra -Werror -I./include -I$(LIBMLX)/include
LIBMLX := ./lib_mlx42
LIBFT := ./libft
LIBS := $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SOURCES_M  := \
    ./src/main.c\

OBJECTS := $(SOURCES_M:.c=.o)

$(NAME): $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a $(OBJECTS)
		$(CC) $(OBJECTS) $(LIBS) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJECTS)

fclean: clean
		$(RM) $(NAME)  $(NAME)
		@make -C $(LIBFT) fclean
		@rm -rf ./lib_mlx42/build/


$(LIBMLX):
		echo "Downloading MLX42 library..."; \
		git clone https://github.com/codam-coding-college/MLX42.git lib_mlx42; \
		rm -rf lib_mlx42/.git;

$(LIBMLX)/build/libmlx42.a: $(LIBMLX)
		@echo "Building mlx42..."
		@cd lib_mlx42; cmake  -DDEBUG=1 -B build; cmake --build build;

$(LIBFT)/libft.a:
		@echo "Compiling libft..."
		@make -C $(LIBFT)

norm :
	@norminette ./include/cub3D.h $(SOURCES) 
  
re: fclean all

.PHONY: all clean fclean re bonus



# NAME = cub3D
# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# LIBMLX	:= ./MLX42
# HEADERS	:= -I ./include -I $(LIBMLX)/include
# LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# LIBFT = libft
# SANITAZER =  -fsanitize=address
# SOURCES = src/main.c \

# OBJECTS = $(SOURCES:.c=.o)

# all: libmlx $(NAME)

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

# $(NAME) : $(OBJECTS)
# 		@make -C $(LIBFT)
# 		$(CC) $(CFLAGS) $(OBJECTS) -L./$(LIBFT) -lft $(LIBS) $(HEADERS) $(SANITAZER) -o $(NAME)

# clean:
# 	rm -rf $(OBJECTS)
# 	rm -rf $(LIBFT)/*.o

# fclean: clean
# 	rm -f $(NAME)
# 	rm -f $(LIBFT)/libft.a

# norm :
# 	@norminette ./includes/cub3D.h $(SOURCES)

# re: fclean all

# .PHONY: all clean fclean re