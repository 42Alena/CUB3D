NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
SANITAZER =  -fsanitize=address
SOURCES = src/main.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
		@make -C $(LIBFT)
		$(CC) $(CFLAGS) $(OBJECTS) -L./$(LIBFT) -lft $(SANITAZER) -o $(NAME)

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