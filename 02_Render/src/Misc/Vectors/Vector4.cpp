#include "Vector4.h"

Vector4::Vector4(float x, float y, float z, float w) : Vector3(x, y, z), _w(w) {}


/**
* Overloads the operator + so that adding Vector4 objects will perform a vector addition by default.
*/
Vector4 Vector4::operator+(const Vector4& rhs) {
	Vector4 result;
	result.SetValues(_x + rhs.GetX(), _y + rhs.GetY(), _z + rhs.GetZ(), _w + rhs.GetW()); 
	return result;
}

/**
* Overloads the operator - so that substracting Vector4 objects will perform a vector substraction by default.
*/
Vector4 Vector4::operator-(const Vector4& rhs) {
	Vector4 result;
	result.SetValues(_x - rhs.GetX(), _y - rhs.GetY(), _z - rhs.GetZ(), _w - rhs.GetW()); 
	return result;
}

/**
* Overloads the operator * so that multiplying Vector4 objects will perform a vector multiplication by default.
*/
Vector4 Vector4::operator*(const Vector4& rhs) {
	Vector4 result;
	result.SetValues(_x * rhs.GetX(), _y * rhs.GetY(), _z * rhs.GetZ(), _w * rhs.GetW());
	return result;
}

Vector4 &Vector4::operator+=(const Vector4 &rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector4 &Vector4::operator-=(const Vector4 &rhs)
{
	*this = *this - rhs;
	return *this;
}

Vector4 &Vector4::operator*=(const Vector4 &rhs)
{
	*this = *this * rhs;
	return *this;
}