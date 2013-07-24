#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <string>
#include "../Update/Updatable.h"
#include "../Misc/Vectors/Vector3.h"

class Entity : public Updatable
{
public:
	enum EntityType {  };

protected:	
	EntityType _type;
	std::string _name;
	Vector3 _position;
};

#endif