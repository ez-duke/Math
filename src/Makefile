CC=gcc -Wall -Werror -Wextra -ggdb3 -std=c11
SOURCES=*.c
OBJECTS=$(SOURCES:.c=.o)

all: s21_math.a

rebuild: clean all

clean:
	rm -rf *.o s21_math.a

cf:
	clang-format -style=Google -i $(SOURCES) s21_math.h 

check:
	clang-format -style=Google -n $(SOURCES) s21_math.h 

cppc:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES) s21_math.h 

test: s21_math.a
	

s21_math.a: $(SOURCES)
	$(CC) -c $(SOURCES)
	ar rcs s21_math.a $(OBJECTS)

gcov_report: test
	gcov report $(SOURCES)
