#include <ash/event/event.hpp>

namespace ash
{
	bool Event::poll()
	{
		Event event;
		if (SDL_PollEvent(&event.ev))
		{
			event.type = static_cast<EventType>(event.ev.type);
			return true;
		}
		return false;
	}
}
