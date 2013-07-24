#ifndef KEYBOARDLISTENER_HEADER
#define KEYBOARDLISTENER_HEADER

#include <SDL/SDL.h>

class KeyboardListener {

public:	
	virtual void KeyDown(SDLKey symbol, SDLMod mode, Uint16 unicode) = 0;
	virtual void KeyUp(SDLKey symbol, SDLMod mode, Uint16 unicode) = 0;

protected:
	KeyboardListener();
	virtual ~KeyboardListener();
};

#endif // KEYBOARDLISTENER_HEADER