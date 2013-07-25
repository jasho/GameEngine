#include "SceneNode.h"
#include "../Render/Models/Model.h"
#include "../Render/RenderManager.h"

SceneNode::SceneNode()
{
}

SceneNode::~SceneNode()
{
}

Vector3 SceneNode::GetPosition() const
{
	return _position;
}

Vector3 SceneNode::GetScale() const
{
	return _scale;
}

Vector3 SceneNode::GetRotation() const
{
	return _rotation;
}

void SceneNode::Translate(int x, int y, int z)
{
	_position.SetValues( _position.GetX() + x, _position.GetY() + y, _position.GetZ() + z );
}

void SceneNode::Translate( Vector3 translation )
{
	_position.SetValues( _position.GetX() + translation.GetX() , _position.GetY() + translation.GetY() , _position.GetZ() + translation.GetZ() );
}

void SceneNode::Rotate( Vector3 rotation )
{
	_rotation.SetValues( _rotation.GetX() + rotation.GetX() , _rotation.GetY() + rotation.GetY() , _rotation.GetZ() + rotation.GetZ() );
}

void SceneNode::Rotate( int x, int y, int z )
{
	_rotation.SetValues( _rotation.GetX() + x, _rotation.GetY() + y, _rotation.GetZ() + z );
}

void SceneNode::Scale( Vector3 scale )
{
	_scale.SetValues( _scale.GetX() + scale.GetX() , _scale.GetY() + scale.GetY() , _scale.GetZ() + scale.GetZ() );
}

void SceneNode::Scale ( int x, int y, int z )
{
	_scale.SetValues( _scale.GetX() + x, _scale.GetY() + y, _scale.GetZ() + z );
}

void SceneNode::Render() const
{
	RenderManager::GetInstance()->StartDrawingSceneNode(_position, _rotation);

		_model->Render();

		vector<SceneNode*>::const_iterator childNodeIterator;
		for(childNodeIterator = _children.begin(); childNodeIterator != _children.end(); ++childNodeIterator)
		{
			(*childNodeIterator)->Render();
		}

	RenderManager::GetInstance()->StopDrawingSceneNode();
}

void SceneNode::addChildNode(SceneNode * node)
{
	_children.push_back( node );
}

void SceneNode::removeChildNode(SceneNode * node)
{
	vector<SceneNode *>::const_iterator foundNode = find(_children.cbegin(), _children.cend(), node); 
	if(foundNode != _children.cend()) 
	{ 
		_children.erase(foundNode);
	}
}
