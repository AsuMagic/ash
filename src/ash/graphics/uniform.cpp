#include <ash/graphics/uniform.hpp>

namespace ash
{
	void uniform_set(GLint loc, float a) { glUniform1f(loc, a); }
	void uniform_set(GLint loc, float a, float b) { glUniform2f(loc, a, b); }
	void uniform_set(GLint loc, float a, float b, float c) { glUniform3f(loc, a, b, c); }

	void uniform_set(GLint loc, Vector2f vec) { glUniform2f(loc, vec.x, vec.y); }

	void uniform_set(GLint loc, int a) { glUniform1i(loc, a); }
	void uniform_set(GLint loc, int a, int b) { glUniform2i(loc, a, b); }
	void uniform_set(GLint loc, int a, int b, int c) { glUniform3i(loc, a, b, c); }

	Uniform::Uniform(Program& program, const std::string name) :
		_location(glGetUniformLocation(program.id, name.c_str()))
	{}

	GLint Uniform::location() const
	{
		return _location;
	}
}
