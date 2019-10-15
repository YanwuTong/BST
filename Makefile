# Makefile

CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

prog2: prog2.o stree.o
	${CXX} $^ -o $@

test1: test1.o stree.o
	${CXX} $^ -o $@

test2: test2.o stree.o
	${CXX} $^ -o $@

test3: test3.o stree.o
	${CXX} $^ -o $@

test4: test4.o stree.o
	${CXX} $^ -o $@

test5: test5.o stree.o
	${CXX} $^ -o $@



clean:
	/bin/rm -f *.o prog2 test1 test2 test3 test4 test5