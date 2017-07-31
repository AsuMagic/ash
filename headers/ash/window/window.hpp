#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <epoxy/gl.h>
#include <string>
#include <ash/graphics/color.hpp>

namespace ash
{
	// Define a SDL window
	class Window
	{
		SDL_Window* _window;
		SDL_GLContext _gl_context;

		bool _should_close = false;

	public:
		Window(const std::string window = "Ash Engine", const int width = 800, const int height = 600);
		~Window();

		static Window* get(const uint32_t win_id);

		void set_vsync(bool on = true);

		SDL_Window& get_handle();
		const SDL_GLContext& get_context() const;

		void clear(const Color color);
		//void render();

		// Returns whether the Window should still appear
		bool is_open() const;
		// Set the requirement to close soon
		void close(bool setting = true);

		void display();
	};
}

#endif // WINDOW_HPP
