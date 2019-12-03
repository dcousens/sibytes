CFLAGS=-std=c++2a -pedantic -W -Wall
OFLAGS=-O3

test: test.cpp sibytes.hpp
	$(CXX) $(CFLAGS) $(OFLAGS) $< -o $@ && ./test


sibytes: sibytes.cpp sibytes.hpp
	$(CXX) $(CFLAGS) $(OFLAGS) $< -o $@

clean:
	rm sibytes test
