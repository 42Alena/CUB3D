NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBMLX	:= ./MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT = libft
SANITAZER =  -fsanitize=address
SOURCES = src/main.c \

OBJECTS = $(SOURCES:.c=.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME) : $(OBJECTS)
		@make -C $(LIBFT)
		$(CC) $(CFLAGS) $(OBJECTS) -L./$(LIBFT) -lft $(LIBS) $(HEADERS) $(SANITAZER) -o $(NAME)

clean:
	rm -rf $(OBJECTS)
	rm -rf $(LIBFT)/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a

norm :
	@norminette ./includes/cub3D.h $(SOURCES)

re: fclean all

.PHONY: all clean fclean re