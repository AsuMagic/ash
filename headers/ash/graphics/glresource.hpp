#ifndef ASH_GLRESOURCE_HPP
#define ASH_GLRESOURCE_HPP

#include <epoxy/gl.h>

namespace ash
{
	template<class Manager>
	struct GLResource
	{
		GLuint id;

		template<class... Types>
		GLResource(Types&&... args);

		GLResource(const GLResource&) = delete;
		GLResource& operator=(const GLResource&) = delete;
		GLResource(GLResource&&);
		GLResource& operator=(GLResource&&);

		~GLResource();

		operator GLuint() const;
	};
}

#include <ash/graphics/glresource.inl>

#endif // GLRESOURCE_HPP
