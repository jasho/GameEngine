#ifndef SCENENODE_HEADER
#define SCENENODE_HEADER

#include "../Misc/Vectors/Vector3.h"
#include <vector>
using namespace std;

class SceneNode
{
public:
	SceneNode();
	~SceneNode();
	Vector3 GetPosition();
	Vector3 GetScale();
	
protected:
	void Translate(int, int, int);
	void Translate( Vector3 );
	void Rotate( Vector3 );
	void Rotate( int, int, int );
	void Scale( Vector3 );
	void Scale (int, int, int );

private:
	Vector3 _position;
	Vector3 _scale;
	Vector3 _rotation;

	vector<SceneNode *> _children;

	void addChildNode(SceneNode * node);
	void removeChildNode(SceneNode * node);
};
#endif