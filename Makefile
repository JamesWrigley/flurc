CXX=g++
CXXFLAGS=-c -Wall -std=c++11 -g

all: test

clean:
	rm *.o

test: test.o
	$(CXX) -o test test.o

test.o: tests/test.cpp src/flurc.hpp
	$(CXX) $(CXXFLAGS) tests/test.cpp -I src
