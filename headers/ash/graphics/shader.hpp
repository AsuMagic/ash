#ifndef ASH_SHADER_HPP
#define ASH_SHADER_HPP

#include <epoxy/gl.h>
#include <string>
#include <ash/graphics/glresource.hpp>

namespace ash
{
	enum class ShaderType
	{
		Vertex = GL_VERTEX_SHADER,
		Fragment = GL_FRAGMENT_SHADER
	};

	struct ShaderStub
	{
		ShaderStub(const ShaderType type, const std::string& source);

		const ShaderType type;
		const std::string& source;
	};

	struct GLShaderManager
	{
		static void alloc(GLuint& id, const ShaderType type);
		static void free(GLuint& id);
	};

	class Shader
	{
		void compile(const std::string& source);

	public:
		GLResource<GLShaderManager> id;

		Shader(const ShaderType type, const std::string& source);
	};
}

#endif // SHADER_HPP
