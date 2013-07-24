#include <cstdio>
#include <SDL/SDL.h>
#include "UpdateManager.h"
#include "Updaters/Updater.h"
#include "Updaters/UpdaterRunning.h"
#include "Updaters/UpdaterPaused.h"
#include "../Event/EventManager.h"

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

		while(SDL_PollEvent(&currentEvent))
		{
			EventManager::GetInstance()->OnEvent(&currentEvent);
		}
		
		_currentUpdater->Update();
	}
}

void UpdateManager::KeyDown(SDLKey symbol, SDLMod mode, Uint16 unicode)
{
	switch(symbol)
	{
	case SDLK_ESCAPE:
		_currentGameState = QUITTING;
	default:
		break;
	}
}

void UpdateManager::KeyUp(SDLKey symbol, SDLMod mode, Uint16 unicode)
{

}