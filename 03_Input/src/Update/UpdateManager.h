#ifndef UPDATEMANAGER_HEADER
#define UPDATEMANAGER_HEADER

#include <SDL/SDL.h>
#include "../Input/KeyboardListener.h"
#include "../Input/MouseListener.h"

class Updater;

class UpdateManager : public KeyboardListener, public MouseListener
{
public:
	static UpdateManager* GetInstance();
	static void Create();
	static void Destroy();
	
	virtual void MouseMoved(int, int);
	virtual void MouseLeftButtonClicked();
	virtual void MouseRightButtonClicked();

	bool Initialize();
	void Run();
	void Quit();

	void KeyDown(SDLKey symbol, SDLMod mode, Uint16 unicode);
	void KeyUp(SDLKey symbol, SDLMod mode, Uint16 unicode);

protected:
	static UpdateManager* _instance;

	enum GameState { RUNNING, PAUSED, QUITTING };

	Updater* _currentUpdater;
	GameState _currentGameState;
	GameState _previousGameState;

private:
	UpdateManager();
	~UpdateManager();
};

#endif // UPDATEMANAGER_HEADER