CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: main

clean:
	rm main map_district.o

main: main.cpp map_district.o 
	$(CXX) $(CXXFLAGS) main.cpp map_district.o -o main

map_district.o: map_district.cpp
	$(CXX) $(CXXFLAGS) -c map_district.cpp

