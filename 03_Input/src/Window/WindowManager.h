#ifndef WINDOWMANAGER_HEADER
#define WINDOWMANAGER_HEADER

#include <SDL/SDL.h>

class WindowManager
{
public:
	static WindowManager * GetInstance();
	static void Create();
	static void Destroy();

	void OnWindowEvent(SDL_Event* event);

protected:
	static WindowManager * _instance;

private:
	WindowManager();
};
#endif