#ifndef ASH_VBO_HPP
#define ASH_VBO_HPP

#include <epoxy/gl.h>
#include <vector>
#include <ash/graphics/vao.hpp>
#include <ash/graphics/glresource.hpp>

namespace ash
{
	enum class VBOUpdateFrequency
	{
		Static = GL_STATIC_DRAW,
		Dynamic = GL_DYNAMIC_DRAW,
		Stream = GL_STREAM_DRAW
	};

	class VAO;

	struct GLVBOManager
	{
		static void alloc(GLuint& id);
		static void free(GLuint& id);
	};

	class VBO
	{
		VBOUpdateFrequency _update_freq = VBOUpdateFrequency::Static;

		std::vector<float> _values;
		std::size_t _buffer_size = 0;

		void buffer_realloc();
		void buffer_update_range(const std::size_t offset, const std::size_t size);

		// Fallback function for push
		void push_impl() {}

		// Push floats
		template<typename Current, typename... Args>
		void push_impl(Current current, Args... rest)
		{
			_values.push_back(current);
			push_impl(rest...);
		}

	public:
		GLResource<GLVBOManager> id;

		// Resize the vertices vector. *Doesn't* affect the VBO, update() is still necessary to refresh the contents.
		void resize(const std::size_t new_size);

		// Reserve N vertices in the vertices vector. *Doesn't* affect the VBO.
		void reserve(const std::size_t reserved);

		// Push floats
		template<class... Args>
		void push(Args... rest)
		{
			std::size_t old_size = _values.size();
			_values.reserve(sizeof...(Args));
			push_impl(rest...);
			buffer_update_range(old_size, sizeof...(Args));
		}

		// Update the VBO. Currently updates the whole VBO with buffer_update_range rather inefficiently.
		void update();

		// Non bound-checked access
		float& operator[](const std::size_t at);

		// Bound-checked access
		float& at(const std::size_t at);
		
		std::size_t size() const;
	};
}

#endif // VBO_HPP
