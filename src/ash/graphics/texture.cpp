#include <ash/graphics/texture.hpp>
#include <ash/util/logger.hpp>

namespace ash
{
	void GLTexture2DManager::alloc(GLuint& id)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &id);
	}

	void GLTexture2DManager::free(GLuint& id)
	{
		glDeleteTextures(1, &id);
	}

	Texture2D::Texture2D(Image& image)
	{
		wrapping(TextureWrapping::Repeat);
		filtering(TextureFiltering::Nearest);

		glTextureStorage2D(id, 1, GL_RGBA8, static_cast<GLsizei>(image.width()), static_cast<GLsizei>(image.height()));
		update(image);
	}
	
	void Texture2D::wrapping(const TextureWrapping mode)
	{
		glTextureParameteri(id, GL_TEXTURE_WRAP_S, static_cast<GLenum>(mode));
		glTextureParameteri(id, GL_TEXTURE_WRAP_T, static_cast<GLenum>(mode));
	}
	
	void Texture2D::filtering(const TextureFiltering mode)
	{
		glTextureParameteri(id, GL_TEXTURE_MIN_FILTER, static_cast<GLenum>(mode));
		glTextureParameteri(id, GL_TEXTURE_MAG_FILTER, static_cast<GLenum>(mode));
	}

	void Texture2D::update(Image& image)
	{
		glTextureSubImage2D(id, 0, 0, 0, image.width(), image.height(), GL_RGBA, GL_UNSIGNED_BYTE, image.data());
	}
	
	void Texture2D::enable(const std::size_t unit)
	{
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, id);
	}
}
