#include "Camera.h"
#include "../RenderManager.h"

void Camera::Transform()
{
	RenderManager::GetInstance()->TransformCamera(_position, _rotation);
}

void Camera::Move(Vector3 translation)
{
	_position += translation;
}

void Camera::Rotate(Vector3 rotation)
{
	_rotation += rotation;
}