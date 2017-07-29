#ifndef ASH_CONSTEXPR_STRING_HPP
#define ASH_CONSTEXPR_STRING_HPP

#include <cstddef>

namespace ash
{
	struct constexpr_string
	{
		const char* str;
		const std::size_t size;

		template<std::size_t Size>
		constexpr constexpr_string(const char (&_str)[Size]) :
			str{_str},
			size{Size - 1} // Skip trailing '\0'
		{}
	};
}

#endif // CONSTEXPR_STRING_HPP
