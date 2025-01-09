##
## EPITECH PROJECT, 2024
## My stdlib
## File description:
## Makefile to make files
##

SRC		=	my_abs.c	\
			my_atof.c	\
			my_atoi.c	\
			my_atol.c	\
			my_calloc.c	\
			my_div.c	\
			my_itoa.c	\
			my_labs.c	\
			my_ldiv.c	\
			my_ltoa.c	\
			my_realloc.c	\
			my_strtod.c	\
			my_strtol.c	\

OBJ		=	$(SRC:.c=.o)

NAME    =   my_stdlib.a

CFLAGS 	+=	-Wall -Wextra -Werror -Wconversion -Wformat -Wshadow -Walloc-zero
CFLAGS	+=	-Wdouble-promotion -Wduplicated-branches -Wundef -Wunused-macros
CFLAGS	+=	-Wduplicated-cond -Wformat=2 -Wformat-signedness -Winit-self
CFLAGS	+=	-Wlogical-op -Wmissing-declarations -Wmissing-prototypes -Wpadded

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
