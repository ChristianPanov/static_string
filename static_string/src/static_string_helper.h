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

	template<typename CharT, std::size_t Size, std::size_t N, std::size_t... Idx>
	constexpr std::array<CharT, Size> to_std_array_impl(const CharT(&arr)[N], std::index_sequence<Idx...>)
	{
		return std::array<CharT, Size>{ arr[Idx]... };
	}

	template<typename CharT, std::size_t Size, std::size_t N>
	constexpr std::array<CharT, Size> to_std_array(const CharT(&arr)[N])
	{
		return to_std_array_impl<CharT, Size>(arr, std::make_index_sequence<Size - 1>());
	}

	template<typename CharT, std::size_t LeftSize, std::size_t RightSize, std::size_t... Idx>
	constexpr bool are_equal_impl(const std::array<CharT, LeftSize>& lhs, const std::array<CharT, RightSize>& rhs,
		std::index_sequence<Idx...>)
	{
		return ((lhs[Idx] == rhs[Idx]) && ...);
	}

	template<typename CharT, std::size_t LeftSize, std::size_t RightSize>
	constexpr bool are_equal(const std::array<CharT, LeftSize>& lhs, const std::array<CharT, RightSize>& rhs)
	{
		constexpr std::size_t min_size = std::min(LeftSize, RightSize);
		return are_equal_impl(lhs, rhs, std::make_index_sequence<min_size - 1>());
	}

	template<typename CharT, std::size_t NewSize, std::size_t OldSize, std::size_t... Idx>
	constexpr std::array<CharT, NewSize> resize_impl(const std::array<CharT, OldSize>& arr,
		std::index_sequence<Idx...>)
	{
		return std::array<CharT, NewSize>{ arr[Idx]... };
	}

	template<typename CharT, std::size_t NewSize, std::size_t OldSize>
	constexpr std::array<CharT, NewSize> resize(const std::array<CharT, OldSize>& arr)
	{
		return resize_impl<CharT, NewSize>(arr, std::make_index_sequence<NewSize - 1>());
	}

	template<typename CharT, std::size_t LeftSize, std::size_t RightSize,
		std::size_t... LeftIdx, std::size_t... RightIdx>
		constexpr std::array<CharT, LeftSize - 1 + RightSize> concat_impl(const std::array<CharT, LeftSize>& lhs,
			const std::array<CharT, RightSize>& rhs, std::index_sequence<LeftIdx...>, std::index_sequence<RightIdx...>)
	{
		return std::array<CharT, LeftSize - 1 + RightSize>{ lhs[LeftIdx]..., rhs[RightIdx]... };
	}

	template<typename CharT, std::size_t LeftSize, std::size_t RightSize>
	constexpr std::array<CharT, LeftSize - 1 + RightSize> concat(const std::array<CharT, LeftSize>& lhs,
		const std::array<CharT, RightSize>& rhs)
	{
		return concat_impl<CharT>(lhs, rhs, std::make_index_sequence<LeftSize - 1>(),
			std::make_index_sequence<RightSize>());
	}
}