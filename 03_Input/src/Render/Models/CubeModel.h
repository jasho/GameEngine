#ifndef CUBEMODEL_HEADER
#define CUBEMODEL_HEADER

#include "Model.h"

#define STRING_ENTITY_TYPE_CUBES "Cubes"

class CubeModel : public Model
{
public:
	virtual void Render() const;
};

#endif