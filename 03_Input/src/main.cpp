#include <SDL/SDL.h>
#include <cstdlib>

#ifdef _WIN32
#undef main
#endif

#include "Update\UpdateManager.h"
#include "Render\RenderManager.h"
#include "Event\EventManager.h"
#include "Input\InputManager.h"

int wmain(int argc, char *argv[])
{
	EventManager::Create();
	InputManager::Create();
	UpdateManager::Create();
	RenderManager::Create();	

	if(UpdateManager::GetInstance()->Initialize() == false)
	{
		EventManager::Destroy();
		InputManager::Destroy();
		UpdateManager::Destroy();
		RenderManager::Destroy();

		return EXIT_FAILURE;
	}

	if(RenderManager::GetInstance()->Initialize() == false)
	{	
		EventManager::Destroy();
		InputManager::Destroy();
		UpdateManager::Destroy();
		RenderManager::Destroy();

		return EXIT_FAILURE;
	}

	UpdateManager::GetInstance()->Run();

	EventManager::Destroy();
	InputManager::Destroy();
	UpdateManager::Destroy();
	RenderManager::Destroy();

	return EXIT_SUCCESS;
}