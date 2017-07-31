#include <ash/graphics/vao.hpp>

namespace ash
{
	void GLVAOManager::alloc(GLuint& id)
	{
		glCreateVertexArrays(1, &id);
	}

	void GLVAOManager::free(GLuint& id)
	{
		glDeleteVertexArrays(1, &id);
	}

	void VAO::draw(const RenderPrimitive primitive, const std::size_t offset, const std::size_t count)
	{
		glBindVertexArray(id);
		glDrawArrays(static_cast<GLenum>(primitive), static_cast<GLsizei>(offset), static_cast<GLsizei>(count));
	}

	void VAO::attribute(const std::size_t attr, const std::size_t components)
	{
		glEnableVertexArrayAttrib(id, attr);
		glVertexArrayAttribFormat(id, attr, components, GL_FLOAT, GL_FALSE, 0);
	}
	
	void VAO::attribute_buffer(VBO& vbo, const std::size_t attr, const std::size_t components, const std::size_t shaderbinding)
	{
		glVertexArrayAttribBinding(id, attr, shaderbinding);
		glVertexArrayVertexBuffer(id, shaderbinding, vbo.id, 0, components * sizeof(float));
	}
}
