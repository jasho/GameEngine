#ifndef SERIALIZATIONHELPER_HEADER
#define SERIALIZATIONHELPER_HEADER

#include <string>
#include <map>
#include <cstdlib>

#include "../SerializationHelperManager.h"

class SerializationHelper
{
public:
	virtual std::string GetStartTag(std::string tagName, std::map<std::string, std::string>* attributes = NULL) const = 0;
	virtual std::string GetEndTag(std::string tagName) const = 0;
	
	virtual std::string GetTagNameFromTag(std::string tag, TagType* tagType) const = 0;
};

#endif