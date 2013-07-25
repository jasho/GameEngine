#include <cstdlib>
#include "EventManager.h"
#include "../Input/InputManager.h"
#include "../Update/UpdateManager.h"
#include "../Window/WindowManager.h"

EventManager* EventManager::_instance = NULL;

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}

EventManager* EventManager::GetInstance()
{
	return _instance;
}

void EventManager::Create()
{
	if(_instance == NULL)
	{
		_instance = new EventManager();
	}
}

void EventManager::Destroy()
{
	if(_instance != NULL)
	{
		delete _instance;
		_instance = NULL;
	}
}

void EventManager::OnEvent(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_ACTIVEEVENT:
	case SDL_QUIT:
	case SDL_VIDEORESIZE:
	case SDL_VIDEOEXPOSE:
		WindowManager::GetInstance()->OnWindowEvent(event);	
		break;
	// Keyboard
	case SDL_KEYDOWN:
	case SDL_KEYUP:
	// Mouse
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
	case SDL_MOUSEBUTTONUP:
	// Joystick
	case SDL_JOYAXISMOTION:
	case SDL_JOYBALLMOTION:
	case SDL_JOYBUTTONDOWN:
	case SDL_JOYBUTTONUP:
		InputManager::GetInstance()->OnInputEvent(event);
		break;
	default:
		break;
	}
}