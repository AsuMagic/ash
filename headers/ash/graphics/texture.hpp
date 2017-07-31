#ifndef ASH_TEXTURE_HPP
#define ASH_TEXTURE_HPP

#include <GL/glew.h>
#include <vector>
#include <ash/graphics/image.hpp>
#include <ash/graphics/glresource.hpp>

namespace ash
{
	struct GLTexture2DManager
	{
		static void alloc(GLuint& id);
		static void free(GLuint& id);
	};
	
	enum class TextureWrapping
	{
		Repeat = GL_REPEAT,
		MirroredReapeat = GL_MIRRORED_REPEAT,
		ClampToEdge = GL_CLAMP_TO_EDGE,
		ClampToBorder = GL_CLAMP_TO_BORDER
	};
	
	enum class TextureFiltering
	{
		Nearest = GL_NEAREST,
		Linear = GL_LINEAR
	};

	// TODO support 1D/3D textures
	class Texture2D
	{
		GLResource<GLTexture2DManager> id;

	public:
		Texture2D(Image& image);
		
		// Set the OpenGL texture wrapping mode
		void wrapping(const TextureWrapping mode);

		// Set the OpenGL texture filtering mode
		void filtering(const TextureFiltering mode);
		
		// Update the texture from an Image.
		void update(Image& image);
		
		// Bind the texture in a specific texture unit
		void enable(const std::size_t unit = 0);
	};
}

#endif // TEXTURE_HPP
