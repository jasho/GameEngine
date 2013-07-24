#include "Conversions.h"

#include <sstream>

using namespace std;

#define STRING_TO_SOMETHING stringstream ss;	\
							ss << input;		\
							ss >> *output;		\
							if(!ss)				\
							{					\
								return false;	\
							}					\
							else				\
							{					\
								return true;	\
							}

#define SOMETHING_TO_STRING stringstream ss;	\
							ss << input;		\
							ss >> *output;

bool Conversions::StringToInt(const string &input, int *output)
{
	STRING_TO_SOMETHING
}

bool Conversions::StringToUnsignedLong(const std::string &input, unsigned long *output)
{
	STRING_TO_SOMETHING
}

bool Conversions::StringToUnsignedLongLong(const string &input, unsigned long long *output)
{
	STRING_TO_SOMETHING
}


bool Conversions::StringToFloat(const string &input, float *output)
{
	STRING_TO_SOMETHING
}

void Conversions::IntToString(int input, string *output)
{
	SOMETHING_TO_STRING
}

void Conversions::UnsignedLongLongToString(unsigned long long input, string *output)
{
	SOMETHING_TO_STRING
}

void Conversions::FloatToString(float input, string *output)
{
	SOMETHING_TO_STRING
}