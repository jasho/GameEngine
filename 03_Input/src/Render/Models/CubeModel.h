#ifndef CUBEMODEL_HEADER
#define CUBEMODEL_HEADER

#include "Model.h"
#include "../../Misc/Color.h"
#include <vector>

using namespace std;

#define STRING_ENTITY_TYPE_CUBES "Cubes"

class CubeModel : public Model
{
public:
	virtual void Render() const;
private:
	vector<vector<vector<Color *>>> _cubes;
};

#endif