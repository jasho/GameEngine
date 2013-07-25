#ifndef MODEL_HEADER
#define MODEL_HEADER

#include "../../Serialize/Serializable.h"

class Model : public Serializable
{
public:
	virtual void Render() const = 0;
};

#endif // MODEL_HEADER