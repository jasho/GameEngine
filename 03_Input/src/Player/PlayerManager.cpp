#include "PlayerManager.h"
#include <iostream>
#include <SDL/SDL.h>

PlayerManager::PlayerManager()
{

}

PlayerManager::~PlayerManager()
{

}

void PlayerManager::Create()
{
	if(_instance == NULL)
	{
		_instance = new PlayerManager();
	}
}

void PlayerManager::Destroy()
{
	if( _instance != NULL )
	{
		delete _instance;
	}
}

PlayerManager * PlayerManager::GetInstance()
{
	return _instance;
}

//void PlayerManager::OnPlayerEvent(SDL_Event* event)
//{
//	switch(event->type)
//	{
//
//	}
//}
