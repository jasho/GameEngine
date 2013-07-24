#include "Updatable.h"
#include "UpdateManager.h"
#include "..\Misc\Conversions.h"

Updatable::Updatable(int frequency) 
{
	_freq = frequency;
	_lastUpdateTime = 0;
}

Updatable::~Updatable() 
{
}


void Updatable::Update()
{
	_lastUpdateTime = UpdateManager::GetInstance()->GetTicksElapsed();
}

/**
* Returns how many times the object needs to be updated
* \param time Current gametime.
* \return Number of updates which is needed to be done for the object.
*/
int Updatable::CheckTime() 
{
	long long interval = UpdateManager::GetInstance()->GetTicksElapsed() - _lastUpdateTime;
	return (int)(interval / (1000.0 /_freq));
}