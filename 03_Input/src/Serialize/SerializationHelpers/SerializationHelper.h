#ifndef SERIALIZATIONHELPER_HEADER
#define SERIALIZATIONHELPER_HEADER

#include <string>
#include <map>

class SerializationHelper
{
public:
	virtual std::string GetStartTag(std::string tagName, std::map<std::string, std::string>* attributes) const = 0;
	virtual std::string GetEndTag(std::string tagName) const = 0;
};

#endif