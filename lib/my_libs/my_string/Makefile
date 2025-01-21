##
## EPITECH PROJECT, 2024
## my_string
## File description:
## Makefile to make files
##

SRC		=	my_memccpy.c	\
			my_memcmp.c	\
			my_memcpy.c	\
			my_memrcpy.c	\
			my_memset.c	\
			my_strcat.c	\
			my_strchr.c	\
			my_strcmp.c	\
			my_strcnb.c	\
			my_strcpy.c	\
			my_strcspn.c	\
			my_strdup.c	\
			my_strlen.c	\
			my_strncat.c	\
			my_strncmp.c	\
			my_strncpy.c	\
			my_strrev.c	\
			my_strtok.c	\

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
