#include <ash/graphics/texture.hpp>
#include <ash/util/logger.hpp>

namespace ash
{
	void GLTexture2DManager::alloc(GLuint& id)
	{
		glGenTextures(1, &id);
	}

	void GLTexture2DManager::free(GLuint& id)
	{
		glDeleteTextures(1, &id);
	}

	Texture2D::Texture2D(Image& image)
	{
		bind();

		glPixelStorei(GL_PACK_ALIGNMENT, 1);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// Set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glActiveTexture(GL_TEXTURE0);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, static_cast<GLsizei>(image.width()), static_cast<GLsizei>(image.height()), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data());
	}

	void Texture2D::update()
	{
		// TODO allow for partial updates
		// TODO allow for multiple texture units
		//glActiveTexture(GL_TEXTURE0);
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, static_cast<GLsizei>(image.width), static_cast<GLsizei>(_height), 0, GL_RGBA, GL_UNSIGNED_BYTE, _image.data());
	}

	void Texture2D::bind()
	{
		glBindTexture(GL_TEXTURE_2D, id);
	}

	void Texture2D::unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
