#include <SDL/SDL.h>
#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32
#include <gl/GL.h>
#include <gl/GLU.h>
#include "RendererOpenGL.h"
#include "../RenderManager.h"

RendererOpenGL::RendererOpenGL(void)
{
}

RendererOpenGL::~RendererOpenGL(void)
{
}

bool RendererOpenGL::Initialize(void)
{
	if(InitializeSDL() == false)
	{
		return false;
	}

	glClearColor(0, 0, 0, 0);
	glClearDepth(1.0f);
 
	glViewport(0, 0, RenderManager::GetInstance()->GetWindowWidth(), RenderManager::GetInstance()->GetWindowHeight());
 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(
		45.0f,
		(GLfloat)RenderManager::GetInstance()->GetWindowWidth()/(GLfloat)RenderManager::GetInstance()->GetWindowHeight(),
		0.1f,
		100.0f);
 
	glMatrixMode(GL_MODELVIEW);
 
	glEnable(GL_TEXTURE_2D);
 
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	return true;
}

bool RendererOpenGL::InitializeSDL(void)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);
 
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,          16);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,         32);
 
	SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,      8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,     8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);
 
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
 
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);

	if((_surfDisplay = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL)
	{
		return false;
	}

	return true;
}

void RendererOpenGL::StartDrawingScene(void) const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix
}

void RendererOpenGL::StopDrawingScene(void) const
{
	SDL_GL_SwapBuffers();
}

void RendererOpenGL::DrawTriangle(void) const
{
	glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0); glVertex3f(0, 0, -10);
		glColor3f(1, 0, 1); glVertex3f(1, 1, -10);
		glColor3f(1, 1, 0); glVertex3f(1, 0, -10);        
	glEnd();
}

void RendererOpenGL::DrawCube(const Vector3& leftUpForwardVertex, const Vector3& rightBottomBackVertex, const Vector3& color) const
{
	// Set the color
	glColor3f(color.GetX(), color.GetY(), color.GetZ());
	
	glBegin(GL_QUADS);
		// Top face
		glVertex3f(leftUpForwardVertex.GetX(), leftUpForwardVertex.GetY(), leftUpForwardVertex.GetZ());
		glVertex3f(rightBottomBackVertex.GetX(), leftUpForwardVertex.GetY(), leftUpForwardVertex.GetZ());
		glVertex3f(rightBottomBackVertex.GetX(), leftUpForwardVertex.GetY(), rightBottomBackVertex.GetZ());
		glVertex3f(leftUpForwardVertex.GetX(), leftUpForwardVertex.GetY(), rightBottomBackVertex.GetZ());

		// Bottom face
		glVertex3f(leftUpForwardVertex.GetX(), rightBottomBackVertex.GetY(), leftUpForwardVertex.GetZ());
		glVertex3f(leftUpForwardVertex.GetX(), rightBottomBackVertex.GetY(), rightBottomBackVertex.GetZ());
		glVertex3f(rightBottomBackVertex.GetX(), rightBottomBackVertex.GetY(), rightBottomBackVertex.GetZ());
		glVertex3f(rightBottomBackVertex.GetX(), rightBottomBackVertex.GetY(), leftUpForwardVertex.GetZ());

		// Front face
		glVertex3f(leftUpForwardVertex.GetX(), leftUpForwardVertex.GetY(), leftUpForwardVertex.GetZ());
		glVertex3f(leftUpForwardVertex.GetX(), rightBottomBackVertex.GetY(), leftUpForwardVertex.GetZ());
		glVertex3f(rightBottomBackVertex.GetX(), rightBottomBackVertex.GetY(), leftUpForwardVertex.GetZ());
		glVertex3f(rightBottomBackVertex.GetX(), leftUpForwardVertex.GetY(), leftUpForwardVertex.GetZ());

		// Back face
		glVertex3f(rightBottomBackVertex.GetX(), leftUpForwardVertex.GetY(), rightBottomBackVertex.GetZ());
		glVertex3f(rightBottomBackVertex.GetX(), rightBottomBackVertex.GetY(), rightBottomBackVertex.GetZ());
		glVertex3f(leftUpForwardVertex.GetX(), rightBottomBackVertex.GetY(), rightBottomBackVertex.GetZ());
		glVertex3f(leftUpForwardVertex.GetX(), leftUpForwardVertex.GetY(), rightBottomBackVertex.GetZ());

		// Left face
		glVertex3f(leftUpForwardVertex.GetX(), leftUpForwardVertex.GetY(), rightBottomBackVertex.GetZ());
		glVertex3f(leftUpForwardVertex.GetX(), rightBottomBackVertex.GetY(), rightBottomBackVertex.GetZ());
		glVertex3f(leftUpForwardVertex.GetX(), rightBottomBackVertex.GetY(), leftUpForwardVertex.GetZ());
		glVertex3f(leftUpForwardVertex.GetX(), leftUpForwardVertex.GetY(), leftUpForwardVertex.GetZ());

		// Right face
		glVertex3f(rightBottomBackVertex.GetX(), leftUpForwardVertex.GetY(), leftUpForwardVertex.GetZ());
		glVertex3f(rightBottomBackVertex.GetX(), rightBottomBackVertex.GetY(), leftUpForwardVertex.GetZ());
		glVertex3f(rightBottomBackVertex.GetX(), rightBottomBackVertex.GetY(), rightBottomBackVertex.GetZ());
		glVertex3f(rightBottomBackVertex.GetX(), leftUpForwardVertex.GetY(), rightBottomBackVertex.GetZ());
	glEnd();
}

void RendererOpenGL::TransformCamera(const Vector3& position, const Vector3& orientation) const 
{
	// Rotate the object On Z, X & Y - work in progress
	glRotatef(-orientation.GetX(), 1, 0, 0);
	glRotatef(-orientation.GetY(), 0, 1, 0);

	// Move the object
	glTranslatef(-position.GetX(), -position.GetY(), -position.GetZ());
}