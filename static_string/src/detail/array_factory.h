#pragma once

#include <cstddef>
#include <array>

#include "index_sequence.h"

namespace cts::_helper
{
	template<typename CharT, std::size_t Size>
	class array_factory
	{
	public:
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

		template<std::size_t LeftSize, std::size_t RightSize, std::size_t... LeftIdx, std::size_t... RightIdx>
		constexpr static std::array<CharT, Size> request(const std::array<CharT, LeftSize>& lhs,
			const std::array<CharT, RightSize>& rhs, seq::index_sequence<LeftIdx...>, seq::index_sequence<RightIdx...>)
		{ return std::array<CharT, Size>{ lhs[LeftIdx]..., rhs[RightIdx]..., static_cast<CharT>('\0') }; }

		template<template<std::size_t> typename MakeSequencePolicy = seq::make_index_sequence, 
			std::size_t LeftSize, std::size_t RightSize>
		constexpr static std::array<CharT, Size> request(const std::array<CharT, LeftSize>& lhs,
			const std::array<CharT, RightSize>& rhs)
		{ return request(lhs, rhs, MakeSequencePolicy<LeftSize - 1>{}, MakeSequencePolicy<RightSize - 1>{}); }
	};
}