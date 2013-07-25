#ifndef RENDEREROPENGL_HEADER
#define RENDEREROPENGL_HEADER

#include "Renderer.h"

struct SDL_Surface;

class RendererOpenGL : public Renderer 
{
public:
	RendererOpenGL(void);
	~RendererOpenGL(void);

	bool Initialize(void);

	void StartDrawingScene(void) const;
	void StopDrawingScene(void) const;

	void DrawTriangle(void) const;
	void DrawCube(const Vector3& leftUpForwardVertex, const Vector3& rightBottomBackVertex, const Color& color) const;

	void TransformCamera(const Vector3& position, const Vector3& orientation) const;

protected:
	SDL_Surface* _surfDisplay;

	bool InitializeSDL(void);
};

#endif // RENDEREROPENGL_HEADER