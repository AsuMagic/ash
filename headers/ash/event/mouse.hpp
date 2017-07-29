#ifndef ASH_MOUSE_HPP
#define ASH_MOUSE_HPP

#include <SDL2/SDL.h>
#include <ash/util/vector.hpp>
#include <ash/window/window.hpp>

namespace ash
{
	struct MouseMoveEvent
	{
		explicit MouseMoveEvent(const SDL_MouseMotionEvent ev);

		Window* focused = nullptr;
		Vector2i position;
	};
}

#endif // MOUSE_HPP
