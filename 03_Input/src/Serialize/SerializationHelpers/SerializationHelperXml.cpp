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

string SerializationHelperXml::GetTagNameFromTag(std::string tag, TagType* tagType) const
{
	string toReturn;
	size_t foundStart = tag.find(STRING_HELPERXML_ENDTAG_START);
	size_t foundEnd;
	if(foundStart == string::npos)
	{
		foundStart = tag.find(STRING_HELPERXML_STARTTAG_START);

		if(foundStart == string::npos)
		{
			(*tagType) = NONE;
			return "";
		}
		else
		{
			foundEnd = tag.find_last_of(STRING_HELPERXML_STARTTAG_END);

			if(foundEnd == string::npos)
			{
				(*tagType) = NONE;
				return "";
			}
			else
			{
				(*tagType) = START;
				return tag.substr(foundStart + 1, (foundEnd - foundStart - 1));
			}
		}
	}
	else
	{
		foundEnd = tag.find_last_of(STRING_HELPERXML_ENDTAG_END);

		if(foundEnd == string::npos)
		{
			(*tagType) = NONE;
			return "";
		}
		else
		{
			(*tagType) = END;
			return tag.substr(foundStart + 2, (foundEnd - foundStart - 2));
		}
	}

	return toReturn;
}