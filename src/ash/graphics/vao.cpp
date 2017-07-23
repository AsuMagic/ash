#include <ash/graphics/vao.hpp>

namespace ash
{
	VAO::VAO()
	{
		glGenVertexArrays(1, &_array_id);
	}

	VAO::~VAO()
	{
		bind();
		glDeleteBuffers(static_cast<GLsizei>(_buffer_ids.size()), _buffer_ids.data());
		unbind();
		glDeleteVertexArrays(1, &_array_id);
	}

	VBO& VAO::emplace()
	{
		bind();

		const std::size_t ready_buffers = _buffer_ids.size() - _buffers.size();
		if (ready_buffers == 0)
		{
			_buffer_ids.emplace_back();
			glGenBuffers(1, &_buffer_ids.back());
		}

		_buffers.emplace_back(_buffer_ids.back());
		return _buffers.back();
	}

	void VAO::reserve(const std::size_t new_capacity)
	{
		const std::size_t old_size = _buffer_ids.size();
		if (new_capacity > old_size)
		{
			bind();

			// Reserve VBOs
			_buffers.reserve(new_capacity);

			// Generate buffers
			_buffer_ids.resize(new_capacity);
			glGenBuffers(static_cast<GLsizei>(old_size - new_capacity), &_buffer_ids[old_size]);
		}
	}

	void VAO::resize(const std::size_t new_size)
	{
		bind();

		const std::size_t old_size = _buffers.size();

		if (new_size < old_size)
		{
			// Erase buffers on the end
			glDeleteBuffers(static_cast<GLsizei>(old_size - new_size), _buffer_ids.data() + old_size);
			_buffers.resize(new_size);
		}
		else if (new_size > old_size)
		{
			const std::size_t to_build = new_size - old_size,
						 old_buffer_size = _buffer_ids.size(),
						 ready_buffers = _buffer_ids.size() - _buffers.size();

			// Build lacking OpenGL buffers
			const int to_generate = static_cast<int>(to_build) - static_cast<int>(ready_buffers); // GL buffers left to build
			if (to_generate > 0)
			{
				_buffer_ids.resize(new_size);
				glGenBuffers(to_generate, &_buffer_ids[old_buffer_size]);
			}

			_buffers.reserve(new_size);
			for (std::size_t i = old_size; i < new_size; ++i)
				_buffers.emplace_back(_buffer_ids[i]);
		}
	}

	std::size_t VAO::size() const
	{
		return _buffers.size();
	}

	void VAO::bind()
	{
		glBindVertexArray(_array_id);
	}

	void VAO::draw(const RenderPrimitive primitive, const std::size_t offset, const std::size_t count)
	{
		bind();
		glDrawArrays(static_cast<GLenum>(primitive), static_cast<GLsizei>(offset), static_cast<GLsizei>(count));
	}

	void VAO::attribute(VBO& vbo, const std::size_t id, const std::size_t size)
	{
		vbo.bind();
		glVertexAttribPointer(static_cast<GLuint>(id), static_cast<GLsizei>(size), GL_FLOAT, GL_FALSE, sizeof(float) * size, 0);
		glEnableVertexAttribArray(static_cast<GLuint>(id));
	}

	VBO& VAO::operator[](const std::size_t at)
	{
		return _buffers[at];
	}

	void VAO::unbind()
	{
		glBindVertexArray(0);
	}

	GLuint VAO::id() const
	{
		return _array_id;
	}
}
