CC=gcc
GCC_FLAGS=-Wall -Werror -Wextra -pedantic -g
VAL_FLAGS=--track-origins=yes --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 -s
SRC=*.c
NAME=hsh
RM=rm -f
TEST_FILE=run_tests.sh
LINTER_FILE=run_betty.sh

all: compile run remove

simple: compile
	./$(NAME)

build: lint compile test

lint:
	@echo "---------------------------------"
	@echo "Running linter..."
	@echo "---------------------------------"
	@./$(LINTER_FILE)

compile:
	@$(CC) $(GCC_FLAGS) $(SRC) -o $(NAME)
	@echo "Successfully compiled"

run:
	@valgrind $(VAL_FLAGS) ./$(NAME)

test:
	@echo "--------------------------------"
	@echo "Running tests..."
	@echo "--------------------------------"
	@./$(TEST_FILE)

remove:
	@$(RM) $(NAME)
