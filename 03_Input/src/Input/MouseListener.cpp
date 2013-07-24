#include "MouseListener.h"
#include "InputManager.h"

MouseListener::MouseListener()
{
	InputManager::GetInstance()->AddMouseListener(this);
}

MouseListener::~MouseListener()
{
	if(!InputManager::GetInstance()->RemoveMouseListener(this))
	{
	}
}