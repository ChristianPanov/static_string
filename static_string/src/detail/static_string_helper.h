#pragma once

#include <cstddef>
#include <array>
#include <limits>

#include "index_sequence.h"

#include <iostream>

namespace cts::_helper
{
	template<typename CharT, std::size_t N>
	constexpr std::size_t std_array_elems(const std::array<CharT, N>& arr, std::size_t i = 0)
	{
		return arr[i] == CharT{} ? i : std_array_elems(arr, i + 1);
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

	template<std::size_t Offset, typename CharT, std::size_t HaySize>
	constexpr std::size_t find(const std::array<CharT, HaySize>& hay, CharT needle, std::size_t hay_index = 0)
	{
		return hay_index + Offset >= HaySize ? std::numeric_limits<std::size_t>::max() :
			hay[hay_index + Offset] == needle ? 
			hay_index + Offset : find<Offset>(hay, needle, hay_index + 1);
	}

	template<std::size_t Offset, typename CharT, std::size_t HaySize, std::size_t NeedleSize>
	constexpr std::size_t find(const std::array<CharT, HaySize>& hay, const std::array<CharT, NeedleSize>& needle, 
		std::size_t hay_index = 0, std::size_t needle_index = 0)
	{
		return hay_index + Offset == HaySize ? std::numeric_limits<std::size_t>::max() :
			needle_index == NeedleSize - 1 ? hay_index + Offset - NeedleSize + 1 : 
			hay[hay_index + Offset] == needle[needle_index] ?
			find<Offset>(hay, needle, hay_index + 1, needle_index + 1) : 
			find<Offset>(hay, needle, hay_index + 1, needle_index = 0);
	}

	template<std::size_t Offset, typename CharT, std::size_t HaySize>
	constexpr std::size_t rfind(const std::array<CharT, HaySize>& hay, CharT needle,
		std::size_t hay_index = (Offset == 0 ? HaySize - 2 : Offset))
	{
		return hay_index == 0 ? std::numeric_limits<std::size_t>::max() :
			hay[hay_index] == needle ? hay_index : 
			rfind<Offset>(hay, needle, hay_index - 1);
	}

	template<std::size_t Offset, typename CharT, std::size_t HaySize, std::size_t NeedleSize>
	constexpr std::size_t rfind(const std::array<CharT, HaySize>& hay, const std::array<CharT, NeedleSize>& needle,
		std::size_t hay_index = (Offset == 0 ? HaySize - 2 : Offset), std::int32_t needle_index = NeedleSize - 2)
	{
		return hay_index < NeedleSize - 2 ? std::numeric_limits<std::size_t>::max() :
			needle_index == -1 ? hay_index + 1 :
			hay[hay_index] == needle[needle_index] ?
			rfind<Offset>(hay, needle, hay_index - 1, needle_index - 1) :
			rfind<Offset>(hay, needle, hay_index - 1, needle_index = NeedleSize - 2);
	}
}