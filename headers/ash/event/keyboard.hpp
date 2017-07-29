#ifndef ASH_KEYBOARD_HPP
#define ASH_KEYBOARD_HPP

#include <SDL2/SDL.h>
#include <ash/window/window.hpp>

namespace ash
{
	struct KeyModifiers
	{
		// Key modifier bitfield
		uint16_t left_shift : 1,
				 right_shift : 1,

				 left_ctrl : 1,
				 right_ctrl : 1,

				 left_alt : 1,
				 right_alt : 1,

				 left_meta : 1,
				 right_meta : 1,

				 num_lock : 1,
				 caps_lock : 1,

				 alt_gr : 1;

		// Helper functions; determines whether some common keys were pressed (shift = lshift + rshift, ...)
		bool shift() const { return left_shift || right_shift; }
		bool ctrl() const { return left_ctrl || right_ctrl; }
		bool alt() const { return left_alt || right_alt; }
		bool meta() const { return left_meta || right_meta; }
	};

	// Virtual keycode mappings to SDL
	enum class Keycode
	{
		// Numpad digits
		Numpad000 = SDLK_KP_000,
		Numpad00 = SDLK_KP_00,
		Numpad0 = SDLK_KP_0,
		Numpad1 = SDLK_KP_1,
		Numpad2 = SDLK_KP_2,
		Numpad3 = SDLK_KP_3,
		Numpad4 = SDLK_KP_4,
		Numpad5 = SDLK_KP_5,
		Numpad6 = SDLK_KP_6,
		Numpad7 = SDLK_KP_7,
		Numpad8 = SDLK_KP_8,
		Numpad9 = SDLK_KP_9,
		NumpadA = SDLK_KP_A,
		NumpadB = SDLK_KP_B,
		NumpadC = SDLK_KP_C,
		NumpadD = SDLK_KP_D,
		NumpadE = SDLK_KP_E,
		NumpadF = SDLK_KP_F,
		NumpadAmpersand = SDLK_KP_AMPERSAND,
		NumpadAt = SDLK_KP_AT,
		NumpadBackspace = SDLK_KP_BACKSPACE,
		NumpadBinary = SDLK_KP_BINARY,
		NumpadDecimal = SDLK_KP_DECIMAL,
		NumpadHexadecimal = SDLK_KP_HEXADECIMAL,
		NumpadOctal = SDLK_KP_OCTAL,
		NumpadPercent = SDLK_KP_PERCENT,
		NumpadPeriod = SDLK_KP_PERIOD,
		NumpadClear = SDLK_KP_CLEAR,
		NumpadClearEntry = SDLK_KP_CLEARENTRY,
		NumpadColon = SDLK_KP_COLON,
		NumpadComma = SDLK_KP_COMMA,
		NumpadAND = SDLK_KP_DBLAMPERSAND,
		NumpadOR = SDLK_KP_DBLVERTICALBAR,
		NumpadNOT = SDLK_KP_EXCLAM,
		NumpadXOR = SDLK_KP_XOR,
		NumpadVerticalBar = SDLK_KP_VERTICALBAR,
		NumpadEnter = SDLK_KP_ENTER,
		NumpadEqual = SDLK_KP_EQUALS,
		NumpadEqualAS400 = SDLK_KP_EQUALSAS400,
		NumpadDivide = SDLK_KP_DIVIDE,
		NumpadMultiply = SDLK_KP_MULTIPLY,
		NumpadPlus = SDLK_KP_PLUS,
		NumpadMinus = SDLK_KP_MINUS,
		NumpadPlusMinus = SDLK_KP_PLUSMINUS,
		NumpadPower = SDLK_KP_POWER,
		NumpadGreater = SDLK_KP_GREATER,
		NumpadLess = SDLK_KP_LESS,
		NumpadLeftParenthesis = SDLK_KP_LEFTPAREN,
		NumpadRightParenthesis = SDLK_KP_RIGHTPAREN,
		NumpadLeftBrace = SDLK_KP_LEFTBRACE,
		NumpadRightBrace = SDLK_KP_RIGHTBRACE,
		NumpadSpace = SDLK_KP_SPACE,
		NumpadTab = SDLK_KP_TAB,
		NumpadHash = SDLK_KP_HASH,
		NumpadMemAdd = SDLK_KP_MEMADD,
		NumpadMemClear = SDLK_KP_MEMCLEAR,
		NumpadMemDivide = SDLK_KP_MEMDIVIDE,
		NumpadMemMultiply = SDLK_KP_MEMMULTIPLY,
		NumpadMemRecall = SDLK_KP_MEMRECALL,
		NumpadMemStore = SDLK_KP_MEMSTORE,
		NumpadMemSubtract = SDLK_KP_MEMSUBTRACT,

