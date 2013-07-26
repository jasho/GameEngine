#include <cstdio>
#include "SceneManager.h"
#include "SceneNode.h"
#include "../Render/RenderManager.h"

//remove this include
#include "../Render/Models/CubeModel.h"

SceneManager* SceneManager::_instance = NULL;

SceneManager::SceneManager()
{
	_sceneNodeRoot = new SceneNode(new CubeModel(), Vector3(0.0f, 0.0f, -10.0f));
}

SceneManager::~SceneManager()
{
}

void SceneManager::Create()
{
	if(_instance == NULL)
	{
		_instance = new SceneManager();
	}
}

void SceneManager::Destroy()
{
	if(_instance != NULL)
	{
		delete _instance;
	}
}

SceneManager* SceneManager::GetInstance()
{
	return _instance;
}

void SceneManager::RenderScene() const
{
	RenderManager::GetInstance()->StartDrawingScene();

	_sceneNodeRoot->Render();

	RenderManager::GetInstance()->StopDrawingScene();
}