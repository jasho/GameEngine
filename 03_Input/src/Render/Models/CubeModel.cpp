#include "CubeModel.h"
#include "../RenderManager.h"
#include "../../Misc/Conversions.h"
#include "../../Serialize/SerializationStrings.h"

using namespace std;

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
	outputStream << STRING_CUBEMODEL_TYPE << STRING_LINE_SEPARATOR;

}

void CubeModel::LoadFromInputStream(std::istream&)
{

}