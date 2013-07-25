#ifndef SERIALIZABLE_HEADER
#define SERIALIZABLE_HEADER

#include <istream>
#include <ostream>
#include <string>

class Serializable
{
public:
	virtual void SaveToFile(std::istream&) = 0;
	virtual void LoadFromFile(std::ostream&) const = 0;
};

#endif