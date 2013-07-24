#include "Vector2.h"

Vector2::Vector2(float x, float y) : Vector(x), _y(y) {}

Vector2 Vector2::operator+(const Vector2 &rhs)
{
	Vector2 result;
	result.SetValues(_x + rhs.GetX(), _y + rhs.GetY()); 
	return result;
}

Vector2 Vector2::operator-(const Vector2 &rhs)
{
	Vector2 result;
	result.SetValues(_x - rhs.GetX(), _y - rhs.GetY()); 
	return result;
}

Vector2 Vector2::operator*(const Vector2 &rhs)
{
	Vector2 result;
	result.SetValues(_x * rhs.GetX(), _y * rhs.GetY()); 
	return result;
}

Vector2 &Vector2::operator+=(const Vector2 &rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &rhs)
{
	*this = *this - rhs;
	return *this;
}

Vector2 &Vector2::operator*=(const Vector2 &rhs)
{
	*this = *this * rhs;
	return *this;
}