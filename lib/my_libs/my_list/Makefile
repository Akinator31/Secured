##
## EPITECH PROJECT, 2025
## My stdlib
## File description:
## Makefile to make files
##

SRC		=	my_add_data.c	\
			my_info_list.c	\
			my_remove_data.c \

OBJ		=	$(SRC:.c=.o)

NAME    =   my_list.a

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
