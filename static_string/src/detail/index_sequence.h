#pragma once

#include <cstddef>

namespace cts::_helper::seq
{
	template<std::size_t... Idx>
	struct index_sequence {};

	template<std::size_t N, std::size_t... Idx>
	struct make_index_sequence : make_index_sequence<N - 1, N - 1, Idx...> {};

	template<std::size_t... Idx>
	struct make_index_sequence<0, Idx...> : index_sequence<Idx...> {};

	template<std::size_t N, std::size_t... Idx>
	struct make_reversed_index_sequence : make_reversed_index_sequence<N - 1, Idx..., N - 1> {};

	template<std::size_t... Idx>
	struct make_reversed_index_sequence<0, Idx...> : index_sequence<Idx...> {};

	template<std::size_t Begin, std::size_t End, std::size_t... Idx>
	struct make_index_subsequence : make_index_subsequence<Begin, End - 1, End, Idx...> {};

	template<std::size_t Begin, std::size_t... Idx>
	struct make_index_subsequence<Begin, Begin, Idx...> : index_sequence<Begin, Idx...> {};

	template<std::size_t Begin, std::size_t End, std::size_t... Idx>
	struct make_reversed_index_subsequence : make_reversed_index_subsequence<Begin, End - 1, Idx..., End> {};

	template<std::size_t Begin, std::size_t... Idx>
	struct make_reversed_index_subsequence<Begin, Begin, Idx...> : index_sequence<Idx..., Begin> {};
}