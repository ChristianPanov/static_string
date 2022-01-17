#pragma once

#include <array>

namespace cts
{
	template<typename CharT, std::size_t Size>
	class basic_static_string
	{
	public:
		constexpr basic_static_string() = default;
		template<std::size_t N>
		constexpr basic_static_string(const CharT(&arr)[N]);
		template<std::size_t N>
		constexpr basic_static_string(const std::array<CharT, N>& arr);
		template<std::size_t N>
		constexpr basic_static_string(const basic_static_string<CharT, N>& other);

	public:
		constexpr bool empty() const;
		constexpr std::size_t size() const;
		constexpr std::size_t length() const;
		constexpr std::array<CharT, Size + 1> data() const;

	public:
		constexpr CharT& operator[](std::size_t index);
		constexpr const CharT& operator[](std::size_t index) const;

	public:
		template<std::size_t N>
		constexpr basic_static_string<CharT, Size>& operator=(const basic_static_string<CharT, N>& other);
		template<std::size_t N>
		constexpr bool operator==(const basic_static_string<CharT, N>& other) const;
		template<std::size_t N>
		constexpr bool operator!=(const basic_static_string<CharT, N>& other) const;
		constexpr operator const CharT* () const;

	private:
		std::size_t m_elems{};
		std::array<CharT, Size + 1> m_buffer{};
	};
}

#include "static_string_impl.h"