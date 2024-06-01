##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

LIBRARY_NAME = libmy.a

HEADER_NAME = my.h

LIB_DIR = lib/my

NAME = my_paint

SRC	=	src/mypaint.c \
		src/event.c \
		src/buttons_event.c \
		src/update.c \
		src/init.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -g3 -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

all: $(NAME)

$(NAME): $(LIBRARY_NAME)
	gcc -o $(NAME) $(SRC) $(LIBRARY_NAME) $(CFLAGS)

$(LIBRARY_NAME): fclean
	@$(MAKE) -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIBRARY_NAME) $(LIBRARY_NAME)
	cp $(LIB_DIR)/$(HEADER_NAME) include/$(HEADER_NAME)

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	rm *.o

fclean:
	@$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(LIBRARY_NAME) *.o $(NAME) include/$(HEADER_NAME) $(NAME)

re: fclean all

.PHONY: build clean fclean re
