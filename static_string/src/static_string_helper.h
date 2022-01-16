#pragma once

#include <array>

namespace cts::_helper
{
	template<std::size_t Size, std::size_t N, std::size_t... Idx>
	constexpr std::array<char, Size> to_std_array_impl(const char(&arr)[N], std::index_sequence<Idx...>)
	{
		return std::array<char, Size>{ arr[Idx]... };
	}

	template<std::size_t Size, std::size_t N>
	constexpr std::array<char, Size> to_std_array(const char(&arr)[N])
	{
		return to_std_array_impl<Size>(arr, std::make_index_sequence<Size - 1>());
	}
}