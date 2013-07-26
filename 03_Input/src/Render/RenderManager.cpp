#include <cstdio>
#include "RenderManager.h"
#include "Renderers/Renderer.h"
#include "Renderers/RendererOpenGL.h"

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

void RenderManager::StartDrawingScene(void) const
{
	_renderer->StartDrawingScene();
}

void RenderManager::StopDrawingScene(void) const
{
	_renderer->StopDrawingScene();
}

void RenderManager::StartDrawingSceneNode(const Vector3 &position, const Vector3 &orientation) const
{
	_renderer->StartDrawingSceneNode(position, orientation);
}

void RenderManager::StopDrawingSceneNode(void) const
{
	_renderer->StopDrawingSceneNode();
}

void RenderManager::DrawCube(const Vector3& leftUpForwardVertex, const Vector3& rightBottomBackVertex, const Color& color) const
{
	_renderer->DrawCube(leftUpForwardVertex, rightBottomBackVertex, color );
}