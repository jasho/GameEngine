#include <SDL/SDL.h>
#include <cstdlib>

#ifdef _WIN32
#undef main
#endif

#include "Update\UpdateManager.h"
#include "Render\RenderManager.h"
#include "Event\EventManager.h"
#include "Input\InputManager.h"
#include "Window\WindowManager.h"
#include "Scene\SceneManager.h"
#include "Serialize\SerializationHelperManager.h"
#include "Player\PlayerManager.h"

int wmain(int argc, char *argv[])
{
	SerializationHelperManager::Create();
	EventManager::Create();
	InputManager::Create();
	PlayerManager::Create();
	SceneManager::Create();
	UpdateManager::Create();
	RenderManager::Create();	
	WindowManager::Create();

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
	SceneManager::GetInstance()->SaveToFile("testOutput");

	UpdateManager::Destroy();
	EventManager::Destroy();
	InputManager::Destroy();
	RenderManager::Destroy();
	WindowManager::Destroy();

	return EXIT_SUCCESS;
}