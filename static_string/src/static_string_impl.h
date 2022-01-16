#pragma once

#include "static_string.h"
#include "static_string_helper.h"

namespace cts
{
	template<std::size_t Size>
	template<std::size_t N>
	constexpr basic_static_string<Size>::basic_static_string(const char(&arr)[N])
		: m_elems{ N - 1 > Size ? Size : N - 1 }
		, m_buffer{ _helper::to_std_array<Size + 1>(arr) }
	{}
}