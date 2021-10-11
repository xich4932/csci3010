CXX = g++
CXXFLAGS	= -std=c++17 -Wall
CXXTESTFLAGS = --coverage # can be used to generate files that help calculate unit test coverage
CXXGDB = -ggdb

all: main #cov

clean:
	rm test # Rectangle.o (because you can't recompile this one!)

main: Counter.o test.cpp
	$(CXX) $(CXXFLAGS) test.cpp Counter.o -o test

cov: Rectangle.o test.cpp
	$(CXX) $(CXXFLAGS) $(CXXTESTFLAGS) test.cpp Rectangle.o -o test