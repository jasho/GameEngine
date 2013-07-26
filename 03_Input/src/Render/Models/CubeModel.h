#ifndef CUBEMODEL_HEADER
#define CUBEMODEL_HEADER

#include "Model.h"
#include "../../Misc/Color.h"
#include <vector>
#include <string>

using namespace std;

#define STRING_ENTITY_TYPE_CUBES "Cubes"

class CubeModel : public Model
{
public:
	virtual void Draw() const;
	virtual void SaveToFile(std::istream&);
	virtual void LoadFromFile(std::ostream&) const;
	virtual string SaveToString() const;
	virtual void LoadToString() const;
private:
	vector<vector<vector<Color *>>> _cubes;
};

#endif