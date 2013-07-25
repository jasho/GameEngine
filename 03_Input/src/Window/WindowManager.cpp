#include "WindowManager.h"
#include "../Update/UpdateManager.h"

WindowManager * WindowManager::_instance = NULL;

WindowManager::WindowManager()
{

}

WindowManager * WindowManager::GetInstance()
{
	return _instance;
}

void WindowManager::Create()
{
	if(_instance == NULL)
	{
		_instance = new WindowManager();
	}
}

void WindowManager::Destroy()
{
	if(_instance != NULL)
	{
		delete _instance;
	}
}

void WindowManager::OnWindowEvent(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_ACTIVEEVENT:
		break;
	case SDL_QUIT:
		UpdateManager::GetInstance()->Quit();
		break;
	case SDL_VIDEORESIZE:
	case SDL_VIDEOEXPOSE:
		break;
	}
}