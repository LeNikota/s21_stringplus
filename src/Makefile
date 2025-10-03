FLAGS = -Wall -Wextra -Werror -std=c11

SRC_C_FUNCTIONS = $(wildcard c_functions/*.c)
SRC_C_SHARP_FUNCTIONS = $(wildcard c#_functions/*.c)
SRC_SPRINTF = $(wildcard s21_sprintf/*.c)
SRC_SSCANF = $(wildcard s21_sscanf/*.c)

# All source files for the library
ALL_SRC = $(SRC_C_FUNCTIONS) $(SRC_C_SHARP_FUNCTIONS) $(SRC_SPRINTF) $(SRC_SSCANF)

# Generate object file paths (all in one directory)
ALL_OBJ = $(addprefix objects/,$(notdir $(ALL_SRC:.c=.o)))

TEST_SRC = $(wildcard tests/*.c) $(wildcard tests/c_functions/*.c) $(wildcard tests/c#_functions/*.c) $(wildcard tests/s21_sprintf/*.c) $(wildcard tests/s21_sscanf/*.c)
# TEST_SRC = $(shell find tests -name "*.c")

.PHONY: all clean format static_check test debugging leak gcov_report

all: format s21_string.a

object_dir:
	@mkdir -p objects

s21_string.a: $(ALL_OBJ) | object_dir
	@ar rcs $@ $^

objects/%.o: c_functions/%.c | object_dir
	@gcc $(FLAGS) $(TEST_FLAGS) -c $< -o $@

objects/%.o: c\#_functions/%.c | object_dir
	@gcc $(FLAGS) $(TEST_FLAGS) -c $< -o $@

objects/%.o: s21_sprintf/%.c | object_dir
	@gcc $(FLAGS) $(TEST_FLAGS) -c $< -o $@

objects/%.o: s21_sscanf/%.c | object_dir
	@gcc $(FLAGS) $(TEST_FLAGS) -c $< -o $@

clean:
	@rm -rf objects/ *.gcno *.gcda coverage* s21_string.a test_runner test test_debugging coverage_html coverage.info


# Testing
test: all
	@gcc $(FLAGS) $(TEST_FLAGS) -o test_runner tests/test_runner.c $(filter-out tests/test_runner.c,$(TEST_SRC)) -I. -L. -l:s21_string.a -lcheck -lsubunit -lm
	@./test_runner

debugging:
	@gcc $(FLAGS) -o test_debugging $(ALL_SRC) $(filter-out tests/test_runner.c,$(TEST_SRC)) -I. -lcheck -lsubunit -lm -g

leak: all
	@gcc $(FLAGS) -o test_runner tests/test_runner.c $(filter-out tests/test_runner.c,$(TEST_SRC)) -I. -L. -l:s21_string.a -lcheck -lsubunit -lm
	@valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all ./test_runner
#	@valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all --verbose ./test_runner

gcov_report: clean
	@mkdir -p objects
	@$(MAKE) test TEST_FLAGS="-fprofile-arcs -ftest-coverage"

	# Create directory for coverage data files
	@mkdir -p coverage_data
	# Copy coverage files to the coverage_data directory
	@find . -name "*.gcno" -exec mv {} coverage_data/ \; 2>/dev/null || true
	@find . -name "*.gcda" -exec mv {} coverage_data/ \; 2>/dev/null || true

	# Generate coverage report
	@lcov --capture --directory . --output-file coverage.info
	@genhtml coverage.info --output-directory coverage_html
	@echo "Coverage report generated in coverage_html/index.html"
	@echo "Coverage data files (.gcno, .gcda) copied to coverage_data/ directory"
	@if [ -x /usr/bin/xdg-open ]; then xdg-open ./coverage_html/index.html; \
	elif [ -x /usr/bin/open ]; then open ./coverage_html/index.html; \
	fi

# Formatting
format:
	@find $(git rev-parse --show-toplevel) \( -name "*.c" -o -name "*.h" \) | xargs clang-format -i

static_check:
	@find $(git rev-parse --show-toplevel) \( -name "*.c" -o -name "*.h" \) | xargs cppcheck --enable=all --suppress=missingIncludeSystem


# Comments

# $@ - Represents the name of the target of the rule.
# $< - Represents the first prerequisite (dependency) of the rule.
# $^ - Represents all the prerequisites (dependencies) of the rule, with duplicates removed.

# $(wildcard pattern) - Finds all files that match the given pattern
# $(notdir pathlist) - Removes directory components from file paths
# $(addprefix prefix, names) - Adds a prefix to each item in a list
# $(filter-out pattern, text) - Removes items from a list that match the pattern
# $(var:suffix=replacement) - Replace a suffix in each word of a variable