#include "static_string.h"

#include <iostream>

int main()
{
	constexpr std::array<char, 7> arr = { "World!" };

	constexpr cts::basic_static_string str = "Hello";
	constexpr cts::basic_static_string str2 = arr;
	constexpr cts::basic_static_string str3 = str2;
	constexpr auto str4 = str + str2;

	static_assert(!str.empty());
	static_assert(str.size() == 5);
	static_assert(str[2] == 'l');
	static_assert(str2 == str3);
	static_assert(str4 == cts::basic_static_string("HelloWorld!"));

	std::cout << str4.size() << '\n';
	std::cout << str4 << '\n';

	return 0;
}