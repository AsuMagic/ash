#ifndef ASH_GLRESOURCE_HPP
#define ASH_GLRESOURCE_HPP

#include <epoxy/gl.h>

namespace ash
{
	// RAII class to handle an OpenGL resource.
	// The manager should have 2 static functions:
	// - MyManager::alloc(GLuint& id, <optional arguments>)
	// - MyManager::free(GLuint& id)
	// This assumes alloc's id parameter is != 0 once the call is done.
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