		// Modifier keys
		LeftAlt = SDLK_LALT,
		RightAlt = SDLK_RALT,
		LeftCtrl = SDLK_LCTRL,
		RightCtrl = SDLK_RCTRL,
		LeftMeta = SDLK_LGUI,
		RightMeta = SDLK_RGUI,
		LeftShift = SDLK_LSHIFT,
		RightShift = SDLK_RSHIFT,

		Numlock = SDLK_NUMLOCKCLEAR,

		Oper = SDLK_OPER,
		Out = SDLK_OUT,
		Prior = SDLK_PRIOR,

		PageDown = SDLK_PAGEDOWN,
		PageUp = SDLK_PAGEUP,

		LeftBracket = SDLK_LEFTBRACKET,
		RightBracket = SDLK_RIGHTBRACKET,
		LeftParenthesis = SDLK_LEFTPAREN,
		RightParenthesis = SDLK_RIGHTPAREN,

		// Top row digits
		Num0 = SDLK_0,
		Num1 = SDLK_1,
		Num2 = SDLK_2,
		Num3 = SDLK_3,
		Num4 = SDLK_4,
		Num5 = SDLK_5,
		Num6 = SDLK_6,
		Num7 = SDLK_7,
		Num8 = SDLK_8,
		Num9 = SDLK_9,

		// Application control keypad
		AppBack = SDLK_AC_BACK,
		AppBookmarks = SDLK_AC_BOOKMARKS,
		AppForward = SDLK_AC_FORWARD,
		AppHome = SDLK_AC_HOME,
		AppRefresh = SDLK_AC_REFRESH,
		AppSearch = SDLK_AC_SEARCH,
		AppStop = SDLK_AC_STOP,

		CapsLock = SDLK_CAPSLOCK,

		Clear = SDLK_CLEAR,
		ClearAgain = SDLK_CLEARAGAIN,

		Cancel = SDLK_CANCEL,

		Undo = SDLK_UNDO,
		Redo = SDLK_AGAIN,

		AltErase = SDLK_ALTERASE,

		Space = SDLK_SPACE,
		Tab = SDLK_TAB,

		Select = SDLK_SELECT,

		Apostrophe = SDLK_QUOTE,
		Comma = SDLK_COMMA,
		Grave = SDLK_BACKQUOTE,
		Period = SDLK_PERIOD,
		Semicolon = SDLK_SEMICOLON,
		Backslash = SDLK_BACKSLASH,
		Slash = SDLK_SLASH,

		ThousandsSeparator = SDLK_THOUSANDSSEPARATOR,
		DecimalSeparator = SDLK_DECIMALSEPARATOR,
		Separator = SDLK_SEPARATOR,

		Escape = SDLK_ESCAPE,

		Delete = SDLK_DELETE,
		Backspace = SDLK_BACKSPACE,
		Insert = SDLK_INSERT,

		BrightnessDown = SDLK_BRIGHTNESSDOWN,
		BrightnessUp = SDLK_BRIGHTNESSUP,

		IlluminationDown = SDLK_KBDILLUMDOWN,
		IlluminationToggle = SDLK_KBDILLUMTOGGLE,
		IlluminationUp = SDLK_KBDILLUMUP,

		MyComputer = SDLK_COMPUTER,
		Calculator = SDLK_CALCULATOR,
		Mail = SDLK_MAIL,
		WWW = SDLK_WWW,

		DisplaySwitch = SDLK_DISPLAYSWITCH,
		Eject = SDLK_EJECT,
		Execute = SDLK_EXECUTE,
		Find = SDLK_FIND,
		Help = SDLK_HELP,
		Home = SDLK_HOME,
		Mute = SDLK_MUTE,
		Power = SDLK_POWER,
		Sleep = SDLK_SLEEP,

		MediaSelect = SDLK_MEDIASELECT,
		Menu = SDLK_MENU,
		ModeSwitch = SDLK_MODE,

		Minus = SDLK_MINUS,
		Plus = SDLK_PLUS,
		Equal = SDLK_EQUALS,

