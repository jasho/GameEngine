#ifndef SCENEMANAGER_HEADER
#define SCENEMANAGER_HEADER

class SceneNode;

class SceneManager
{
public:
	static SceneManager* GetInstance();
	static void Create();
	static void Destroy();

	void RenderScene() const;

protected:
	static SceneManager* _instance;
	SceneNode* _sceneNodeRoot;

private:
	SceneManager();
	~SceneManager();
};

#endif // SCENEMANAGER_HEADER