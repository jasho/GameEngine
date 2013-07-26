#include "Serializable.h"
#include <fstream>

using namespace std;

void Serializable::SaveToFile(string fileName) const
{
	ofstream outputFileStream;
	outputFileStream.open(fileName, ios::out | ios::trunc);
	if(!outputFileStream.is_open())
	{
		return;
	}

	SaveToOutputStream(outputFileStream);

	outputFileStream.close();
}

bool Serializable::LoadFromFile(string fileName)
{
	ifstream inputFileStream;
	inputFileStream.open(fileName, ios::in);
	if(!inputFileStream.is_open())
	{
		return;
	}

	LoadFromInputStream(inputFileStream);
}