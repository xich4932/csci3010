CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: main #test

clean:
	rm main #test #ElectoralMap.o

main: main.cpp ElectoralMap.o 
	$(CXX) $(CXXFLAGS) main.cpp ElectoralMap.o -o main

test: test.cpp ElectoralMap.o 
	$(CXX) $(CXXFLAGS) test.cpp ElectoralMap.o -o test

ElectoralMap.o: ElectoralMap.cpp
	$(CXX) $(CXXFLAGS) -c ElectoralMap.cpp



