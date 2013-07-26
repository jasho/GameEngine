#ifndef CAMERA_HEADER
#define CAMERA_HEADER

#include "../../Misc/Vectors/Vector3.h"

class Camera
{
public:
	void Transform();

	void Move(Vector3 translation);
	void Rotate(Vector3 rotation);

protected:
	Vector3 _position;
	Vector3 _rotation;
};

#endif // CAMERA_HEADER