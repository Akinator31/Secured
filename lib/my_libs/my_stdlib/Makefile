##
## EPITECH PROJECT, 2024
## My stdlib
## File description:
## Makefile to make files
##

SRC		=	my_free.c	\
			my_malloc.c	\

OBJ		=	$(SRC:.c=.o)

NAME    =   my_stdlib.a

CFLAGS += -Wall -Wextra

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(SRC) $(NAME)

build: $(OBJ)

$(NAME): build
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
