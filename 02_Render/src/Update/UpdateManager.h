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

protected:
	static UpdateManager* _instance;

	enum GameState { RUNNING, PAUSED };

	Updater* _currentUpdater;
	GameState _currentGameState;
	GameState _previousGameState;

private:
	UpdateManager();
	~UpdateManager();
};

#endif // UPDATEMANAGER_HEADER