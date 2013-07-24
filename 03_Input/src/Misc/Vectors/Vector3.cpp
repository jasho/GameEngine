#include "Vector3.h"
#include "..\Conversions.h"

using namespace std;

Vector3::Vector3(float x, float y, float z) : Vector2(x, y), _z(z) {}

string Vector3::ToString() const
{
	string xString, yString, zString;
	Conversions::FloatToString(_x, &xString);
	Conversions::FloatToString(_y, &yString);
	Conversions::FloatToString(_z, &zString);

	string toReturn = xString + STRING_VECTOR_SEPARATOR + yString + STRING_VECTOR_SEPARATOR + zString;
	return toReturn;
}

void Vector3::FromString(const string &values)
{
	string values_local = values;
	size_t index = values_local.find_first_of(STRING_VECTOR_SEPARATOR);
	string numString;

	if(index == string::npos)
	{
		//error, no separator found
		return;
	}
	numString = values_local.substr(0, index);
	values_local = values_local.substr(index + 1, values_local.size());
	if(!Conversions::StringToFloat(numString, &_x))
	{
		//error, not a number
		return;
	}

	index = values_local.find_first_of(STRING_VECTOR_SEPARATOR);
	if(index == string::npos)
	{
		//error, no separator found
		return;
	}
	numString = values_local.substr(0, index);
	values_local = values_local.substr(index + 1, values_local.size());
	if(!Conversions::StringToFloat(numString, &_y))
	{
		//error, not a number
		return;
	}

	index = values_local.find_first_of(STRING_VECTOR_SEPARATOR);
	numString = values_local.substr(0, index);
	if(!Conversions::StringToFloat(numString, &_z))
	{
		//error, not a number
		return;
	}
}

/**
* Overloads the operator + so that adding Vector3 objects will perform a vector addition by default.
*/
Vector3 Vector3::operator+(const Vector3& rhs)const {
	Vector3 result;
	result.SetValues(_x + rhs.GetX(), _y + rhs.GetY(), _z + rhs.GetZ()); 
	return result;
}

/**
* Overloads the operator - so that substracting Vector3 objects will perform a vector substraction by default.
*/
Vector3 Vector3::operator-(const Vector3& rhs) {
	Vector3 result;
	result.SetValues(_x - rhs.GetX(), _y - rhs.GetY(), _z - rhs.GetZ()); 
	return result;
}

/**
* Overloads the operator * so that multiplying Vector3 objects will perform a vector multiplication by default.
*/
Vector3 Vector3::operator*(const Vector3& rhs) {
	Vector3 result;
	result.SetValues(_x * rhs.GetX(), _y * rhs.GetY(), _z * rhs.GetZ()); 
	return result;
}

Vector3 Vector3::operator*(const int rhs)
{
	Vector3 result;
	result.SetValues(_x * rhs, _y * rhs, _z * rhs);
	return result;
}

Vector3 &Vector3::operator+=(const Vector3 &rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &rhs)
{
	*this = *this - rhs;
	return *this;
}

Vector3 &Vector3::operator*=(const Vector3 &rhs)
{
	*this = *this * rhs;
	return *this;
}