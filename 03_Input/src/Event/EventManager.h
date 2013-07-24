#ifndef EVENTMANAGER_HEADER
#define EVENTMANAGER_HEADER

#include <SDL/SDL.h>

class EventManager
{
public:
	static EventManager* GetInstance();

	static void Create();
	static void Destroy();

	void OnEvent(SDL_Event* event);

protected:
	static EventManager* _instance;

private:
	EventManager();
	~EventManager();
};

#endif // EVENTMANAGER_HEADER