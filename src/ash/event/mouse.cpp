#include <ash/event/mouse.hpp>

namespace ash
{
	MouseMoveEvent::MouseMoveEvent(const SDL_MouseMotionEvent ev) :
		focused{Window::get(ev.windowID)},
		position{ev.x, ev.y}
	{}
}
