#ifndef ASH_TEXTURE_HPP
#define ASH_TEXTURE_HPP

#include <GL/glew.h>
#include <vector>
#include "image.hpp"
#include "glresource.hpp"

namespace ash
{
	struct GLTexture2DManager
	{
		static void alloc(GLuint& id);
		static void free(GLuint& id);
	};

	// TODO support 1D/2D/3D textures
	class Texture2D
	{
		GLResource<GLTexture2DManager> id;

	public:
		Texture2D(Image& image);

		// Update the texture.
		void update();

		// Bind the texture to GL_TEXTURE_2D to use by OpenGL functions
		void bind();

		// Unbind the texture from GL_TEXTURE_2D
		void unbind();
	};
}

#endif // TEXTURE_HPP
