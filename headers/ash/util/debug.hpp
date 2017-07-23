#ifndef ASH_DEBUG_HPP
#define ASH_DEBUG_HPP

#include <typeinfo>

#if defined(_GLIBCXX_RELEASE) || defined(_LIBCPP_VERSION)
	#define CXXABI_AVAILABLE
	#include <cxxabi.h>
#endif

namespace ash
{
	#ifdef ASH_DEBUG
	constexpr bool debug_mode = true;
	#else
	constexpr bool debug_mode = false;
	#endif

	#ifdef CXXABI_AVAILABLE
	template<class T>
	const char* pretty_name()
	{
		return abi::__cxa_demangle(typeid(T).name(), 0, 0, nullptr);
	}
	#else
	template<class T>
	const char* pretty_name()
	{
		#pragma message("Could not detect library support for cxxabi.h. No pretty demangling.")
		return typeid(T).name();
	}
	#endif
}

#endif // DEBUG_HPP
