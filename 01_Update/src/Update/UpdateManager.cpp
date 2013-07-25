#include <cstdio>
#include <SDL/SDL.h>
#include "UpdateManager.h"
#include "Updaters/Updater.h"
#include "Updaters/UpdaterRunning.h"
#include "Updaters/UpdaterPaused.h"

UpdateManager* UpdateManager::_instance = NULL;

UpdateManager::UpdateManager()
{
}

UpdateManager::~UpdateManager()
{
}

UpdateManager* UpdateManager::GetInstance()
{	
	return _instance;
}

void UpdateManager::Create()
{
	if(_instance == NULL)
	{
		_instance = new UpdateManager();
	}
}

void UpdateManager::Destroy()
{
	if(_instance != NULL)
	{
		delete _instance;
	}
}

bool UpdateManager::Initialize()
{
	_currentGameState = RUNNING;
	_previousGameState = RUNNING;

	return true;
}

void UpdateManager::Run()
{
	switch (_currentGameState)
	{
	case RUNNING:
		_currentUpdater = new UpdaterRunning();
		break;
	case PAUSED:
		_currentUpdater = new UpdaterPaused();
		break;
	default:
		break;
	}

	SDL_Event currentEvent;
	while(_currentGameState!= QUITTING)
	{
		switch (_currentGameState)
		{
		case UpdateManager::RUNNING:
			break;
		case UpdateManager::PAUSED:
			break;
		case UpdateManager::QUITTING:		
			break;
		default:
			break;
		}
		
		_currentUpdater->Update();
	}
}