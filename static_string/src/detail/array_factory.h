#pragma once

#include <cstddef>
#include <array>

#include "index_sequence.h"

namespace cts::_helper
{
	template<typename CharT, std::size_t Size>
	struct array_factory
	{
		template<std::size_t N, std::size_t... Idx>
		constexpr static std::array<CharT, Size> request(const CharT(&arr)[N], seq::index_sequence<Idx...>)
		{ return std::array<CharT, Size>{ arr[Idx]..., static_cast<CharT>('\0') }; }

		template<template<std::size_t> typename MakeSequencePolicy = seq::make_index_sequence, std::size_t N>
		constexpr static std::array<CharT, Size> request(const CharT(&arr)[N])
		{ return request(arr, MakeSequencePolicy<(Size > N ? N : Size) - 1>{}); }

		template<std::size_t N, std::size_t... Idx>
		constexpr static std::array<CharT, Size> request(const std::array<CharT, N>& arr, seq::index_sequence<Idx...>)
		{ return std::array<CharT, Size>{ arr[Idx]..., static_cast<CharT>('\0') }; }

		template<template<std::size_t> typename MakeSequencePolicy = seq::make_index_sequence, std::size_t N>
		constexpr static std::array<CharT, Size> request(const std::array<CharT, N>& arr)
		{ return request(arr, MakeSequencePolicy<(Size > N ? N : Size) - 1>{}); }

		template<std::size_t LeftN, std::size_t RightN, std::size_t... LeftIdx, std::size_t... RightIdx>
		constexpr static std::array<CharT, Size> request(const std::array<CharT, LeftN>& lhs,
			const std::array<CharT, RightN>& rhs, seq::index_sequence<LeftIdx...>, seq::index_sequence<RightIdx...>)
		{ return std::array<CharT, Size>{ lhs[LeftIdx]..., rhs[RightIdx]..., static_cast<CharT>('\0') }; }

		template<template<std::size_t> typename MakeSequencePolicy = seq::make_index_sequence, 
			std::size_t LeftN, std::size_t RightN>
		constexpr static std::array<CharT, Size> request(const std::array<CharT, LeftN>& lhs, 
			const std::array<CharT, RightN>& rhs)
		{ return request(lhs, rhs, MakeSequencePolicy<LeftN - 1>{}, MakeSequencePolicy<RightN - 1>{}); }

		template<std::size_t Begin, std::size_t End, std::size_t N, std::size_t... Idx>
		constexpr static std::array<CharT, Size> request(const std::array<CharT, N>& arr, 
			seq::index_sequence<Idx...>)
		{ return std::array<CharT, Size>{ arr[Idx]..., static_cast<CharT>('\0') }; }

		template<std::size_t Begin, std::size_t End, 
			template<std::size_t, std::size_t> typename MakeSubSequencePolicy = seq::make_index_subsequence, 
			std::size_t N>
		constexpr static std::array<CharT, Size> request(const std::array<CharT, N>& arr)
		{ return request<Begin, End>(arr, MakeSubSequencePolicy<Begin, End>{}); }
	};
}