#ifndef INPUTMANAGER_HEADER
#define INPUTMANAGER_HEADER

#include <set>
#include <SDL/SDL.h>

class KeyboardListener;
class MouseListener;
class Vector2;

class InputManager {

public:	
	// Maintain the Input Manager
	inline static InputManager* GetInstance() { return InputManager::_instance; }
	static void Create();
	static void Destroy();

	void OnInputEvent(SDL_Event* event);

	// Keyboard Handlers
	bool IsKeyDown(SDLKey key) const;
	void ResetKey(char);

	// Mouse Handlers
	inline const Vector2 *GetMousePosition() const { return _mousePosition; }
	inline bool MouseLeftButtonDown() const { return _isMouseLeftDown; }
	inline bool MouseRightButtonDown() const { return _isMouseRightDown; }
	
	// Polling function
	//bool Update(UINT, WPARAM, LPARAM);

	// Manage Listeners
	void AddKeyboardListener(KeyboardListener*);
	bool RemoveKeyboardListener(const KeyboardListener*);

	void AddMouseListener(MouseListener*);
	bool RemoveMouseListener(const MouseListener*);

protected:
	InputManager();

private:
	static InputManager* _instance; ///< Unique InputManager instance.

	bool _keys[SDLK_LAST];	///< Storing the state of the keyboard keys.

	Vector2 *_mousePosition;	///< Storing the position of the mouse.
	bool _isMouseLeftDown;		///< Stores whether the left mouse button is pressed or not.
	bool _isMouseRightDown;		///< Stores whether the right mouse button is pressed or not.

	std::set<KeyboardListener *> _keyboardListeners;	///< Container for all the keyboard listeners.
	std::set<MouseListener *> _mouseListeners;			///< Container for all the mouse listeners.

	void notifyKeyDown(SDLKey symbol, SDLMod mode, Uint16 unicode) const;
	void notifyKeyUp(SDLKey symbol, SDLMod mode, Uint16 unicode) const;

	void notifyMouseMoved(int,int) const;
	void notifyMouseLeftButtonClicked() const;
	void notifyMouseRightButtonClicked() const;
};

#endif // INPUTMANAGER_HEADER