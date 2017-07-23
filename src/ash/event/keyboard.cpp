#include <ash/event/keyboard.hpp>

namespace ash
{
	Key::Key(SDL_Keycode sdl_keycode, uint16_t modifiers) :
		vk{static_cast<Keycode>(sdl_keycode)}
	{
		apply_modifiers(modifiers);
	}

	Key::Key(SDL_Scancode sdl_scancode, uint16_t modifiers) :
		//pk{static_cast<Keycode>(sdl_keycode)},
		vk{static_cast<Keycode>(SDL_GetKeyFromScancode(sdl_scancode))}
	{
		apply_modifiers(modifiers);
	}

	void Key::apply_modifiers(const uint16_t newmods)
	{
		mods.left_shift = static_cast<bool>(newmods & KMOD_LSHIFT);
		mods.right_shift = static_cast<bool>(newmods & KMOD_RSHIFT);

		mods.left_ctrl = static_cast<bool>(newmods & KMOD_LCTRL);
		mods.right_ctrl = static_cast<bool>(newmods & KMOD_RCTRL);

		mods.left_alt = static_cast<bool>(newmods & KMOD_LALT);
		mods.right_alt = static_cast<bool>(newmods & KMOD_RALT);

		mods.left_meta = static_cast<bool>(newmods & KMOD_LGUI);
		mods.right_meta = static_cast<bool>(newmods & KMOD_RGUI);

		mods.num_lock = static_cast<bool>(newmods & KMOD_NUM);
		mods.caps_lock = static_cast<bool>(newmods & KMOD_CAPS);

		mods.alt_gr = static_cast<bool>(newmods & KMOD_MODE);
	}

	std::string Key::name() const
	{
		return SDL_GetKeyName(static_cast<SDL_Keycode>(vk));
	}

	KeyEvent::KeyEvent(const SDL_KeyboardEvent ev) :
		key(ev.keysym.sym, ev.keysym.mod),
		focused(Window::get(ev.windowID)),
		was_repeated(ev.repeat)
	{}

	KeyPressEvent::KeyPressEvent(const SDL_KeyboardEvent ev) :
		KeyEvent{ev}
	{}

	KeyReleaseEvent::KeyReleaseEvent(const SDL_KeyboardEvent ev) :
		KeyEvent{ev}
	{}
}
