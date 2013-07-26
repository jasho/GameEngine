#ifndef SERIALIZABLE_HEADER
#define SERIALIZABLE_HEADER

#include <istream>
#include <ostream>
#include <string>

class Serializable
{
public:
	virtual void SaveToFile(std::string) = 0;
	virtual void LoadFromFile(std::string) const = 0;
	virtual void SaveToOutputStream(std::ostream&) const = 0;
	virtual void LoadFromOutputStream(std::istream&) const = 0;
};

#endif