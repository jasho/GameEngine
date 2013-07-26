#ifndef SCENEMANAGER_HEADER
#define SCENEMANAGER_HEADER
#include "../Serialize/Serializable.h"
class SceneNode;

class SceneManager : public Serializable
{
public:
	static SceneManager* GetInstance();
	static void Create();
	static void Destroy();

	void RenderScene() const;
	virtual void SaveToOutputStream(std::ostream&) const;
	virtual bool LoadFromInputStream(std::istream&);

protected:
	static SceneManager* _instance;
	SceneNode* _sceneNodeRoot;

private:
	SceneManager();
	~SceneManager();
};

#endif // SCENEMANAGER_HEADER