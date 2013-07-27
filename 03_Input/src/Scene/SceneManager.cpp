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
	outputStream << SerializationHelperManager::GetInstance()->GetStartTag( STRING_SCENEMANAGER_TAGNAME , NULL);
	_sceneNodeRoot->SaveToOutputStream( outputStream );	
	outputStream << SerializationHelperManager::GetInstance()->GetEndTag( STRING_SCENEMANAGER_TAGNAME );
}

bool SceneManager::LoadFromInputStream(std::istream& inputStream)
{
	string line = "";
	string tagName = "";
	TagType tagType;

	while(!inputStream.eof() 
		|| (tagName != STRING_SCENEMANAGER_TAGNAME && tagType != TagType::END) )
	{
		getline(inputStream, line);
		tagName = SerializationHelperManager::GetInstance()->GetTagNameFromTag(line, &tagType);

		if(tagType == TagType::START)
		{
			if(tagName == STRING_SCENENODE_TAGNAME)
			{
				SceneNode* newSceneNode = new SceneNode(inputStream);

				_sceneNodeRoot = newSceneNode;
			}
		}
	}


	return true;
}

