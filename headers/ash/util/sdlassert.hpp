#ifndef ASH_SDLASSERT_HPP
#define ASH_SDLASSERT_HPP

#include <typeinfo>

// TODO generalize, if possible, for portaudio or other wrappers later

namespace ash
{
	[[noreturn]] void assert_crash_common();
	void sdl_assert_handler(const int tested);
	void sdl_assert_handler(const bool tested);

	template<typename T>
	void sdl_assert_handler(T* pointer)
	{
		if (!pointer)
			assert_crash_common();
	}

	// Fallback for variadic sdl_assert()
	void sdl_assert();

	// Handle a number of assertions
	template<typename Current, typename... Args>
	void sdl_assert(Current current, Args... args)
	{
		sdl_assert_handler(current); // Handle the current argument
		sdl_assert(args...); // Handle the rest
	}
}

#endif // SDLASSERT_HPP
