#pragma once

#include <cstddef>
#include <array>

namespace cts
{
	template<typename CharT, std::size_t Size>
	class basic_static_string
	{
		template<typename CharT, std::size_t Size>
		friend class basic_static_string;

	public:
		static constexpr std::size_t npos = std::numeric_limits<std::size_t>::max();

	public:
		constexpr basic_static_string() = default;
		constexpr basic_static_string(const CharT(&arr)[Size]);
		constexpr basic_static_string(const std::array<CharT, Size>& arr);
		constexpr basic_static_string(const basic_static_string<CharT, Size>& other);

	public:
		template<std::size_t Offset = 0>
		constexpr std::size_t find(CharT ch) const;
		template<std::size_t Offset = 0, std::size_t OtherSize>
		constexpr std::size_t find(const CharT(&arr)[OtherSize]) const;
		template<std::size_t Offset = 0, std::size_t OtherSize>
		constexpr std::size_t find(const std::array<CharT, OtherSize>& arr) const;
		template<std::size_t Offset = 0, std::size_t OtherSize>
		constexpr std::size_t find(const basic_static_string<CharT, OtherSize>& other) const;

	public:
		template<std::size_t Offset = 0>
		constexpr std::size_t rfind(CharT ch) const;
		template<std::size_t Offset = 0, std::size_t OtherSize>
		constexpr std::size_t rfind(const CharT(&arr)[OtherSize]) const;
		template<std::size_t Offset = 0, std::size_t OtherSize>
		constexpr std::size_t rfind(const std::array<CharT, OtherSize>& arr) const;
		template<std::size_t Offset = 0, std::size_t OtherSize>
		constexpr std::size_t rfind(const basic_static_string<CharT, OtherSize>& other) const;

	public:
		constexpr bool contains(CharT ch) const;
		template<std::size_t OtherSize>
		constexpr bool contains(const CharT(&arr)[OtherSize]) const;
		template<std::size_t OtherSize>
		constexpr bool contains(const std::array<CharT, OtherSize>& arr) const;
		template<std::size_t OtherSize>
		constexpr bool contains(const basic_static_string<CharT, OtherSize>& other) const;

	public:
		constexpr bool starts_with(CharT ch) const;
		template<std::size_t OtherSize>
		constexpr bool starts_with(const CharT(&arr)[OtherSize]) const;
		template<std::size_t OtherSize>
		constexpr bool starts_with(const std::array<CharT, OtherSize>& arr) const;
		template<std::size_t OtherSize>
		constexpr bool starts_with(const basic_static_string<CharT, OtherSize>& other) const;

	public:
		constexpr bool ends_with(CharT ch) const;
		template<std::size_t OtherSize>
		constexpr bool ends_with(const CharT(&arr)[OtherSize]) const;
		template<std::size_t OtherSize>
		constexpr bool ends_with(const std::array<CharT, OtherSize>& arr) const;
		template<std::size_t OtherSize>
		constexpr bool ends_with(const basic_static_string<CharT, OtherSize>& other) const;

	public:
		constexpr basic_static_string<CharT, Size> reverse() const;
		template<std::size_t Begin, std::size_t End>
		constexpr basic_static_string<CharT, End - Begin + 2> substr() const;
		template<std::size_t Begin, std::size_t End>
		constexpr basic_static_string<CharT, End - Begin + 2> rsubstr() const;

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
		constexpr bool operator==(const CharT(&arr)[OtherSize]) const;
		template<std::size_t OtherSize>
		constexpr bool operator!=(const CharT(&arr)[OtherSize]) const;
		template<std::size_t OtherSize>
		constexpr bool operator==(const std::array<CharT, OtherSize>& arr) const;
		template<std::size_t OtherSize>
		constexpr bool operator!=(const std::array<CharT, OtherSize>& arr) const;
		template<std::size_t OtherSize>
		constexpr bool operator==(const basic_static_string<CharT, OtherSize>& other) const;
		template<std::size_t OtherSize>
		constexpr bool operator!=(const basic_static_string<CharT, OtherSize>& other) const;
		constexpr operator const CharT* () const;

	public:
		template<typename CharT, std::size_t LeftSize, std::size_t RightSize>
		friend constexpr basic_static_string<CharT, LeftSize - 1 + RightSize> operator+(
			const basic_static_string<CharT, LeftSize>& lhs, const basic_static_string<CharT, RightSize>& rhs);

	private:
		std::size_t m_elems{};
		std::array<char, Size> m_buffer{};
	};

	template<typename CharT, std::size_t LeftSize, std::size_t RightSize>
	constexpr basic_static_string<CharT, LeftSize - 1 + RightSize> operator+(
		const basic_static_string<CharT, LeftSize>& lhs, const basic_static_string<CharT, RightSize>& rhs);
}

#include "static_string_impl.h"