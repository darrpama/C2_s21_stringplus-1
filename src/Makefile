OS := $(shell uname -s)
CC = gcc
CFLAGS = -O2 -Wall -Wextra -Werror -std=c11

ifeq ($(OS), Darwin)
	CHKFLAGS := -lcheck
else
	CHKFLAGS = -lcheck -lrt -lm -lpthread -lsubunit
endif

all: clean s21_string.a test gcov_report

test1: s21_string.o s21_unit_test.o
	$(CC) $(CFLAGS) s21_string.o s21_unit_test.o -o test1.out $(CHKFLAGS)
	./test1.out

test: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o test.out $(CHKFLAGS)
	./test.out

s21_unit_test.o:
	$(CC)  -c unit_test.c -o s21_unit_test.o $(CHKFLAGS)

s21_string_test.o:
	checkmk clean_mode=1 tests.check > s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c -o s21_string_test.o $(CHKFLAGS)

gcov_report:
	$(CC) $(CFLAGS) --coverage -l check s21_string.c s21_string_test.c -o test
	./test
	lcov -t "./test" -o test.info -c -d .
	genhtml -o report test.info

clean: 
	rm -rf *.o *.gcda *.gcno *.out *.gch *.info
	rm -rf test
	rm -rf report

s21_string.a: s21_string.o 
	ar rc s21_string.a s21_string.o
	ranlib s21_string.a

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

install_lcov:
	brew install lcov

install_valgrind:
	brew install --HEAD LouisBrunner/valgrind/valgrind

install_cppcheck:
	brew install cppcheck

s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o $(CHKFLAGS)
