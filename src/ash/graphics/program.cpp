#include <ash/graphics/program.hpp>
#include <ash/util/logger.hpp>

namespace ash
{
	void GLProgramManager::alloc(GLuint& id)
	{
		id = glCreateProgram();
	}

	void GLProgramManager::free(GLuint& id)
	{
		glDeleteProgram(id);
	}

	Program::Program(const std::initializer_list<ShaderStub> shader_list)
	{
		std::vector<Shader> shaders;
		shaders.reserve(shader_list.size());
		for (const ShaderStub& stub : shader_list)
			shaders.emplace_back(stub.type, stub.source);

		for (Shader& shader : shaders)
			glAttachShader(id, shader.id);

		glLinkProgram(id);

		GLint success;
		glGetProgramiv(id, GL_LINK_STATUS, &success);

		if (!success)
		{
			GLint log_buffer_size = 0;
			glGetProgramiv(id, GL_INFO_LOG_LENGTH, &log_buffer_size);
			std::vector<char> log(static_cast<std::size_t>(log_buffer_size));

			glGetProgramInfoLog(id, log_buffer_size, nullptr, &(log[0]));
			cgraphics(LogLevel::Error) << "GL Program #" << id << ": Program link error!\n" << log.data();
		}
	}

	void Program::use()
	{
		glUseProgram(id);
	}
}
