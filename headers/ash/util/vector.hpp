#ifndef ASH_VECTOR_HPP
#define ASH_VECTOR_HPP

namespace ash
{
	template<typename T>
	class Vector2
	{
	public:
		Vector2() = default;

		template<typename Y>
		explicit Vector2(const Vector2<Y> other) :
			x{static_cast<T>(other.x)}, y{static_cast<T>(other.y)}
		{}

		Vector2(T _x, T _y) :
			x{_x}, y{_y}
		{}

		Vector2<T> operator+(const Vector2<T> other) const;
		Vector2<T> operator-(const Vector2<T> other) const;
		Vector2<T> operator*(const Vector2<T> other) const;
		Vector2<T> operator/(const Vector2<T> other) const;
		Vector2<T> operator*(const T other) const;
		Vector2<T> operator/(const T other) const;

		T x, y;
	};

	using Vector2d = Vector2<double>;
	using Vector2f = Vector2<float>;
	using Vector2u = Vector2<unsigned>;
	using Vector2i = Vector2<int>;
}

#include <ash/util/vector.inl>

#endif // VECTOR_HPP
