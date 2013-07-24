#ifndef CONVERSIONS_HEADER
#define CONVERSIONS_HEADER

#include <string>
#include <windows.h>

class Conversions
{
public:
	static bool StringToInt(const std::string &input, int *output);
	static bool StringToUnsignedLong(const std::string &input, unsigned long *output);
	static bool StringToUnsignedLongLong(const std::string &input, unsigned long long *output);
	static bool StringToFloat(const std::string &input, float *output);	

	static void IntToString(int input, std::string *output);
	static void UnsignedLongLongToString(unsigned long long input, std::string *output);
	static void FloatToString(float input, std::string *output);
};

#endif