#pragma once

#include <cstddef>
#include <array>

#include "index_sequence.h"

namespace cts::_helper
{
	template<typename CharT, std::size_t N>
	constexpr std::size_t std_array_elems_impl(const std::array<CharT, N>& arr, std::size_t i = 0)
	{
		return arr[i] == CharT{} ? i : std_array_elems_impl(arr, i + 1);
	}

	template<typename CharT, std::size_t N>
	constexpr std::size_t std_array_elems(const std::array<CharT, N>& arr)
	{
		return std_array_elems_impl(arr);
	}

	template<typename CharT, std::size_t LeftSize, std::size_t RightSize, std::size_t... Idx>
	constexpr bool are_equal(const std::array<CharT, LeftSize>& lhs, const std::array<CharT, RightSize>& rhs,
		seq::index_sequence<Idx...>)
	{
		return ((lhs[Idx] == rhs[Idx]) && ...);
	}

	template<typename CharT, std::size_t LeftSize, std::size_t RightSize>
	constexpr bool are_equal(const std::array<CharT, LeftSize>& lhs, const std::array<CharT, RightSize>& rhs)
	{
		constexpr std::size_t min_size = std::min(LeftSize, RightSize);
		return are_equal(lhs, rhs, seq::make_index_sequence<min_size - 1>());
	}

	template<typename CharT, std::size_t LeftSize, std::size_t RightSize, std::size_t... Idx>
	constexpr bool are_equal(const std::array<CharT, LeftSize>& lhs, const CharT(&rhs)[RightSize],
		seq::index_sequence<Idx...>)
	{
		return ((lhs[Idx] == rhs[Idx]) && ...);
	}

	template<typename CharT, std::size_t LeftSize, std::size_t RightSize>
	constexpr bool are_equal(const std::array<CharT, LeftSize>& lhs, const CharT(&rhs)[RightSize])
	{
		constexpr std::size_t min_size = std::min(LeftSize, RightSize);
		return are_equal(lhs, rhs, seq::make_index_sequence<min_size - 1>());
	}
}