#include "SceneNode.h"

SceneNode::SceneNode()
{
}

SceneNode::~SceneNode()
{
}

void SceneNode::Translate(int x, int y, int z)
{
	_position.SetValues( _position.GetX() + x, _position.GetY() + y, _position.GetZ + z );
}

void SceneNode::Translate( Vector3 vector )
{
	_position.SetValues( _position.GetX() + vector.GetX() , _position.GetY() + vector.GetY() , _position.GetZ + vector.GetZ() );
}

void SceneNode::Rotate( Vector3 vector )
{
	_rotation.SetValues( _rotation.GetX() + vector.GetX() , _rotation.GetY() + vector.GetY() , _rotation.GetZ + vector.GetZ() );
}

void SceneNode::Rotate( int x, int y, int z )
{
	_rotation.SetValues( _rotation.GetX() + x, _rotation.GetY() + y, _rotation.GetZ + z );
}

void SceneNode::Scale( Vector3 vector )
{
	_scale.SetValues( _scale.GetX() + vector.GetX() , _scale.GetY() + vector.GetY() , _scale.GetZ + vector.GetZ() );
}

void SceneNode::Scale ( int x, int y, int z )
{
	_scale.SetValues( _scale.GetX() + x, _scale.GetY() + y, _scale.GetZ + z );
}


void SceneNode::addChildNode(SceneNode * node)
{
	_children.push_back( node );
}

void SceneNode::removeChildNode(SceneNode * node)
{
	vector<SceneNode *>::const_iterator found = find(_children.cbegin(), _children.cend(), node); 
	if(found != _children.cend()) 
	{ 
		_children.erase(found);
	}
}

