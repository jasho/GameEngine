#include "UpdaterRunning.h"
#include "../../Render/RenderManager.h"
#include <Windows.h>
#include <iostream>

void UpdaterRunning::Update()
{
	RenderManager::GetInstance()->RenderScene();
}