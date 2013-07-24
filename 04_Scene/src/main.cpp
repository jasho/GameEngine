#include <SDL/SDL.h>
#include <cstdlib>

#ifdef _WIN32
#undef main
#endif

#include "Update\UpdateManager.h"
#include "Render\RenderManager.h"

int wmain(int argc, char *argv[])
{
	UpdateManager::Create();
	RenderManager::Create();

	if(UpdateManager::GetInstance()->Initialize() == false)
	{
		UpdateManager::Destroy();
		RenderManager::Destroy();

		return EXIT_FAILURE;
	}

	if(RenderManager::GetInstance()->Initialize() == false)
	{
		UpdateManager::Destroy();
		RenderManager::Destroy();

		return EXIT_FAILURE;
	}

	UpdateManager::GetInstance()->Run();

	return EXIT_SUCCESS;
}