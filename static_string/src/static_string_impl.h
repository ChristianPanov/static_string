#pragma once

#include "static_string.h"
#include "detail/array_factory.h"
#include "detail/static_string_helper.h"

namespace cts
{
	template<typename CharT, std::size_t Size>
	constexpr basic_static_string<CharT, Size>::basic_static_string(const CharT(&arr)[Size])
		: m_elems{ Size - 1 }
		, m_buffer{ _helper::array_factory<CharT, Size>::request(arr) }
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
	constexpr basic_static_string<CharT, Size> basic_static_string<CharT, Size>::reverse() const
	{
		return basic_static_string<CharT, Size>{
			_helper::array_factory<CharT, Size>::request<_helper::seq::make_reversed_index_sequence>(m_buffer)
		};
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Begin, std::size_t End>
	constexpr basic_static_string<CharT, End - Begin + 2> basic_static_string<CharT, Size>::substr() const
	{
		return basic_static_string<CharT, End - Begin + 2>{
			_helper::array_factory<CharT, End - Begin + 2>::request<Begin, End, 
				_helper::seq::make_index_subsequence>(m_buffer)
		};
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Begin, std::size_t End>
	constexpr basic_static_string<CharT, End - Begin + 2> basic_static_string<CharT, Size>::rsubstr() const
	{
		return basic_static_string<CharT, End - Begin + 2>{
			_helper::array_factory<CharT, End - Begin + 2>::request<Begin, End,
				_helper::seq::make_reversed_index_subsequence>(m_buffer)
		};
	}

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
	constexpr const CharT& cts::basic_static_string<CharT, Size>::front() const
	{ return m_buffer[0]; }

	template<typename CharT, std::size_t Size>
	constexpr const CharT& basic_static_string<CharT, Size>::back() const
	{ return m_buffer[m_elems - 1]; }

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

	template<typename CharT, std::size_t LeftSize, std::size_t RightSize>
	constexpr basic_static_string<CharT, LeftSize - 1 + RightSize> operator+(
		const basic_static_string<CharT, LeftSize>& lhs, const basic_static_string<CharT, RightSize>& rhs)
	{
		return basic_static_string<CharT, LeftSize - 1 + RightSize>{
			_helper::array_factory<CharT, LeftSize - 1 + RightSize>::request(lhs.m_buffer, rhs.m_buffer)
		};
	}
}