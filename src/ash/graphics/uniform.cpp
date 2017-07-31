#include <ash/graphics/uniform.hpp>

namespace ash
{
	void uniform_set(GLuint program, GLint loc, float a) { glProgramUniform1f(program, loc, a); }
	void uniform_set(GLuint program, GLint loc, float a, float b) { glProgramUniform2f(program, loc, a, b); }
	void uniform_set(GLuint program, GLint loc, float a, float b, float c) { glProgramUniform3f(program, loc, a, b, c); }

	void uniform_set(GLuint program, GLint loc, Vector2f vec) { glProgramUniform2f(program, loc, vec.x, vec.y); }

	void uniform_set(GLuint program, GLint loc, int a) { glProgramUniform1i(program, loc, a); }
	void uniform_set(GLuint program, GLint loc, int a, int b) { glProgramUniform2i(program, loc, a, b); }
	void uniform_set(GLuint program, GLint loc, int a, int b, int c) { glProgramUniform3i(program, loc, a, b, c); }

	Uniform::Uniform(Program& program, const std::string name) :
		_program(program.id),
		_location(glGetUniformLocation(program.id, name.c_str()))
	{}

	GLint Uniform::location() const
	{
		return _location;
	}
}
