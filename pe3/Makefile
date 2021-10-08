CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall # flags for the compiler (use c++17 standards, turn on all optional warnings)

all: main

clean:
	rm main

main: #Point.o main.cpp
	$(CXX) $(CXXFLAGS) pe3_references.cpp -o main

#Point.o: Point.cpp
#	$(CXX) $(CXXFLAGS) -c Point.cpp