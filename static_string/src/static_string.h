#pragma once

#include <iostream>

class static_string
{
public:
	static_string() { std::cout << "static_string\n"; }
};

#include "static_string_impl.h"