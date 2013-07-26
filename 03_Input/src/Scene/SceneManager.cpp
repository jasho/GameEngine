#include <cstdio>
#include "SceneManager.h"
#include "SceneNode.h"

SceneManager* SceneManager::_instance = NULL;

SceneManager::SceneManager()
{
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
	_sceneNodeRoot->Render();
}