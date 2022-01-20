#include "static_string.h"
#include "detail/index_sequence.h"
#include <iostream>

template<std::size_t... Idx>
static void print_sequence(cts::_helper::seq::index_sequence<Idx...>)
{
	((std::cout << Idx << ' '), ...);
}

int main()
{
	constexpr std::array<char, 28> arr2 = { "Heyy here Hello here World!" };
	constexpr auto arr = cts::_helper::array_factory<char, 5>::request<1, 4>(arr2);
	//constexpr auto con = cts::_helper::array_factory<char, 13>::request(arr, arr2);

	//print_sequence(cts::_helper::seq::make_index_subsequence<0, 7>{});

	constexpr cts::basic_static_string str = "Hello";
	constexpr cts::basic_static_string str2 = " World!";
	constexpr auto str4 = str + str2;
	constexpr auto str5 = str.substr<1, 4>();

	static_assert(!str.empty());
	static_assert(str.size() == 5);
	static_assert(str[2] == 'l');
	static_assert(str != str2);
	static_assert(str4 == "Hello World!");

	constexpr cts::basic_static_string str6 = "Heyy here Hello here World!";
	constexpr cts::basic_static_string needle = "here";

	std::cout << "Found " << "'" << needle << "'" << " at: " << str6.rfind<0>(needle) << "\n";
	//cts::_helper::rfind<9>(arr2, needle);

	std::cout << str5.size() << '\n';
	std::cout << str5 << '\n';

	return 0;
}