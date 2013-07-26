#include <cstdio>
#include "SerializationHelperManager.h"
#include "SerializationHelpers\SerializationHelper.h"
#include "SerializationHelpers\SerializationHelperXml.h"

using namespace std;

SerializationHelperManager* SerializationHelperManager::_instance = NULL;

SerializationHelperManager::SerializationHelperManager(SerializationHelperType helperType)
{
	switch (helperType)
	{
	case SerializationHelperManager::XML:
		_serializationHelper = new SerializationHelperXml();
		break;
	default:
		break;
	}
}

SerializationHelperManager::~SerializationHelperManager()
{
}

SerializationHelperManager* SerializationHelperManager::GetInstance()
{
	return _instance;
}

void SerializationHelperManager::Create()
{
	if(_instance == NULL)
	{
		_instance = new SerializationHelperManager();
	}
}

void SerializationHelperManager::Destroy()
{
	if(_instance != NULL)
	{
		delete _instance;
		_instance = NULL;
	}
}

string SerializationHelperManager::GetStartTag(string tagName, map<string, string>* attributes) const
{
	return _serializationHelper->GetStartTag(tagName, attributes);
}

string SerializationHelperManager::GetEndTag(string tagName) const
{
	return _serializationHelper->GetEndTag(tagName);
}