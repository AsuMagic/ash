#ifndef ASH_EVENT_HPP
#define ASH_EVENT_HPP

#include <SDL2/SDL.h>
#include <ash/window/window.hpp>

namespace ash
{
	enum class EventType : uint32_t
	{
		Quit = SDL_QUIT,

		// Android, iOS, WinRT
		AppTerminate = SDL_APP_TERMINATING,
		AppLowMemory = SDL_APP_LOWMEMORY,
		Defocusing = SDL_APP_WILLENTERBACKGROUND,
		Defocused = SDL_APP_DIDENTERBACKGROUND,
		Focusing = SDL_APP_WILLENTERFOREGROUND,
		Focused = SDL_APP_DIDENTERFOREGROUND,

		// Window events
		WinEvent = SDL_WINDOWEVENT,
		WMEvent = SDL_SYSWMEVENT,

		// Keyboard events
		KeyPressed = SDL_KEYDOWN,
		KeyReleased = SDL_KEYUP,
		TextEditing = SDL_TEXTEDITING,
		TextInput = SDL_TEXTINPUT,
		KeymapRemap = SDL_KEYMAPCHANGED,

		// Mouse events
		MouseMove = SDL_MOUSEMOTION,
		MousePressed = SDL_MOUSEBUTTONDOWN,
		MouseReleased = SDL_MOUSEBUTTONUP,
		MouseWheel = SDL_MOUSEWHEEL,

		// Joystick events
		JoyAxisMove = SDL_JOYAXISMOTION,
		JoyBallMove = SDL_JOYBALLMOTION,
		JoyHatMove = SDL_JOYHATMOTION,
		JoyButtonPressed = SDL_JOYBUTTONDOWN,
		JoyButtonReleased = SDL_JOYBUTTONUP,
		JoyPlugged = SDL_JOYDEVICEADDED,
		JoyUnplugged = SDL_JOYDEVICEREMOVED,

		// Controller events
		ControllerAxisMove = SDL_CONTROLLERAXISMOTION,
		ControllerButtonPressed = SDL_CONTROLLERBUTTONDOWN,
		ControllerButtonReleased = SDL_CONTROLLERBUTTONUP,
		ControllerPlugged = SDL_CONTROLLERDEVICEADDED,
		ControllerUnplugged = SDL_CONTROLLERDEVICEREMOVED,
		ControllerRemap = SDL_CONTROLLERDEVICEREMAPPED,

		// Touch events
		FingerMove = SDL_FINGERMOTION,
		FingerPressed = SDL_FINGERDOWN,
		FingerReleased = SDL_FINGERUP,

		// Clipboard
		ClipboardUpdate = SDL_CLIPBOARDUPDATE,

		// Drag and Drop events
		DropFile = SDL_DROPFILE,
		DropText = SDL_DROPTEXT,
		DropBegin = SDL_DROPBEGIN,
		DropEnd = SDL_DROPCOMPLETE,

		// Audio events
		AudioDevicePlugged = SDL_AUDIODEVICEADDED,
		AudioDeviceUnplugged = SDL_AUDIODEVICEREMOVED,

		// Render events
		RenderTargetReset = SDL_RENDER_TARGETS_RESET,
		RenderDeviceReset = SDL_RENDER_DEVICE_RESET,

		// User events : Implement or not?
	};

	struct Event
	{
		EventType type;
		SDL_Event ev;

		bool poll();

		template<typename T, typename... Args>
		bool poll(T&& handler);
	};
}

#include "event.inl"

#endif // EVENT_HPP
