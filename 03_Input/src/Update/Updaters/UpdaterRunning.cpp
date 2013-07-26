#include "UpdaterRunning.h"
#include "../../Render/RenderManager.h"
#include "../../Scene/SceneManager.h"

void UpdaterRunning::Update()
{
	SceneManager::GetInstance()->RenderScene();
}