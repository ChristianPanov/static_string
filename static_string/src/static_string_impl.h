#pragma once

#include "static_string.h"
#include "static_string_helper.h"

namespace cts
{
	template<std::size_t Size>
	template<std::size_t N>
	constexpr basic_static_string<Size>::basic_static_string(const char(&arr)[N])
		: m_elems{ N - 1 > Size ? Size : N - 1 }
		, m_buffer{ _helper::to_std_array<Size + 1>(arr) }
	{}

	template<std::size_t Size>
	template<std::size_t N>
	constexpr basic_static_string<Size>::basic_static_string(const std::array<char, N>& arr)
		: m_elems{ _helper::std_array_elems(_helper::resize<Size + 1>(arr)) }
		, m_buffer{ _helper::resize<Size + 1>(arr) }
	{}

	template<std::size_t Size>
	template<std::size_t N>
	constexpr basic_static_string<Size>::basic_static_string(const basic_static_string<N>& other)
		: basic_static_string<Size>(other.m_buffer)
	{}

	template<std::size_t Size>
	constexpr bool basic_static_string<Size>::empty() const
	{
		return m_elems == 0;
	}

	template<std::size_t Size>
	constexpr std::size_t basic_static_string<Size>::size() const
	{
		return m_elems;
	}

	template<std::size_t Size>
	constexpr std::size_t basic_static_string<Size>::length() const
	{
		return m_elems;
	}

	template<std::size_t Size>
	constexpr std::array<char, Size + 1> basic_static_string<Size>::data() const
	{
		return m_buffer;
	}

	template<std::size_t Size>
	constexpr char& basic_static_string<Size>::operator[](std::size_t index)
	{
		return m_buffer[index];
	}

	template<std::size_t Size>
	constexpr const char& basic_static_string<Size>::operator[](std::size_t index) const
	{
		return m_buffer[index];
	}

	template<std::size_t Size>
	constexpr basic_static_string<Size>::operator const char* () const
	{
		return m_buffer.data();
	}
}