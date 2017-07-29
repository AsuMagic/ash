#ifndef ASH_PROGRAM_HPP
#define ASH_PROGRAM_HPP

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <vector>
#include <iostream>
#include <ash/graphics/shader.hpp>
#include <ash/graphics/glresource.hpp>

namespace ash
{
	struct GLProgramManager
	{
		static void alloc(GLuint& id);
		static void free(GLuint& id);
	};

	class Program
	{
	public:
		GLResource<GLProgramManager> id;

		Program(const std::initializer_list<ShaderStub> shader_list);

		void use();
	};
}

#endif // PROGRAM_HPP
