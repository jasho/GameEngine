#ifndef USEPLAYER_HEADER
#define USERPLAYER_HEADER

#include "Player.h"
#include "../Input/KeyboardListener.h"
#include "../Input/MouseListener.h"

#include <SDL/SDL.h>
using namespace std;


class UserPlayer : public Player, public KeyboardListener, public MouseListener
{
public:
	UserPlayer();
	~UserPlayer();

	void KeyDown(SDLKey symbol, SDLMod mode, Uint16 unicode);
	void KeyUp(SDLKey symbol, SDLMod mode, Uint16 unicode );

};
#endif