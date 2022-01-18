#include "static_string.h"

#include <iostream>

int main()
{
	//constexpr std::array<char, 8> arr2 = { " World!" };
	//constexpr auto arr = cts::_helper::array_factory<char, 6>::request("Hello");
	//constexpr auto con = cts::_helper::array_factory<char, 13>::request(arr, arr2);

	constexpr cts::basic_static_string str = "Hello";
	constexpr cts::basic_static_string str2 = " World!";
	constexpr auto str4 = str + str2;
	constexpr auto str5 = str.reverse();

	static_assert(!str.empty());
	static_assert(str.size() == 5);
	static_assert(str[2] == 'l');
	static_assert(str != str2);
	static_assert(str4 == cts::basic_static_string("Hello World!"));

	std::cout << str5.size() << '\n';
	std::cout << str5 << '\n';

	return 0;
}