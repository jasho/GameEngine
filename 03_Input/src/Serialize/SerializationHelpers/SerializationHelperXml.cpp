#include "SerializationHelperXml.h"
#include "../SerializationStrings.h"

using namespace std;

string SerializationHelperXml::GetStartTag(string tagName, map<string, string>* attributes) const
{
	string toReturn = "";

	toReturn += STRING_HELPERXML_STARTTAG_START;
		toReturn += tagName;
	
		if(attributes != NULL)
		{
			map<string, string>::iterator attributeIterator;
			for(attributeIterator = attributes->begin(); attributeIterator != attributes->end(); ++attributeIterator)
			{
				toReturn += STRING_SPACE_SEPARATOR;
				toReturn += (*attributeIterator).first;
				toReturn += STRING_EQUALS;
				toReturn += STRING_QUOTE;
					toReturn += (*attributeIterator).second;
				toReturn += STRING_QUOTE;
			}
		}
	toReturn += STRING_HELPERXML_STARTTAG_END;
	toReturn += STRING_LINE_SEPARATOR;

	return toReturn;
}

string SerializationHelperXml::GetEndTag(std::string tagName) const
{
	string toReturn = "";
	toReturn += STRING_HELPERXML_ENDTAG_START;
	toReturn += tagName;
	toReturn += STRING_HELPERXML_ENDTAG_END;
	toReturn += STRING_LINE_SEPARATOR;

	return toReturn;
}

string SerializationHelperXml::GetTagNameFromTag(std::string tag) const
{
	string toReturn;

	return toReturn;
}