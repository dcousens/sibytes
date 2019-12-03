#include <cassert>
#include "sibytes.hpp"

int main () {
	assert(sibytes(1) == "1 B");
	assert(sibytes(10) == "10 B");
	assert(sibytes(100) == "100 B");
	assert(sibytes(111) == "111 B");
	assert(sibytes(1000) == "1 kB");
	assert(sibytes(1077) == "1.077 kB");
	assert(sibytes(2222) == "2.222 kB");

	assert(sibytes(1e4L) == "10 kB");
	assert(sibytes(1e5L) == "100 kB");
	assert(sibytes(1e6L) == "1 MB");
	assert(sibytes(162195527L) == "162.1965527 MB");
	assert(sibytes(4444224444) == "4.444224444 GB");
	return 0;
}
