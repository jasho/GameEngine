#include "Vector2.h"
#include "../../Serialize/SerializationStrings.h"

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

void Vector2::SaveToOutputStream(std::ostream& outputStream) const
{
	Vector::SaveToOutputStream(outputStream);
	outputStream << STRING_SPACE_SEPARATOR << _y;
}

bool Vector2::LoadFromInputStream(std::istream& inputStream)
{
	Vector::LoadFromInputStream(inputStream);
	inputStream >> _y;

	return true;
}