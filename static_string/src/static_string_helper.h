#pragma once

#include <array>

namespace cts::_helper
{
	template<typename CharT, std::size_t Size>
	constexpr std::size_t std_array_elems_impl(const std::array<CharT, Size>& arr, std::size_t i = 0)
	{
		return arr[i] == CharT{} ? i : std_array_elems_impl(arr, i + 1);
	}

	template<typename CharT, std::size_t Size>
	constexpr std::size_t std_array_elems(const std::array<CharT, Size>& arr)
	{
		return std_array_elems_impl(arr);
	}

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

	template<std::size_t NewSize, std::size_t OldSize, std::size_t... Idx>
	constexpr std::array<char, NewSize> resize_impl(const std::array<char, OldSize>& arr, std::index_sequence<Idx...>)
	{
		return std::array<char, NewSize>{ arr[Idx]... };
	}

	template<std::size_t NewSize, std::size_t OldSize>
	constexpr std::array<char, NewSize> resize(const std::array<char, OldSize>& arr)
	{
		return resize_impl<NewSize>(arr, std::make_index_sequence<NewSize - 1>());
	}
}