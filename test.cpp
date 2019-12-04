#include <cassert>
// #include <limits>
#include "sibytes.hpp"

int main () {
	assert(sibytes(0) == "0 B");
	assert(sibytes(1) == "1 B");
	assert(sibytes(10) == "10 B");
	assert(sibytes(100) == "100 B");
	assert(sibytes(111) == "111 B");
	assert(sibytes(999) == "999 B");
	assert(sibytes(1000) == "1 kB");
	assert(sibytes(1100) == "1.1 kB");
	assert(sibytes(1077) == "1.077 kB");
	assert(sibytes(2222) == "2.222 kB");
	assert(sibytes(9999) == "9.999 kB");
	assert(sibytes(1e4L) == "10 kB");
	assert(sibytes(1e5L) == "100 kB");
	assert(sibytes(999999) == "999.999 kB");
	assert(sibytes(1000000) == "1 MB");
	assert(sibytes(1000001) == "1.000001 MB");
	assert(sibytes(162195527L) == "162.195527 MB");
	assert(sibytes(4444224444) == "4.444224444 GB");
	assert(sibytes(9555000000000000000UL) == "9.555 EB");

	assert(sibytes(17999999999999999999UL) == "17.999999999999999999 EB");
	assert(sibytes(18000000000000000000UL) == "18 EB");
	assert(sibytes(18000000000000000001UL) == "18.000000000000000001 EB");
	assert(sibytes(18100000000000000000UL) == "18.1 EB");

	// std::numeric_limits<unsigned long>::max()
	assert(sibytes(18446744073709551615UL) == "18.446744073709551615 EB");
	assert(sibytes(-1) == "18.446744073709551615 EB"); // probably U/B, don't do this

	return 0;
}
