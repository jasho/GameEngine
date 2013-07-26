#ifndef SCENEMANAGER_HEADER
#define SCENEMANAGER_HEADER
#include "../Serialize/Serializable.h"
#include "../Misc/Vectors/Vector3.h"

class SceneNode;
class Camera;

class SceneManager : public Serializable
{
public:
	static SceneManager* GetInstance();
	static void Create();
	static void Destroy();

	void CameraMove(const Vector3& translation);
	void CameraRotate(const Vector3& rotation);

	void RenderScene() const;
	virtual void SaveToOutputStream(std::ostream&) const;
	virtual bool LoadFromInputStream(std::istream&);

protected:
	static SceneManager* _instance;
	
	SceneNode* _sceneNodeRoot;
	Camera* _currentCamera;

private:
	SceneManager();
	~SceneManager();
};

#endif // SCENEMANAGER_HEADER