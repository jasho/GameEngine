#include "InputManager.h"
#include "KeyboardListener.h"
#include "MouseListener.h"
#include "..\Misc\Vectors\Vector2.h"
#include <iostream>

using namespace std;

// Initialize the static variable.
InputManager* InputManager::_instance = NULL;

/**
* Default constructor.
*/
InputManager::InputManager()
{
	for(int i = 0; i < 256; ++i)
		_keys[i] = false;

	_mousePosition = new Vector2();	
	_isMouseLeftDown = false;

	_keyboardListeners = std::set<KeyboardListener *>();
	_mouseListeners = std::set<MouseListener *>();
}

/**
* Creates the unique instance of the InputManager.
*/
void InputManager::Create() 
{
	if(_instance == NULL)
	{
		_instance = new InputManager();
	}
}

/*
* Destroys the unique instance of the InputManager.
*/
void InputManager::Destroy()
{	
	// Destruction of the instance
	delete _instance;
	_instance = NULL;
}

void InputManager::OnInputEvent(SDL_Event* event)
{
	int a;
	switch (event->type)
	{
	// Keyboard
	case SDL_KEYDOWN:
		_keys[event->key.keysym.sym] = true;
		notifyKeyDown(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
		break;
	case SDL_KEYUP:
		_keys[event->key.keysym.sym] = false;
		notifyKeyUp(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
		break;
	// Mouse
	case SDL_MOUSEMOTION:
		notifyMouseMoved( event->motion.xrel , event->motion.yrel );
		std::cout << event->motion.x << " x " << event->motion.y << std::endl;
		break;

	case SDL_MOUSEBUTTONDOWN:
		switch(event->button.button)
		{
		case SDL_BUTTON_LEFT:
			notifyMouseLeftButtonClicked();
			break;
		case SDL_BUTTON_RIGHT:
			notifyMouseRightButtonClicked();
			break;
		}
		break;
	case SDL_MOUSEBUTTONUP:
	// Joystick
	case SDL_JOYAXISMOTION:
	case SDL_JOYBALLMOTION:
	case SDL_JOYBUTTONDOWN:
	case SDL_JOYBUTTONUP:
		break;

	default:
		break;
	}
}

/**
* Returns true if the key specified by the argument is currently pressed.
* \param wParam Code of the key to be checked.
*/
bool InputManager::IsKeyDown(SDLKey key) const 
{
	return _keys[key];
}

/**
* Force release the given key.
* \param key Keyboard key that is needed to be released.
*/
void InputManager::ResetKey(char key) 
{
	_keys[key] = false;
}

/**
* Adds a keyboard listener to the container of keyboard listeners.
* \param keyboardListener Listener to be added.
*/
void InputManager::AddKeyboardListener(KeyboardListener *keyboardListener) {
	_keyboardListeners.insert(keyboardListener);
}

bool InputManager::RemoveKeyboardListener(const KeyboardListener *keyboardListener)
{
	for(set<KeyboardListener *>::iterator iter = _keyboardListeners.begin(); iter != _keyboardListeners.end(); ++iter)
	{
		if((*iter) == keyboardListener)
		{
			_keyboardListeners.erase(iter);
			return true;
		}
	}

	return false;
}

bool InputManager::RemoveMouseListener(const MouseListener *mouseListener)
{
	for(set<MouseListener *>::iterator iter = _mouseListeners.begin(); iter != _mouseListeners.end(); ++iter)
	{
		if((*iter) == mouseListener)
		{
			_mouseListeners.erase(iter);
			return true;
		}
	}

	return false;
}

/**
* Adds a mouse listener to the container of mouse listeners.
* \param mouseListener Listener to be added.
*/
void InputManager::AddMouseListener(MouseListener *mouseListener) {
	_mouseListeners.insert(mouseListener);
}

/**
* Notifies all the keyboard listeners that a key was pressed.
*/
void InputManager::notifyKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) const 
{
	set<KeyboardListener*>::iterator iter;
	for(iter = _keyboardListeners.begin(); iter != _keyboardListeners.end(); ++iter)
	{
		(*iter)->KeyDown(sym, mod, unicode);
	}
}

/**
* Notifies all the keyboard listeners that a key was released.
*/
void InputManager::notifyKeyUp(SDLKey symbol, SDLMod mode, Uint16 unicode) const 
{
	set<KeyboardListener*>::iterator iter;
	for(iter = _keyboardListeners.begin(); iter != _keyboardListeners.end(); ++iter)
	{
		(*iter)->KeyUp(symbol, mode, unicode);
	}
}

/**
* Notifies all the mouse listeners that the right button was clicked (released).
*/
void InputManager::notifyMouseRightButtonClicked() const {
	std::set<MouseListener *>::iterator iter;
	for(iter = _mouseListeners.begin(); iter != _mouseListeners.end(); ++iter)
		(*iter)->MouseRightButtonClicked();
}

void InputManager::notifyMouseMoved( int x, int y ) const
{
	for(std::set<MouseListener *>::iterator iter = _mouseListeners.begin(); iter != _mouseListeners.end(); ++iter)
		(*iter)->MouseMoved( x, y);
}

/**
* Notifies all the mouse listeners that the left button was clicked (released).
*/
void InputManager::notifyMouseLeftButtonClicked() const {
	for(std::set<MouseListener *>::iterator iter = _mouseListeners.begin(); iter != _mouseListeners.end(); ++iter)
		(*iter)->MouseLeftButtonClicked();
}