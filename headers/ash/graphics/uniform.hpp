#ifndef ASH_UNIFORM_HPP
#define ASH_UNIFORM_HPP

#include <ash/graphics/program.hpp>
#include <ash/util/vector.hpp>

namespace ash
{
	void uniform_set(GLuint program, GLint loc, float a);
	void uniform_set(GLuint program, GLint loc, float a, float b);
	void uniform_set(GLuint program, GLint loc, float a, float b, float c);

	void uniform_set(GLuint program, GLint loc, Vector2f vec);

	void uniform_set(GLuint program, GLint loc, int a);
	void uniform_set(GLuint program, GLint loc, int a, int b);
	void uniform_set(GLuint program, GLint loc, int a, int b, int c);

	class Uniform
	{
		const GLuint _program;
		const GLint _location;

	public:
		Uniform(Program& program, const std::string name);

		GLint location() const;

		template<typename... Args>
		Uniform& operator=(const Args... args)
		{
			uniform_set(_program, _location, args...);
			return *this;
		}
	};
}

#endif // UNIFORM_HPP
