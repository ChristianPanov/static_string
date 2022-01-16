#include "static_string.h"

#include <iostream>

int main()
{
	constexpr cts::basic_static_string<6> str = "Hello";

	return 0;
}