#ifndef RENDERER_HEADER
#define RENDERER_HEADER

#include "../../Misc/Vectors/Vector3.h"
#include "../../Misc/Color.h"

class Renderer {
public:
	Renderer(void);
	virtual ~Renderer(void);

	virtual bool Initialize(void) = 0;
	virtual void StartDrawingScene(void) const = 0;
	virtual void StopDrawingScene(void) const = 0;

	virtual void StartDrawingSceneNode(const Vector3 &position, const Vector3 &orientation) const = 0;
	virtual void StopDrawingSceneNode(void) const = 0;

	virtual void DrawTriangle(void) const = 0;
	virtual void DrawCube(const Vector3& leftUpForwardVertex, const Vector3& rightBottomBackVertex, const Color &color) const = 0;

	virtual void TransformCamera(const Vector3& position, const Vector3& orientation) const = 0;
};

#endif // RENDERER_HEADER