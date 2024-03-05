NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
AR = ar rc

HEADER := -I ./include
SOURCES = get_next_line_utils.c get_next_line.c

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
