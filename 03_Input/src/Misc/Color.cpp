#include "Color.h"

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