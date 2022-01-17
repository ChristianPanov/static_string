#pragma once

#include "static_string.h"
#include "static_string_helper.h"

namespace cts
{
	template<typename CharT, std::size_t Size>
	constexpr basic_static_string<CharT, Size>::basic_static_string(const CharT(&arr)[Size])
		: m_elems{ Size - 1 }
		, m_buffer{ _helper::to_std_array<CharT, Size>(arr) }
	{}

	template<typename CharT, std::size_t Size>
	constexpr basic_static_string<CharT, Size>::basic_static_string(const std::array<CharT, Size>& arr)
		: m_elems{ _helper::std_array_elems<CharT>(arr) }
		, m_buffer{ arr }
	{}

	template<typename CharT, std::size_t Size>
	constexpr basic_static_string<CharT, Size>::basic_static_string(const basic_static_string<CharT, Size>& other)
		: basic_static_string<CharT, Size>(other.m_buffer)
	{}

	template<typename CharT, std::size_t Size>
	constexpr bool basic_static_string<CharT, Size>::empty() const
	{ return m_elems == 0; }

	template<typename CharT, std::size_t Size>
	constexpr std::size_t basic_static_string<CharT, Size>::size() const
	{ return m_elems; }

	template<typename CharT, std::size_t Size>
	constexpr std::size_t basic_static_string<CharT, Size>::length() const
	{ return m_elems; }

	template<typename CharT, std::size_t Size>
	constexpr std::array<CharT, Size> basic_static_string<CharT, Size>::data() const
	{ return m_buffer; }

	template<typename CharT, std::size_t Size>
	constexpr CharT& basic_static_string<CharT, Size>::operator[](std::size_t index)
	{ return m_buffer[index]; }

	template<typename CharT, std::size_t Size>
	constexpr const CharT& basic_static_string<CharT, Size>::operator[](std::size_t index) const
	{ return m_buffer[index]; }

	template<typename CharT, std::size_t Size>
	template<std::size_t N>
	constexpr basic_static_string<CharT, Size>& basic_static_string<CharT, Size>::operator=(
		const basic_static_string<CharT, N>& other)
	{
		m_buffer = _helper::resize<CharT, Size>(other.m_buffer);
		m_elems = other.m_elems;
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool basic_static_string<CharT, Size>::operator==(
		const basic_static_string<CharT, OtherSize>& other) const
	{ return _helper::are_equal<CharT>(m_buffer, other.m_buffer); }

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool basic_static_string<CharT, Size>::operator!=(
		const basic_static_string<CharT, OtherSize>& other) const
	{ return !_helper::are_equal<CharT>(m_buffer, other.m_buffer); }

	template<typename CharT, std::size_t Size>
	constexpr basic_static_string<CharT, Size>::operator const CharT* () const
	{ return m_buffer.data(); }
}