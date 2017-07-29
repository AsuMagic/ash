#include <ash/window/window.hpp>

#include <iostream>
#include <GL/glew.h>

#include <ash/util/propertymanager.hpp>
#include <ash/util/sdlassert.hpp>
#include <ash/util/logger.hpp>

namespace ash
{
	Window::Window(const std::string window, const int width, const int height)
	{
		if (!pman.sdl_initialized)
		{
			cengine() << "Initializing engine";
			sdl_assert(SDL_Init(SDL_INIT_VIDEO));
			pman.sdl_initialized = true;
		}

		cengine() << "Creating window";
		_window = SDL_CreateWindow(window.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		SDL_SetWindowData(_window, "sh", this);
		sdl_assert(_window);

		sdl_assert(
			// Select core OpenGL4.5
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE),
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4),
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5),

			// Set the color depth
			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8),
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8),
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8),

			SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32),

			// Disable depth and stencil buffers
			SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0),
			SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 0),

			// Enable double buffering
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1)
		);

		// Create a context over the window
		sdl_assert((_gl_context = SDL_GL_CreateContext(_window)));

		// Initialize glew
		glewExperimental = GL_TRUE;
		glewInit();

		GLint major, minor;
		glGetIntegerv(GL_MAJOR_VERSION, &major);
		glGetIntegerv(GL_MINOR_VERSION, &minor);

		cengine() << "Created OpenGL " << major << '.' << minor << " context over " << glGetString(GL_RENDERER);

		++pman.window_count;
	}

	Window::~Window()
	{
		cengine() << "Freeing window";
		SDL_GL_DeleteContext(_gl_context);
		SDL_DestroyWindow(_window);

		if (--pman.window_count == 0 && pman.sdl_cleanup_nowindow)
		{
			cengine() << "Cleaning up SDL";
			SDL_Quit();
		}
	}

	Window* Window::get(const uint32_t win_id)
	{
		return static_cast<Window*>(SDL_GetWindowData(SDL_GetWindowFromID(win_id), "sh"));
	}

	void Window::set_vsync(bool on)
	{
		SDL_GL_SetSwapInterval(on);
	}

	void Window::clear(const Color color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	bool Window::is_open() const
	{
		return !_should_close;
	}

	void Window::close(bool setting)
	{
		_should_close = setting;
	}

	SDL_Window& Window::get_handle()
	{
		return *_window;
	}

	const SDL_GLContext& Window::get_context() const
	{
		return _gl_context;
	}

	/*void Window::render()
	{

	}*/

	void Window::display()
	{
		SDL_GL_SwapWindow(_window);
	}
}
