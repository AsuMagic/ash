#include <ash/graphics/vao.hpp>

namespace ash
{
	void GLVAOManager::alloc(GLuint& id)
	{
		glGenVertexArrays(1, &id);
	}

	void GLVAOManager::free(GLuint& id)
	{
		glDeleteVertexArrays(1, &id);
	}

	void VAO::bind()
	{
		glBindVertexArray(id);
	}

	void VAO::draw(const RenderPrimitive primitive, const std::size_t offset, const std::size_t count)
	{
		bind();
		glDrawArrays(static_cast<GLenum>(primitive), static_cast<GLsizei>(offset), static_cast<GLsizei>(count));
	}

	void VAO::attribute(VBO& vbo, const std::size_t index, const std::size_t size)
	{
		bind();
		vbo.bind();
		glVertexAttribPointer(static_cast<GLuint>(index), static_cast<GLsizei>(size), GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(static_cast<GLuint>(index));
	}

	void VAO::unbind()
	{
		glBindVertexArray(0);
	}
}
