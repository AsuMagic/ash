#ifndef ASH_VAO_HPP
#define ASH_VAO_HPP

#include <GL/glew.h>
#include "vbo.hpp"
#include "primitive.hpp"

namespace ash
{
	class VBO;

	class VAO
	{
		GLuint _array_id;

		std::vector<VBO> _buffers;
		std::vector<GLuint> _buffer_ids;

	public:
		// Default constructor. Constructs a single buffer on its own and manages it.
		VAO();

		// Destroy the VAO and free the GL buffers
		~VAO();

		// Emplace a VBO
		VBO& emplace();

		// Pre-generate GL buffers and reserve some space in _buffers
		void reserve(const std::size_t new_capacity);

		// Resize the buffers, creating new ones if necessary
		void resize(const std::size_t new_size);

		// Return the count of built VBOs
		std::size_t size() const;

		// Bind the VAO
		void bind();

		// Call specifying an amount of vertices
		void draw(const RenderPrimitive primitive, const std::size_t offset, const std::size_t count);

		//
		void attribute(VBO& vbo, const std::size_t id, const std::size_t size);

		// Get VBO at index
		VBO& operator[](const std::size_t at);

		// Unbind the VAO
		void unbind();

		// Returns the VAO id
		GLuint id() const;
	};
}

#endif // VAO_HPP
