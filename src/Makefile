FLAGS = -Wall -Wextra -Werror -std=c11 # -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=unreachable
SRC = $(wildcard s21_*.c)
OBJ = $(SRC:.c=.o)
ifeq ($(MAKECMDGOALS), gcov_report)
    TEST_FLAGS = -fprofile-arcs -ftest-coverage
else
    TEST_FLAGS =
endif

all: s21_string.a

s21_string.a: $(OBJ)
	ar rcs $@ $^

%.o: %.c
	gcc $(FLAGS) $(TEST_FLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ) *.gcno *.gcda coverage* s21_string.a a.out  test.c test

format:
	@find $(git rev-parse --show-toplevel) \( -name "*.c" -o -name "*.h" \) | xargs clang-format -i

test: all
	checkmk ./tests/*.check > test.c
	gcc test.c -o test -L. -l:s21_string.a -lcheck -lm -lsubunit -lgcov
	./test
#@find $(git rev-parse --show-toplevel) \( -name "*.c" -o -name "*.h" \) | xargs clang-format -n
#@find $(git rev-parse --show-toplevel) \( -name "*.c" -o -name "*.h" \) | xargs cppcheck --enable=all --suppress=missingIncludeSystem
#valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all ./s21_cat $flags $files 2>&1 | grep -E "ERROR"

gcov_report: clean test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage_html
	open ./coverage_html/index.html