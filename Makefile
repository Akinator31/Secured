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

CFLAGS += 	-Wextra -Wall -lm $(INCLUDE)

TESTING_FLAGS = 	-fsanitize=address -g3	-Wextra -Wall -lm $(INCLUDE)

LIB_NAME = libhashtable.a

MY_LIB = my_libs.a

TESTING_NAME = secured

build/%.o: %.c
		@mkdir -p $(dir $@)
		@gcc $(CFLAGS) -c $< -o $@

build-testing/%.o: %.c
		@mkdir -p $(dir $@)
		@gcc $(TESTING_FLAGS) -c $< -o $@

all: $(LIB_NAME)

$(LIB_NAME): build_lib $(OBJ)
	@rm -f $(LIB_NAME)
	@ar rc $(LIB_NAME) $(MY_LIB) $(OBJ)

$(TESTING_NAME): build_lib $(OBJ_TESTING)
	@rm -f $(LIB_NAME)
	@ar rc $(LIB_NAME) $(MY_LIB) $(OBJ_TESTING)
	gcc src/main.c -o $(TESTING_NAME) $(LIB_NAME) $(TESTING_FLAGS)

build_lib:
	$(MAKE) -s -C lib/my_libs/
	@mv lib/my_libs/my_libs.a .

clean:
	$(shell find . -type f -name ".o" -delete)

fclean: clean
	rm -rf build
	rm -rf build-testing
	rm -f $(LIB_NAME)
	rm -f $(TESTING_NAME)
	rm -f coding-style-reports.log
	rm -f $(MY_LIB)

re: fclean all
