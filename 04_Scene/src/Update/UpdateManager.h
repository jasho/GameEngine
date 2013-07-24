#ifndef UPDATEMANAGER_HEADER
#define UPDATEMANAGER_HEADER

class Updater;

class UpdateManager
{
public:
	static UpdateManager* GetInstance();
	static void Create();
	static void Destroy();
	
	bool Initialize();
	void Run();

	long long GetTicksElapsed();

protected:
	static UpdateManager* _instance;

	enum GameState { RUNNING, PAUSED, QUITTIING };

	Updater* _currentUpdater;	
	GameState _currentGameState;
	GameState _previousGameState;	

	long long  _startTicks;
	long long _pausedTicks;

private:
	UpdateManager();
	~UpdateManager();
};

#endif // UPDATEMANAGER_HEADER