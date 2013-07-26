#ifndef SERIALIZATIONHELPERMANAGER_HEADER
#define SERIALIZATIONHELPERMANAGER_HEADER

#include <string>
#include <map>

class SerializationHelper;

class SerializationHelperManager
{
public:
	static SerializationHelperManager* GetInstance();
	static void Create(void);
	static void Destroy(void);

	bool Initialize(void);

	std::string GetStartTag(std::string tagName, std::map<std::string, std::string>* attributes) const;
	std::string GetEndTag(std::string tagName) const;

protected:
	enum SerializationHelperType { XML };

	SerializationHelperType _prefferedHelperType;

	static SerializationHelperManager* _instance;

	SerializationHelper* _serializationHelper;

private:
	SerializationHelperManager(SerializationHelperType helperType = XML);
	~SerializationHelperManager();
};

#endif // SERIALIZATIONHELPERMANAGER_HEADER