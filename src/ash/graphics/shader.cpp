#include <ash/graphics/shader.hpp>
#include <ash/util/logger.hpp>
#include <vector>

namespace ash
{
	ShaderStub::ShaderStub(const ShaderType _type, const std::string& _source) :
		type(_type), source(_source)
	{}

	void GLShaderManager::alloc(GLuint& id, const ShaderType type)
	{
		id = glCreateShader(static_cast<GLenum>(type));
	}

	void GLShaderManager::free(GLuint& id)
	{
		glDeleteShader(id);
	}

	Shader::Shader(const ShaderType type, const std::string& source) :
		id{type}
	{
		compile(source);
	}

	void Shader::compile(const std::string& source)
	{
		const char* csource = source.data();
		glShaderSource(id, 1, &csource, nullptr);
		glCompileShader(id);

		GLint success;
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			GLint log_buffer_size = 0;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &log_buffer_size);
			std::vector<char> log(static_cast<std::size_t>(log_buffer_size));

			glGetShaderInfoLog(id, log_buffer_size, nullptr, &(log[0]));
			cgraphics(LogLevel::Error) << "Shader compile error!\n" << log.data();

			throw std::runtime_error("shader failed to compile");
		}
	}
}
