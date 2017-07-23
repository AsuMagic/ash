#ifndef EVENT_TPP
#define EVENT_TPP

#include "mouse.hpp"
#include "keyboard.hpp"
#include "system.hpp"
#include "event.hpp"
#include "../util/trycall.hpp"

namespace ash
{
	template<typename F, typename... Args>
	bool Event::poll(F&& handler)
	{
		Event ev;
		if (SDL_PollEvent(&ev.ev))
		{
			ev.type = static_cast<EventType>(ev.ev.type);

			if (ev.type == EventType::KeyPressed)
				try_call(handler, KeyPressEvent{ev.ev.key});
			else if (ev.type == EventType::KeyReleased)
				try_call(handler, KeyReleaseEvent{ev.ev.key});
			else if (ev.type == EventType::MouseMove)
				try_call(handler, MouseMoveEvent{ev.ev.motion});
			else if (ev.type == EventType::Quit)
				try_call(handler, QuitEvent{});

			return true;
		}
		return false;
	}
}

#endif
