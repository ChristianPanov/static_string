#pragma once

#include "static_string.h"
#include "detail/array_factory.h"
#include "detail/static_string_helper.h"

namespace cts
{
	template<typename CharT, std::size_t Size>
	constexpr static_string<CharT, Size>::static_string(const CharT(&arr)[Size])
		: m_elems{ Size - 1 }
		, m_buffer{ _helper::array_factory<CharT, Size>::request(arr) }
	{}

	template<typename CharT, std::size_t Size>
	constexpr static_string<CharT, Size>::static_string(const std::array<CharT, Size>& arr)
		: m_elems{ _helper::std_array_elems<CharT>(arr) }
		, m_buffer{ arr }
	{}

	template<typename CharT, std::size_t Size>
	constexpr static_string<CharT, Size>::static_string(const static_string<CharT, Size>& other)
		: static_string<CharT, Size>(other.m_buffer)
	{}

	template<typename CharT, std::size_t Size>
	template<std::size_t Offset>
	constexpr std::size_t static_string<CharT, Size>::find(CharT ch) const
	{ 
		return _helper::find<Offset>(m_buffer, ch); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Offset, std::size_t OtherSize>
	constexpr std::size_t static_string<CharT, Size>::find(const CharT(&arr)[OtherSize]) const
	{ 
		return _helper::find<Offset>(m_buffer, _helper::array_factory<CharT, OtherSize>::request(arr)); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Offset, std::size_t OtherSize>
	constexpr std::size_t static_string<CharT, Size>::find(const std::array<CharT, OtherSize>& arr) const
	{ 
		return _helper::find<Offset>(m_buffer, arr); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Offset, std::size_t OtherSize>
	constexpr std::size_t static_string<CharT, Size>::find(const static_string<CharT, OtherSize>& other) const
	{ 
		return _helper::find<Offset>(m_buffer, other.m_buffer); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Offset>
	constexpr std::size_t static_string<CharT, Size>::rfind(CharT ch) const
	{ 
		return _helper::rfind<Offset>(m_buffer, ch); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Offset, std::size_t OtherSize>
	constexpr std::size_t static_string<CharT, Size>::rfind(const CharT(&arr)[OtherSize]) const
	{ 
		return _helper::rfind<Offset>(m_buffer, _helper::array_factory<CharT, OtherSize>::request(arr)); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Offset, std::size_t OtherSize>
	constexpr std::size_t static_string<CharT, Size>::rfind(const std::array<CharT, OtherSize>& arr) const
	{ 
		return _helper::rfind<Offset>(m_buffer, arr); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Offset, std::size_t OtherSize>
	constexpr std::size_t static_string<CharT, Size>::rfind(const static_string<CharT, OtherSize>& other) const
	{ 
		return _helper::rfind<Offset>(m_buffer, other.m_buffer); 
	}

	template<typename CharT, std::size_t Size>
	constexpr bool cts::static_string<CharT, Size>::contains(CharT ch) const
	{ 
		return _helper::find<0>(m_buffer, ch) != this->npos; 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool static_string<CharT, Size>::contains(const CharT(&arr)[OtherSize]) const
	{ 
		return _helper::find<0>(m_buffer, _helper::array_factory<CharT, OtherSize>::request(arr)) != this->npos; 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool static_string<CharT, Size>::contains(const std::array<CharT, OtherSize>& arr) const
	{ 
		return _helper::find<0>(m_buffer, arr) != this->npos; 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool static_string<CharT, Size>::contains(const static_string<CharT, OtherSize>& other) const
	{ 
		return _helper::find<0>(m_buffer, other.m_buffer) != this->npos; 
	}

	template<typename CharT, std::size_t Size>
	constexpr bool cts::static_string<CharT, Size>::starts_with(CharT ch) const
	{ 
		return _helper::find<0>(m_buffer, ch) == 0; 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool static_string<CharT, Size>::starts_with(const CharT(&arr)[OtherSize]) const
	{ 
		return _helper::find<0>(m_buffer, _helper::array_factory<CharT, OtherSize>::request(arr)) == 0; 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool static_string<CharT, Size>::starts_with(const std::array<CharT, OtherSize>& arr) const
	{ 
		return _helper::find<0>(m_buffer, arr) == 0; 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool static_string<CharT, Size>::starts_with(const static_string<CharT, OtherSize>& other) const
	{ 
		return _helper::find<0>(m_buffer, other.m_buffer) == 0; 
	}

	template<typename CharT, std::size_t Size>
	constexpr bool cts::static_string<CharT, Size>::ends_with(CharT ch) const
	{ 
		return _helper::rfind<0>(m_buffer, ch) == Size - 2; 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool static_string<CharT, Size>::ends_with(const CharT(&arr)[OtherSize]) const
	{ 
		return _helper::rfind<0>(m_buffer, _helper::array_factory<CharT, OtherSize>::request(arr)) == Size - OtherSize; 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool static_string<CharT, Size>::ends_with(const std::array<CharT, OtherSize>& arr) const
	{ 
		return _helper::rfind<0>(m_buffer, arr) == Size - OtherSize; 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool static_string<CharT, Size>::ends_with(const static_string<CharT, OtherSize>& other) const
	{ 
		return _helper::rfind<0>(m_buffer, other.m_buffer) == Size - OtherSize; 
	}

	template<typename CharT, std::size_t Size>
	constexpr static_string<CharT, Size> static_string<CharT, Size>::reverse() const
	{
		return static_string<CharT, Size>{
			_helper::array_factory<CharT, Size>::request<_helper::seq::make_reversed_index_sequence>(m_buffer)
		};
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Begin, std::size_t End>
	constexpr static_string<CharT, End - Begin + 2> static_string<CharT, Size>::substr() const
	{
		return static_string<CharT, End - Begin + 2>{
			_helper::array_factory<CharT, End - Begin + 2>::request<Begin, End, 
				_helper::seq::make_index_subsequence>(m_buffer)
		};
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Begin, std::size_t End>
	constexpr static_string<CharT, End - Begin + 2> static_string<CharT, Size>::rsubstr() const
	{
		return static_string<CharT, End - Begin + 2>{
			_helper::array_factory<CharT, End - Begin + 2>::request<Begin, End,
				_helper::seq::make_reversed_index_subsequence>(m_buffer)
		};
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Begin, std::size_t End, std::size_t OtherSize>
	constexpr static_string<CharT, Size - (End - Begin) + OtherSize> static_string<CharT, Size>::replace(
		const CharT(&arr)[OtherSize]) const
	{
		return this->substr<0, Begin - 1>() + static_string<CharT, OtherSize>{
			_helper::array_factory<CharT, OtherSize>::request(arr)
		} + this->substr<End, Size - 1>();
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Begin, std::size_t End, std::size_t OtherSize>
	constexpr static_string<CharT, Size - (End - Begin) + OtherSize> static_string<CharT, Size>::replace(
		const std::array<CharT, OtherSize>& arr) const
	{
		return this->substr<0, Begin - 1>() + static_string<CharT, OtherSize>{
			_helper::array_factory<CharT, OtherSize>::request(arr)
		} + this->substr<End, Size - 1>();
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t Begin, std::size_t End, std::size_t OtherSize>
	constexpr static_string<CharT, Size - (End - Begin) + OtherSize> static_string<CharT, Size>::replace(
		const static_string<CharT, OtherSize>& other) const
	{
		return this->substr<0, Begin - 1>() + other + this->substr<End, Size - 1>();
	}

	template<typename CharT, std::size_t Size>
	constexpr bool static_string<CharT, Size>::empty() const
	{ 
		return m_elems == 0; 
	}

	template<typename CharT, std::size_t Size>
	constexpr std::size_t static_string<CharT, Size>::size() const
	{ 
		return m_elems; 
	}

	template<typename CharT, std::size_t Size>
	constexpr std::size_t static_string<CharT, Size>::length() const
	{ 
		return m_elems; 
	}

	template<typename CharT, std::size_t Size>
	constexpr std::array<CharT, Size> static_string<CharT, Size>::data() const
	{ 
		return m_buffer; 
	}

	template<typename CharT, std::size_t Size>
	constexpr CharT& static_string<CharT, Size>::operator[](std::size_t index)
	{ 
		return m_buffer[index]; 
	}

	template<typename CharT, std::size_t Size>
	constexpr const CharT& static_string<CharT, Size>::operator[](std::size_t index) const
	{ 
		return m_buffer[index]; 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool cts::static_string<CharT, Size>::operator==(const CharT(&arr)[OtherSize]) const
	{ 
		return _helper::are_equal<CharT>(m_buffer, _helper::array_factory<CharT, OtherSize>::request(arr)); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool cts::static_string<CharT, Size>::operator!=(const CharT(&arr)[OtherSize]) const
	{ 
		return !_helper::are_equal<CharT>(m_buffer, _helper::array_factory<CharT, OtherSize>::request(arr)); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool cts::static_string<CharT, Size>::operator==(const std::array<CharT, OtherSize>& arr) const
	{ 
		return _helper::are_equal<CharT>(m_buffer, arr); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool cts::static_string<CharT, Size>::operator!=(const std::array<CharT, OtherSize>& arr) const
	{ 
		return !_helper::are_equal<CharT>(m_buffer, arr); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool static_string<CharT, Size>::operator==(const static_string<CharT, OtherSize>& other) const
	{ 
		return _helper::are_equal<CharT>(m_buffer, other.m_buffer); 
	}

	template<typename CharT, std::size_t Size>
	template<std::size_t OtherSize>
	constexpr bool static_string<CharT, Size>::operator!=(const static_string<CharT, OtherSize>& other) const
	{ 
		return !_helper::are_equal<CharT>(m_buffer, other.m_buffer); 
	}

	template<typename CharT, std::size_t Size>
	constexpr static_string<CharT, Size>::operator const CharT* () const
	{ 
		return m_buffer.data(); 
	}

	template<typename CharT, std::size_t LeftSize, std::size_t RightSize>
	constexpr static_string<CharT, LeftSize - 1 + RightSize> operator+(const static_string<CharT, LeftSize>& lhs, 
		const static_string<CharT, RightSize>& rhs)
	{
		return static_string<CharT, LeftSize - 1 + RightSize>{
			_helper::array_factory<CharT, LeftSize - 1 + RightSize>::request(lhs.m_buffer, rhs.m_buffer)
		};
	}
}