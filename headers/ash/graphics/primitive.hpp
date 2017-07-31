#ifndef ASH_PRIMITIVE_HPP
#define ASH_PRIMITIVE_HPP

#include <epoxy/gl.h>

namespace ash
{
	enum class RenderPrimitive
	{
		Points = GL_POINTS,

		LineStrip = GL_LINE_STRIP,
		LineLoop = GL_LINE_LOOP,
		Lines = GL_LINES,
		LineStripAdjacency = GL_LINE_STRIP_ADJACENCY,
		LinesAdjacency = GL_LINES_ADJACENCY,

		TriangleStrip = GL_TRIANGLE_STRIP,
		TriangleFan = GL_TRIANGLE_FAN,
		Triangles = GL_TRIANGLES,
		TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
		TrianglesAdjacency = GL_TRIANGLES_ADJACENCY
	};
}

#endif // PRIMITIVE_HPP
