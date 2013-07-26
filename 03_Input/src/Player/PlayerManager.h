#ifndef PLAYERMANAGER_HEADER
#define PLAYERMANAGER_HEADER

#include <vector>
#include <SDL/SDL.h>
using namespace std;

class Player;

class PlayerManager
{
public:
	static PlayerManager * GetInstance();
	static void Create();
	static void Destroy();
	//void OnPlayerEvent(SDL_Event* event);

protected:
private:
	static PlayerManager * _instance;

	vector<Player *> _players;

	PlayerManager();
	~PlayerManager();
};
#endif