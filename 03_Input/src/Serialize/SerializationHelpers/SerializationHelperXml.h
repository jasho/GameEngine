#ifndef SERIALIZATIONHELPERXML_HEADER
#define SERIALIZATIONHELPERXML_HEADER

#include "SerializationHelper.h"

class SerializationHelperXml : public SerializationHelper
{
public:
	virtual std::string GetStartTag(std::string tagName, std::map<std::string, std::string>* attributes = NULL) const;
	virtual std::string GetEndTag(std::string tagName) const;

	virtual std::string GetTagNameFromTag(std::string tag, TagType* tagType) const;
};

#endif // SERIALIZATIONHELPERXML_HEADER