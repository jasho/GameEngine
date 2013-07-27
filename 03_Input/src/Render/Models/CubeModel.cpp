#include "CubeModel.h"
#include "../RenderManager.h"
#include "../../Misc/Conversions.h"
#include "../../Serialize/SerializationStrings.h"
#include "../../Serialize/SerializationHelperManager.h"

using namespace std;

CubeModel::CubeModel()
{
	_cubes = vector<vector<vector<Color *>>>(1);
	_cubes[0] = vector<vector<Color *>>(1);
	_cubes[0][0] = vector<Color *>(1);

	_cubes[0][0][0] = new Color(1.0f, 1.0f, 1.0f);
}

CubeModel::CubeModel(istream& inputStream)
{
	LoadFromInputStream(inputStream);
}

CubeModel::~CubeModel()
{

}

void CubeModel::Draw() const
{
	int sizeX = _cubes.size();

	int sizeY = _cubes[0].size();
	int sizeZ = _cubes[0][0].size();
		
	for( int x = 0; x < sizeX; ++x )
	{
		for( int y = 0; y < sizeY; ++y )
		{
			for( int z = 0; z < sizeZ; ++z )
			{
				if( _cubes[x][y][z] != NULL )
				{
					RenderManager::GetInstance()->DrawCube( Vector3(x, y, z) , Vector3(x + 1, y + 1, z + 1 ), * _cubes[x][y][z] );
				}
			}
		}
	}
}

void CubeModel::SaveToOutputStream(std::ostream& outputStream) const
{
	int sizeX = _cubes.size();
	int sizeY = _cubes[0].size();
	int sizeZ = _cubes[0][0].size();

	outputStream << sizeX << STRING_SPACE_SEPARATOR;
	outputStream << sizeY << STRING_SPACE_SEPARATOR;
	outputStream << sizeY << STRING_LINE_SEPARATOR;

	for(int x = 0; x < sizeX; ++x)
	{
		for(int y = 0; y < sizeY; ++y)
		{
			for(int z = 0; z < sizeZ; ++z)
			{
				if(_cubes[x][y][z] == NULL)
				{
					outputStream << STRING_COLOR_NULL << STRING_SPACE_SEPARATOR;
				}
				else
				{
					_cubes[x][y][z]->SaveToOutputStream(outputStream);
				}
			}

			if(y < (sizeY - 1))
			{
				outputStream << STRING_LINE_SEPARATOR;
			}
		}

		if(x < (sizeX - 1))
		{
			outputStream << STRING_LAYER_SEPARATOR;
		}
	}
}

bool CubeModel::LoadFromInputStream(std::istream& inputStream)
{
	int sizeX, sizeY, sizeZ;
	inputStream >> sizeX >> sizeY >> sizeZ;

	_cubes = vector<vector<vector<Color *>>>(sizeX);
	
	for(int x = 0; x < sizeX; ++x)
	{
		_cubes[x] = vector<vector<Color *>>( sizeY );
		for(int y = 0; y < sizeY; ++y)
		{
			_cubes[x][y] = vector<Color *>( sizeZ );
			for(int z = 0; z < sizeZ; ++z)
			{
				Color * newCubeColor = new Color();
				if( newCubeColor->LoadFromInputStream(inputStream) )
				{
					_cubes[x][y][z] = newCubeColor;
				}
				else
				{
					_cubes[x][y][z] = NULL;
					delete newCubeColor;
				}
			}
		}
	}

	return true;
}