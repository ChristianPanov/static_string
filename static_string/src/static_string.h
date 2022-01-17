#pragma once

#include <array>

namespace cts
{
	template<typename CharT, std::size_t Size>
	class basic_static_string
	{
		template<typename CharT, std::size_t Size>
		friend class basic_static_string;

	public:
		constexpr basic_static_string() = default;
		constexpr basic_static_string(const CharT(&arr)[Size]);
		constexpr basic_static_string(const std::array<CharT, Size>& arr);
		constexpr basic_static_string(const basic_static_string<CharT, Size>& other);

	public:
		constexpr bool empty() const;
		constexpr std::size_t size() const;
		constexpr std::size_t length() const;
		constexpr std::array<CharT, Size> data() const;

	public:
		constexpr CharT& operator[](std::size_t index);
		constexpr const CharT& operator[](std::size_t index) const;

	public:
		template<std::size_t OtherSize>
		constexpr basic_static_string<CharT, Size>& operator=(const basic_static_string<CharT, OtherSize>& other);
		template<std::size_t OtherSize>
		constexpr bool operator==(const basic_static_string<CharT, OtherSize>& other) const;
		template<std::size_t OtherSize>
		constexpr bool operator!=(const basic_static_string<CharT, OtherSize>& other) const;
		constexpr operator const CharT* () const;

	protected:
		std::size_t m_elems{};
		std::array<char, Size> m_buffer{};
	};
}

#include "static_string_impl.h"