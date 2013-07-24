#include <SDL/SDL.h>
#include <cstdlib>

#ifdef _WIN32
#undef main
#endif

#include "Update\UpdateManager.h"

int wmain(int argc, char *argv[])
{
	UpdateManager::Create();

	if(UpdateManager::GetInstance()->Initialize() == false)
	{
		UpdateManager::Destroy();

		return EXIT_FAILURE;
	}

	UpdateManager::GetInstance()->Run();

	return EXIT_SUCCESS;
}