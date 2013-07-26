#ifndef CUBEMODEL_HEADER
#define CUBEMODEL_HEADER

#include "Model.h"
#include "../../Misc/Color.h"
#include <vector>
#include <string>

using namespace std;

class CubeModel : public Model
{
public:
	virtual void Draw() const;
	
	virtual void SaveToOutputStream(std::ostream&) const;
	virtual void LoadFromInputStream(std::istream&);

private:
	vector<vector<vector<Color *>>> _cubes;
};

#endif