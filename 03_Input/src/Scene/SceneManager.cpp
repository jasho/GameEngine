#include <cstdio>
#include "SceneManager.h"
#include "SceneNode.h"
#include "../Render/RenderManager.h"
#include "../Serialize/SerializationHelperManager.h"
#include "../Serialize/SerializationStrings.h"
#include "../Render/Camera/Camera.h"

//remove this include
#include "../Render/Models/CubeModel.h"

SceneManager* SceneManager::_instance = NULL;

SceneManager::SceneManager()
{
	_sceneNodeRoot = new SceneNode(new CubeModel(), Vector3(0.0f, 0.0f, -10.0f));
	_currentCamera = new Camera();
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

void SceneManager::CameraMove(const Vector3& translation)
{
	_currentCamera->Move(translation);
}

void SceneManager::CameraRotate(const Vector3& rotation)
{
	_currentCamera->Rotate(rotation);
}

void SceneManager::RenderScene() const
{

	RenderManager::GetInstance()->StartDrawingScene();

	_currentCamera->Transform();

	_sceneNodeRoot->Render();

	RenderManager::GetInstance()->StopDrawingScene();
}

void SceneManager::SaveToOutputStream(std::ostream& outputStream) const
{
	outputStream << SerializationHelperManager::GetInstance()->GetStartTag( STRING_SCENEMANAGER_SCENE_TAGNAME , NULL);
	_sceneNodeRoot->SaveToOutputStream( outputStream );	
	outputStream << SerializationHelperManager::GetInstance()->GetEndTag( STRING_SCENEMANAGER_SCENE_TAGNAME );
}

bool SceneManager::LoadFromInputStream(std::istream&)
{
	return true;
}

