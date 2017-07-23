#include "vector.hpp"

namespace ash
{
	template<typename T>
	Vector2<T> Vector2<T>::operator+(const Vector2<T> other) const
	{
		return Vector2<T>{x + other.x, y + other.y};
	}

	template<typename T>
	Vector2<T> Vector2<T>::operator-(const Vector2<T> other) const
	{
		return Vector2<T>{x - other.x, y - other.y};
	}

	template<typename T>
	Vector2<T> Vector2<T>::operator*(const Vector2<T> other) const
	{
		return Vector2<T>{x * other.x, y * other.y};
	}

	template<typename T>
	Vector2<T> Vector2<T>::operator/(const Vector2<T> other) const
	{
		return Vector2<T>{x / other.x, y / other.y};
	}

	template<typename T>
	Vector2<T> Vector2<T>::operator*(const T other) const
	{
		return Vector2<T>{x * other, y * other};
	}

	template<typename T>
	Vector2<T> Vector2<T>::operator/(const T other) const
	{
		return Vector2<T>{x / other, y / other};
	}
}
