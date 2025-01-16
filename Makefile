##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for my_printf project
##

SRC = $(shell find . -type f -name "*.c" ! -name "main.c" ! -path "./tests/*")

SRC_TEST = $(shell find . -type f -name "*.c" ! -name "main.c")

INCLUDE_H := $(shell find include -type d)

INCLUDE = $(INCLUDE_H:%=-I%)

OBJ = 	$(SRC:%.c=build/%.o)

OBJ_DEBUG = $(SRC:%.c=build-debug/%.o)

OBJ_TEST = $(SRC:%.c=build-test/%.o)

CFLAGS += 	-Wextra -Wall -lm $(INCLUDE)

DEBUG_FLAGS = -fsanitize=address -g3 -Wextra -Wall -lm $(INCLUDE)

TESTING_FLAGS = --coverage -lgcov -lcriterion -lm $(INCLUDE)

LIB_NAME = libhashtable.a

MY_LIB = my_libs.a

DEBUG_NAME = debug

TESTING_NAME = test

build/%.o: %.c
		@mkdir -p $(dir $@)
		@gcc $(CFLAGS) -c $< -o $@

build-debug/%.o: %.c
		@mkdir -p $(dir $@)
		@gcc $(DEBUG_FLAGS) -c $< -o $@

build-test/%.o: %.c
		@mkdir -p $(dir $@)
		@gcc $(TESTING_FLAGS) -c $< -o $@

all: $(LIB_NAME)

$(LIB_NAME): build_lib $(OBJ)
	@rm -f $(LIB_NAME)
	@ar rc $(LIB_NAME) $(MY_LIB) $(OBJ)

$(DEBUG_NAME): build_lib $(OBJ_DEBUG)
	@rm -f $(LIB_NAME)
	@ar rc $(LIB_NAME) $(MY_LIB) $(OBJ_DEBUG)
	gcc src/main.c -o $(DEBUG_NAME) $(LIB_NAME) $(DEBUG_FLAGS)

tests_run: build_lib $(OBJ_TEST)
	@rm -f $(LIB_NAME)
	@ar rc $(LIB_NAME) $(MY_LIB) $(OBJ_TEST)
	gcc tests/criterion_tests.c tests/ht_insert_lines.c \
		-o $(TESTING_NAME) $(LIB_NAME) $(TESTING_FLAGS)
	./$(TESTING_NAME)

show_test: tests_run
	mkdir -p coverage
	gcovr -r . --html --html-details -o coverage/index.html
	firefox coverage/index.html

build_lib:
	$(MAKE) -s -C lib/my_libs/
	@mv lib/my_libs/my_libs.a .

clean:
	$(shell find . -type f -name "*.o" -delete)

fclean: clean
	rm -rf build
	rm -rf build-debug
	rm -rf build-test
	rm -f $(LIB_NAME)
	rm -f $(DEBUG_NAME)
	rm -f $(TESTING_NAME)
	rm -f coding-style-reports.log
	rm -f $(MY_LIB)
	rm -rf coverage
	$(shell find . -name "*.gcda" -delete)
	$(shell find . -name "*.gcno" -delete)

re: fclean all
