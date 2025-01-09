##
## EPITECH PROJECT, 2024
## my_string
## File description:
## Makefile to make files
##

SRC		=	my_memchr.c	\
			my_memcmp.c	\
			my_memccpy.c	\
			my_memcpy.c	\
			my_memmove.c	\
			my_memset.c	\
			my_str_to_word_array.c	\
			my_strcat.c	\
			my_strncat.c	\
			my_strcmp.c	\
			my_strcnb.c	\
			my_strncmp.c	\
			my_strcpy.c	\
			my_strncpy.c	\
			my_strlen.c	\
			my_strspn.c	\
			my_strcspn.c	\
			my_strdup.c	\
			my_strchr.c	\
			my_strrchr.c	\
			my_strstr.c	\
			my_strpbrk.c	\
			my_strtok.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	my_string.a

CFLAGS 	+=	-Wall -Wextra -Werror -Wconversion -Wformat -Wshadow -Walloc-zero
CFLAGS	+=	-Wdouble-promotion -Wduplicated-branches -Wundef -Wunused-macros
CFLAGS	+=	-Wduplicated-cond -Wformat=2 -Wformat-signedness -Winit-self
CFLAGS	+=	-Wlogical-op -Wmissing-declarations -Wmissing-prototypes -Wpadded

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