		// Function keys
		F1 = SDLK_F1,
		F2 = SDLK_F2,
		F3 = SDLK_F3,
		F4 = SDLK_F4,
		F5 = SDLK_F5,
		F6 = SDLK_F6,
		F7 = SDLK_F7,
		F8 = SDLK_F8,
		F9 = SDLK_F9,
		F10 = SDLK_F10,
		F11 = SDLK_F11,
		F12 = SDLK_F12,
		F13 = SDLK_F13,
		F14 = SDLK_F14,
		F15 = SDLK_F15,
		F16 = SDLK_F16,
		F17 = SDLK_F17,
		F18 = SDLK_F18,
		F19 = SDLK_F19,
		F20 = SDLK_F20,
		F21 = SDLK_F21,
		F22 = SDLK_F22,
		F23 = SDLK_F23,
		F24 = SDLK_F24,

		// Direction keys
		Up = SDLK_UP,
		Right = SDLK_RIGHT,
		Down = SDLK_DOWN,
		Left = SDLK_LEFT,

		CrSel = SDLK_CRSEL,
		ExSel = SDLK_EXSEL,

		Pause = SDLK_PAUSE,
		Stop = SDLK_STOP,
		PrintScreen = SDLK_PRINTSCREEN,
		ScrollLock = SDLK_SCROLLLOCK,
		SysReq = SDLK_SYSREQ,

		CurrencySubUnit = SDLK_CURRENCYSUBUNIT,
		CurrencyUnit = SDLK_CURRENCYUNIT,

		// Paste
		Cut = SDLK_CUT,
		Copy = SDLK_COPY,
		Paste = SDLK_PASTE,

		ContextMenu = SDLK_APPLICATION,

		// Audio control
		AudioMute = SDLK_AUDIOMUTE,
		AudioNext = SDLK_AUDIONEXT,
		AudioPlay = SDLK_AUDIOPLAY,
		AudioPrevious = SDLK_AUDIOPREV,
		AudioStop = SDLK_AUDIOSTOP,

		VolumeUp = SDLK_VOLUMEUP,
		VolumeDown = SDLK_VOLUMEDOWN,

		// Alphabet keys
		A = SDLK_a,
		B = SDLK_b,
		C = SDLK_c,
		D = SDLK_d,
		E = SDLK_e,
		F = SDLK_f,
		G = SDLK_g,
		H = SDLK_h,
		I = SDLK_i,
		J = SDLK_j,
		K = SDLK_k,
		L = SDLK_l,
		M = SDLK_m,
		N = SDLK_n,
		O = SDLK_o,
		P = SDLK_p,
		Q = SDLK_q,
		R = SDLK_r,
		S = SDLK_s,
		T = SDLK_t,
		U = SDLK_u,
		V = SDLK_v,
		W = SDLK_w,
		X = SDLK_x,
		Y = SDLK_y,
		Z = SDLK_z,

		Ampersand = SDLK_AMPERSAND,
		Asterisk = SDLK_ASTERISK,
		At = SDLK_AT,
		Caret = SDLK_CARET,
		Colon = SDLK_COLON,
		Dollar = SDLK_DOLLAR,
		Exclaim = SDLK_EXCLAIM,
		Greater = SDLK_GREATER,
		Less = SDLK_LESS,
		Hash = SDLK_HASH,
		Percent = SDLK_PERCENT,
		Question = SDLK_QUESTION,
		DoubleQuote = SDLK_QUOTEDBL,
		Underscore = SDLK_UNDERSCORE,

		Unknown = SDLK_UNKNOWN
	};

	enum class KeyEventType
	{
		Press,
		Release
	};

	struct Key
	{
		Key() = default;
		Key(SDL_Keycode sdl_keycode, uint16_t modifiers = 0);
		Key(SDL_Scancode sdl_scancode, uint16_t modifiers = 0);

		void apply_modifiers(const uint16_t newmods);

		std::string name() const;

		//Keycode pk; // Physical key
		Keycode vk; // Virtual key

		KeyModifiers mods;
	};

	struct KeyEvent
	{
		explicit KeyEvent(const SDL_KeyboardEvent ev);

		Key key;
		Window* focused = nullptr;
		bool was_repeated = false;
	};

	struct KeyPressEvent : KeyEvent
	{
		explicit KeyPressEvent(const SDL_KeyboardEvent ev);
	};

	struct KeyReleaseEvent : KeyEvent
	{
		explicit KeyReleaseEvent(const SDL_KeyboardEvent ev);
	};
}

#endif // KEYBOARD_HPP
