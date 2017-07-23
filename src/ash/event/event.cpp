#include <ash/event/event.hpp>

namespace ash
{
	bool Event::poll()
	{
		Event ev;
		if (SDL_PollEvent(&ev.ev))
		{
			ev.type = static_cast<EventType>(ev.ev.type);
			return true;
		}
		return false;
	}
}
