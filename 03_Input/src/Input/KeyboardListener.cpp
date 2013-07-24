#include "KeyboardListener.h"
#include "InputManager.h"

KeyboardListener::KeyboardListener()
{
	InputManager::GetInstance()->AddKeyboardListener(this);
}

KeyboardListener::~KeyboardListener()
{
	if(!InputManager::GetInstance()->RemoveKeyboardListener(this))
	{
	}
}