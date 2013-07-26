#ifndef SERIALIZATIONHELPERXML_HEADER
#define SERIALIZATIONHELPERXML_HEADER

#include "SerializationHelper.h"

class SerializationHelperXml : public SerializationHelper
{
public:
	virtual std::string GetStartTag(std::string tagName, std::map<std::string, std::string>* attributes) const;
	virtual std::string GetEndTag(std::string tagName) const;
};

#endif // SERIALIZATIONHELPERXML_HEADER