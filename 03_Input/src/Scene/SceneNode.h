#ifndef SCENENODE_HEADER
#define SCENENODE_HEADER

#include <vector>
#include "../Misc/Vectors/Vector3.h"
#include "../Serialize/Serializable.h"

using namespace std;

class Model;

class SceneNode : public Serializable
{
public:
	SceneNode();
	SceneNode(std::istream& inputStream);
	SceneNode(Model* model, Vector3& position = Vector3(0.0f, 0.0f, 0.0f), Vector3& rotation = Vector3(0.0f, 0.0f, 0.0f), Vector3& scale = Vector3(0.0f, 0.0f, 0.0f));
	~SceneNode();

	Vector3 GetPosition() const;
	Vector3 GetScale() const;
	Vector3 GetRotation() const;

	void Translate( Vector3 );
	void Translate(int, int, int);
	void Rotate( Vector3 );
	void Rotate( int, int, int );
	void Scale( Vector3 );
	void Scale (int, int, int );

	virtual void SaveToOutputStream(std::ostream&) const;
	virtual bool LoadFromInputStream(std::istream&);

	void Render() const;

private:
	Vector3 _position;
	Vector3 _scale;
	Vector3 _rotation;

	Model* _model;

	vector<SceneNode *> _children;

	void addChildNode(SceneNode * node);
	void removeChildNode(SceneNode * node);	
};
#endif