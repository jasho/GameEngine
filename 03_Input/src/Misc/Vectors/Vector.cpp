#include "Vector.h"

Vector::Vector(float x) : _x(x) {}

Vector Vector::operator+(const Vector &rhs)
{
	Vector result;
	result.SetValues(_x + rhs.GetX()); 
	return result;
}

Vector Vector::operator-(const Vector &rhs)
{
	Vector result;
	result.SetValues(_x - rhs.GetX()); 
	return result;
}

Vector Vector::operator*(const Vector &rhs)
{
	Vector result;
	result.SetValues(_x * rhs.GetX()); 
	return result;
}

Vector &Vector::operator+=(const Vector &rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector &Vector::operator-=(const Vector &rhs)
{
	*this = *this - rhs;
	return *this;
}

Vector &Vector::operator*=(const Vector &rhs)
{
	*this = *this * rhs;
	return *this;
}

void Vector::SaveToOutputStream(std::ostream& outputStream) const
{
	outputStream <<_x;
}

bool Vector::LoadFromInputStream(std::istream& inputStream)
{
	inputStream >> _x;
	return true;
}