##
## EPITECH PROJECT, 2024
## my_string
## File description:
## Makefile to make files
##

SRC		=	my_memcpy.c	\
			my_memrcpy.c	\
			my_memset.c	\
			my_strlen.c	\
			my_strdup.c \

OBJ		=	$(SRC:.c=.o)

NAME	=	my_string.a

CFLAGS += -Wall -Wextra

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(SRC) $(NAME)

build: $(OBJ)

$(NAME): build
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	$(NAME) all clean fclean re
