##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC =  $(shell find . -name "*.c")

OBJ =  $(SRC:.c=.o)

CFLAGS = -Wextra -Wall -lm -I.

NAME = my_printf.a

%.o: %.c
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

build: $(OBJ)

$(NAME): $(OBJ)
	@rm -f $(NAME)
	@ar rc $(NAME) $(OBJ)

clean:
	$(shell find . -type f -name "*.o" -delete)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
