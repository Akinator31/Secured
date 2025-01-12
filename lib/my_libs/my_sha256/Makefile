##
## EPITECH PROJECT, 2024
## My stdlib
## File description:
## Makefile to make files
##

SRC		=	my_hash.c	\
			sigmas.c	\

OBJ		=	$(SRC:.c=.o)

NAME    =   my_sha256.a

CFLAGS += -Weverything -std=c2x -Wno-missing-variable-declarations
CFLAGS += -Wno-unsafe-buffer-usage -Wno-pre-c23-compat -Wno-vla -Wno-cast-qual

CC = clang

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
