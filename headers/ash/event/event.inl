#ifndef ASH_EVENT_INL
#define ASH_EVENT_INL

#include <ash/event/mouse.hpp>
#include <ash/event/keyboard.hpp>
#include <ash/event/system.hpp>
#include <ash/event/event.hpp>
#include <ash/util/trycall.hpp>

namespace ash
{
	template<typename F, typename... Args>
	bool Event::poll(F&& handler)
	{
		Event event;
		if (SDL_PollEvent(&event.ev))
		{
			event.type = static_cast<EventType>(event.ev.type);

			if (event.type == EventType::KeyPressed)
				try_call(handler, KeyPressEvent{event.ev.key});
			else if (event.type == EventType::KeyReleased)
				try_call(handler, KeyReleaseEvent{event.ev.key});
			else if (event.type == EventType::MouseMove)
				try_call(handler, MouseMoveEvent{event.ev.motion});
			else if (event.type == EventType::Quit)
				try_call(handler, QuitEvent{});

			return true;
		}
		return false;
	}
}

#endif
