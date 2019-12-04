#include <array>
#include <string>

const auto UNITS = std::array{
	"B",
	"kB",
	"MB",
	"GB",
	"TB",
	"PB",
	"EB"
};

const auto EXP = std::array{
	1UL,
	1000UL,
	1000000UL,
	1000000000UL,
	1000000000000UL,
	1000000000000000UL,
	1000000000000000000UL,
};

const auto FORMATS = std::array{
	"%lu.%.0lu",
	"%lu.%.3lu",
	"%lu.%.6lu",
	"%lu.%.9lu",
	"%lu.%.12lu",
	"%lu.%.15lu",
	"%lu.%.18lu",
};

inline std::string sibytes (const unsigned long number) {
	size_t unit;
	if (number < 1e3) unit = 0;
	else if (number < 1e6) unit = 1;
	else if (number < 1e9) unit = 2;
	else if (number < 1e12) unit = 3;
	else if (number < 1e15) unit = 4;
	else if (number < 1e18) unit = 5;
	else unit = 6;

	const auto left = number / EXP.at(unit);
	const auto right = number % EXP.at(unit);
	const auto unitp = UNITS.at(unit);
	auto buffer = std::array<char, 25>{ '\0' };
	auto bufferOut = std::array<char, 25>{ '\0' };

	auto count = 0;
	if (right == 0) {
		count = snprintf(buffer.data(), buffer.size(), "%lu", left);

	} else {
		count = snprintf(buffer.data(), buffer.size(), FORMATS.at(unit), left, right);

		// trim trailing zeros
		while (count > 0 and buffer.at(count - 1) == '0') {
			buffer.at(count - 1) = '\0';
			count--;
		}
	}

	count = snprintf(bufferOut.data(), bufferOut.size(), "%s %s", buffer.data(), unitp);
	return std::string(bufferOut.data(), count);
}
