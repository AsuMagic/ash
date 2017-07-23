#include <ash/graphics/vbo.hpp>
#include <stdexcept>

namespace ash
{
	void GLVBOManager::alloc(GLuint& id)
	{
		glGenBuffers(1, &id);
	}

	void GLVBOManager::free(GLuint& id)
	{
		glDeleteBuffers(1, &id);
	}

	void VBO::buffer_realloc()
	{
		bind();
		glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(_values.size() * sizeof(float)), _values.data(), static_cast<GLenum>(_update_freq));
		_buffer_size = _values.size();
	}

	void VBO::buffer_update_range(const std::size_t offset, const std::size_t size)
	{
		if ((offset + size) > _values.size())
		{
			throw std::out_of_range("VBO update range is out of the vertices vector");
		}
		else if ((offset + size) > _buffer_size)
		{
			// Reallocate the whole buffer if the area is out of the current buffer
			// buffer_realloc() bind()s the VBO already
			buffer_realloc();
		}
		else
		{
			bind();
			glBufferSubData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(offset), static_cast<GLsizeiptr>(size), &_values.data()[offset]);
			// Do not update _buffer_size, it may only be changed through buffer_realloc().
		}
	}

	void VBO::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}

	void VBO::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VBO::resize(const std::size_t new_size)
	{
		_values.resize(new_size);
	}

	void VBO::reserve(const std::size_t reserved)
	{
		_values.reserve(reserved);
	}

	void VBO::update(VAO& vao)
	{
		vao.bind();
		buffer_update_range(0, _values.size());
	}

	float& VBO::operator[](const std::size_t at)
	{
		return _values[at];
	}

	float& VBO::at(const std::size_t at)
	{
		return _values.at(at);
	}
}
