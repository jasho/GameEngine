#include "CubeModel.h"
#include "../RenderManager.h"
#include "../../Misc/Conversions.h"
#include <iostream>
#include <fstream>
#include <string>
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

void CubeModel::SaveToFile(std::istream&)
{
	// get a data string
	string tmp = SaveToString();
	ofstream output(fname);
	output.write(tmp.c_str(), tmp.size());
	output.close();
}

void CubeModel::LoadFromFile(std::ostream&) const
{
}

string CubeModel::SaveToString() const
{
	// temporary things we need
	string buffer("");
	string tmp;
	int width = _cubes.size();
	int height = _cubes[0].size();
	int length = _cubes[0][0].size();

	// write first line with sizes
	Conversions::IntToString(width, &tmp);
	buffer.append(tmp + SPACE_SEPARATOR);
	Conversions::IntToString(height, &tmp);
	buffer.append(tmp + SPACE_SEPARATOR);
	Conversions::IntToString(length, &tmp);
	buffer.append(tmp + SPACE_SEPARATOR);
	buffer.append(LINE_SEPARATOR);

	for(int h=0; h<height; h++)
	{
		// insert a comment line for clarity of view
		buffer.append(COMMENT_SIGN);
		buffer.append(LINE_SEPARATOR);

		for(int l=0; l<length; l++)
		{
			for(int w=0; w<width; w++)
			{
				Conversions::IntToString(_cubes[w][h][l], &tmp);
				buffer.append(tmp + SPACE_SEPARATOR);
			}
			buffer.append(LINE_SEPARATOR);
		}
	}

	return buffer;
}