#include "static_string.h"

#include <iostream>

int main()
{
	constexpr std::array<char, 7> arr = { "World!" };

	constexpr cts::basic_static_string<6> str = "Hello";
	constexpr cts::basic_static_string<7> str2 = arr;
	constexpr cts::basic_static_string<7> str3 = str2;

	static_assert(!str.empty());
	static_assert(str3.size() == 6);

	return 0;
}