#include <ash/util/sdlassert.hpp>

#include <SDL2/SDL.h>
#include <iostream>
#include <ash/util/logger.hpp>

namespace ash
{
	[[noreturn]] void assert_crash_common()
	{
		cengine() << "SDL: " << SDL_GetError();
		std::terminate();
	}

	void sdl_assert_handler(const int tested)
	{
		if (tested < 0)
			assert_crash_common();
	}

	void sdl_assert_handler(const bool tested)
	{
		if (!tested)
			assert_crash_common();
	}

	void sdl_assert() {}

}
