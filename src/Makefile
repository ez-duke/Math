CC=gcc -Wall -Werror -Wextra -ggdb3 -std=c11
SOURCES=functions/*.c
TEST_SOURCES=tests/*.c
OBJECTS=*.o
HEADERS=s21_math.h tests/s21_math_tests.h

all: s21_math.a

rebuild: clean all

clean:
	rm -rf s21_math.a build/*

cf:
	clang-format -style=Google -i $(SOURCES) $(TEST_SOURCES) $(HEADERS)

check:
	clang-format -style=Google -n $(SOURCES) $(TEST_SOURCES) $(HEADERS)

cppc:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES) $(TEST_SOURCES) $(HEADERS)

test: s21_math.a $(TEST_SOURCES)
	$(CC) -o build/s21_math_tests tests/*.c s21_math.a -lcheck -lm
	./build/s21_math_tests

s21_math.a: $(SOURCES)
	$(CC) -c $(SOURCES)
	ar rcs s21_math.a $(OBJECTS)
	rm -rf $(OBJECTS)

gcov_report: clean test
	gcov report $(TEST_SOURCES)
