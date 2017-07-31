#ifndef ASH_EVENT_INL
#define ASH_EVENT_INL

#include <ash/event/mouse.hpp>
#include <ash/event/keyboard.hpp>
#include <ash/event/system.hpp>
#include <ash/event/event.hpp>
#include <ash/util/trycall.hpp>
#include <ash/util/logger.hpp>

namespace ash
{
	template<typename F, typename... Args>
	bool Event::poll(F&& handler)
	{
		Event event;
		if (SDL_PollEvent(&event.ev))
		{
			switch (static_cast<EventType>(event.ev.type))
			{
			case EventType::KeyPressed:  try_call(handler, KeyPressEvent{event.ev.key}); break;
			case EventType::KeyReleased: try_call(handler, KeyReleaseEvent{event.ev.key}); break;
			case EventType::MouseMove:   try_call(handler, MouseMoveEvent{event.ev.motion}); break;
			case EventType::Quit:		 try_call(handler, QuitEvent{}); break;
			default:					 break;//cdebug() << "Unhandled event " << static_cast<int>(event.type);
			};
		}
		return false;
	}
}

#endif
