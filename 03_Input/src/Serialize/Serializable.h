#ifndef SERIALIZABLE_HEADER
#define SERIALIZABLE_HEADER

#include <istream>
#include <ostream>
#include <string>

class Serializable
{
public:
	void SaveToFile(std::string fileName) const;
	void LoadFromFile(std::string fileName);
	virtual void SaveToOutputStream(std::ostream&) const = 0;
	virtual void LoadFromInputStream(std::istream&) = 0;
};

#endif