FLAGS = -Wall -Wextra -Werror -std=c11 #-fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=unreachable
SRC = $(wildcard s21_*.c)
OBJ = $(SRC:.c=.o)
ifeq ($(MAKECMDGOALS), gcov_report)
    TEST_FLAGS = -fprofile-arcs -ftest-coverage
else
    TEST_FLAGS =
endif

all: s21_string.a

s21_string.a: $(OBJ)
	@ar rcs $@ $^

%.o: %.c
	@find $(git rev-parse --show-toplevel) \( -name "*.c" -o -name "*.h" \) | xargs clang-format -i
	@gcc $(FLAGS) $(TEST_FLAGS) -c $^ -o $@

clean:
	@rm -rf $(OBJ) *.gcno *.gcda coverage* s21_string.a a.out test test_debugging

format:
	@find $(git rev-parse --show-toplevel) \( -name "*.c" -o -name "*.h" \) | xargs clang-format -i

static_check:
	@find $(git rev-parse --show-toplevel) \( -name "*.c" -o -name "*.h" \) | xargs cppcheck --enable=all --suppress=missingIncludeSystem


test: all
	@gcc $(FLAGS) -o test test.c ./tests/*.c -L. -l:s21_string.a -lcheck -lsubunit -lm -lgcov
	@./test

debugging:
	@gcc $(FLAGS) -o test_debugging *.c ./tests/*.c -lcheck -lsubunit -lm -g

leak: all
	@gcc $(FLAGS) -o test test.c ./tests/*.c -L. -l:s21_string.a -lcheck -lsubunit -lm
	valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all ./test

gcov_report: clean test
	@lcov --capture --directory . --output-file coverage.info
	@genhtml coverage.info --output-directory coverage_html
	@open ./coverage_html/index.html
