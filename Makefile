##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for my_printf project
##

SRC = $(shell find . -type f -name "*.c" ! -name "main.c")
INCLUDE_H := $(shell find include -type d)
INCLUDE = $(INCLUDE_H:%=-I%)
OBJ = 	$(SRC:%.c=build/%.o)
OBJ_TESTING = $(SRC:%.c=build-testing/%.o)
CFLAGS += 	-lcsfml-audio -lcsfml-graphics -lcsfml-window \
			-lcsfml-network -lcsfml-system -Wextra -Wall -lm $(INCLUDE)
TESTING_FLAGS = 	-fsanitize=address -g3 -lcsfml-audio -lcsfml-graphics \
				-lcsfml-window -lcsfml-network -lcsfml-system \
				-Wextra -Wall -lm $(INCLUDE)

LIB_NAME = libhashtable.a
TESTING_NAME = secured

build/%.o: %.c
		mkdir -p $(dir $@)
		gcc $(CFLAGS) -c $< -o $@

build-testing/%.o: %.c
		mkdir -p $(dir $@)
		gcc $(TESTING_FLAGS) -c $< -o $@

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	rm -f $(LIB_NAME)
	ar rc $(LIB_NAME) $(OBJ)

$(TESTING_NAME): $(OBJ_TESTING)
	rm -f $(LIB_NAME)
	ar rc $(LIB_NAME) $(OBJ_TESTING)
	gcc src/main.c -o $(TESTING_NAME) $(LIB_NAME) $(TESTING_FLAGS)

clean:
	$(shell find . -type f -name ".o" -delete)

fclean: clean
	rm -rf build
	rm -rf build-testing
	rm -f $(LIB_NAME)
	rm -f $(TESTING_NAME)
	rm -f coding-style-reports.log

re: fclean all
