#pragma once

#include <array>

namespace cts
{
	template<std::size_t Size>
	class basic_static_string
	{
	public:
		constexpr basic_static_string() = default;
		template<std::size_t N>
		constexpr basic_static_string(const char(&arr)[N]);
		template<std::size_t N>
		constexpr basic_static_string(const std::array<char, N>& arr);
		template<std::size_t N>
		constexpr basic_static_string(const basic_static_string<N>& other);

	private:
		std::size_t m_elems{};
		std::array<char, Size + 1> m_buffer{};
	};
}

#include "static_string_impl.h"