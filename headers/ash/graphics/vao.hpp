#ifndef ASH_VAO_HPP
#define ASH_VAO_HPP

#include <GL/glew.h>
#include <ash/graphics/vbo.hpp>
#include <ash/graphics/primitive.hpp>
#include <ash/graphics/glresource.hpp>

namespace ash
{
	class VBO;

	struct GLVAOManager
	{
		static void alloc(GLuint& id);
		static void free(GLuint& id);
	};

	class VAO
	{
	public:
		GLResource<GLVAOManager> id;

		// Bind the VAO
		void bind();

		// Call specifying an amount of vertices
		// TODO move to the thing logically actually rendering the vao
		void draw(const RenderPrimitive primitive, const std::size_t offset, const std::size_t count);

		//
		void attribute(VBO& vbo, const std::size_t id, const std::size_t size);

		// Get VBO at index
		//VBO& operator[](const std::size_t at);

		// Unbind the VAO
		void unbind();
	};
}

#endif // VAO_HPP
