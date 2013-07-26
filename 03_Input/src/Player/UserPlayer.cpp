#include "UserPlayer.h"


UserPlayer::UserPlayer()
{
}

UserPlayer::~UserPlayer()
{
}

void UserPlayer::KeyDown( SDLKey symbol, SDLMod mode, Uint16 unicode )
{
	switch(symbol)
	{
	case SDLK_UP:
		//change position? translate?
	case SDLK_DOWN:
	case SDLK_LEFT:
	case SDLK_RIGHT:
		default:
		break;
	}
}

void UserPlayer::KeyUp( SDLKey symbol, SDLMod mode, Uint16 unicode )
{

}