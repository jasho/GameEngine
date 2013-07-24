#include <cstdio>
#include "RenderManager.h"
#include "Renderers/Renderer.h"
#include "Renderers/RendererOpenGL.h"

#include <Windows.h>

RenderManager* RenderManager::_instance = NULL;

RenderManager::RenderManager(void)
{
	_prefferedRenderer = RENDERER_TYPE_OPENGL;
	_windowWidth = 640;
	_windowHeight = 480;
	_fullscreen = false;

	tmpYRotation = -90.0f;
}

RenderManager::~RenderManager(void)
{
}

RenderManager* RenderManager::GetInstance()
{
	return _instance;
}

void RenderManager::Create(void)
{
	if(_instance == NULL)
	{
		_instance = new RenderManager();
	}
}

void RenderManager::Destroy(void)
{
	if(_instance != NULL)
	{
		delete _instance;
	}
}

bool RenderManager::Initialize(void)
{
	switch (_prefferedRenderer)
	{
	case RenderManager::RENDERER_TYPE_OPENGL:
		_renderer = new RendererOpenGL();
		break;
	case RenderManager::RENDERER_TYPE_DIRECTX:
		break;
	default:
		break;
	}

	return _renderer->Initialize();
}

int RenderManager::GetWindowWidth(void) const
{
	return _windowWidth;
}

void RenderManager::SetWindowWidth(int windowWidth)
{
	_windowWidth = windowWidth;
}

int RenderManager::GetWindowHeight(void) const
{
	return _windowHeight;
}

void RenderManager::SetWindowHeight(int windowHeight)
{
	_windowHeight = windowHeight;
}

bool RenderManager::IsFullscreen(void) const
{
	return _fullscreen;
}

void RenderManager::ToggleFullscreen(void)
{
	_fullscreen = !_fullscreen;
}

void RenderManager::RenderScene(void)
{
	_renderer->StartDrawingScene();
	Vector3 cameraPosition(0.0f, 0.0f, 0.0f);
	Vector3 cameraRotation(0.0f, tmpYRotation, 0.0f);
	_renderer->TransformCamera(cameraPosition, cameraRotation);
	//_renderer->DrawTriangle();
	Vector3 leftUpForwardVertex(0.0f, 1.0f, -10.0f);
	Vector3 rightBottomBackVertex(1.0f, 0.0f, -20.0f);
	Vector3 color(1.0f, 0.0f, 0.0f);
	_renderer->DrawCube(leftUpForwardVertex, rightBottomBackVertex, color);
	_renderer->StopDrawingScene();

	tmpYRotation += 1.0f;
	if(tmpYRotation > 90.0f)
	{
		tmpYRotation = -90.0f;
	}

	Sleep(10);
}