#ifndef ASH_COLOR_HPP
#define ASH_COLOR_HPP

#include <cstdint>

namespace ash
{
	// Default alpha channel traits
	template<class T> struct color_alpha_default;
	template<> struct color_alpha_default<float> { static constexpr float value = 1.f; };
	template<> struct color_alpha_default<uint8_t> { static constexpr uint8_t value = 255; };

	// Default red, green and blue channel traits
	template<class T> struct color_rgb_default;
	template<> struct color_rgb_default<float> { static constexpr float value = 0.f; };
	template<> struct color_rgb_default<uint8_t> { static constexpr uint8_t value = 0; };

	template<typename T/*, bool has_alpha = true*/>
	struct ColorT
	{
		constexpr ColorT(T red = 0, T green = 0, T blue = 0, T alpha = color_alpha_default<T>::value) :
			r(red), g(green), b(blue), a(alpha)
		{}

		T r, g, b, a;

		template<class To>
		ColorT<To> as()
		{
			return ColorT<To>{static_cast<To>(r),
							  static_cast<To>(g),
							  static_cast<To>(b)};
		}
	};

	using Color = ColorT<float>; // Float color
	using ColorU = ColorT<uint8_t>; // Integer color

	constexpr Color c_red     { 1.f,  0.f,  0.f  },
					c_orange  { 1.f,  0.7f, 0.f  },
					c_green   { 0.f,  1.f,  0.f  },
					c_cyan    { 0.f,  1.f,  0.7f },
					c_blue    { 0.f,  0.f,  1.f  },
					c_magenta { 0.7f, 0.f,  1.f  },
					c_pink    { 1.f,  0.f,  1.f  },
					c_white   { 1.f,  1.f,  1.f  },
					c_black   { 0.f,  0.f,  0.f  };
}

#endif // COLOR_HPP
