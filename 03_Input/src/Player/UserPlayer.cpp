#include "UserPlayer.h"
#include "../Scene/SceneManager.h"

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
		SceneManager::GetInstance()->CameraMove(Vector3(0, 0, -1));
		break;
	case SDLK_DOWN:
		SceneManager::GetInstance()->CameraMove(Vector3(0, 0, 1));
		break;
	case SDLK_LEFT:
		SceneManager::GetInstance()->CameraMove(Vector3(1, 0, 0));
		break;
	case SDLK_RIGHT:
		SceneManager::GetInstance()->CameraMove(Vector3(-1, 0, 0));
		break;
		default:
		break;
	}
}

void UserPlayer::MouseMoved(int x, int y)
{
	SceneManager::GetInstance()->CameraRotate( Vector3(x/10.0f, y/10.0f, 0) );
}

void UserPlayer::MouseLeftButtonClicked()
{

}

void UserPlayer::MouseRightButtonClicked()
{
}


void UserPlayer::KeyUp( SDLKey symbol, SDLMod mode, Uint16 unicode )
{

}