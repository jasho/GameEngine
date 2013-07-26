#include "Color.h"
#include "../Misc/Conversions.h"
#include "../Serialize/SerializationStrings.h"

Color::Color()
{
}

Color::Color( float red, float blue, float green )
{
	_red = red;
	_blue = blue;
	_green = green;
}

Color::~Color()
{
}

float Color::GetRed() const
{
	return _red;
}

float Color::GetBlue() const
{
	return _blue;
}

float Color::GetGreen() const
{
	return _green;
}

void Color::SetRed(float red)
{
	_red = red;
}

void Color::SetBlue(float blue)
{
	_blue = blue;
}

void Color::SetGreen(float green)
{
	_green = green;
}

void Color::SetColors( float red , float blue , float green )
{
	_red = red;
	_blue = blue;
	_green = green;
}

void Color::SaveToOutputStream(std::ostream& outputStream) const
{
	outputStream << _red << STRING_SPACE_SEPARATOR;
	outputStream << _green << STRING_SPACE_SEPARATOR;
	outputStream << _blue << STRING_SPACE_SEPARATOR;
}

void Color::LoadFromInputStream(std::istream& inputStream)
{
	inputStream >> _red;
	inputStream >> _green;
	inputStream >> _blue;
}