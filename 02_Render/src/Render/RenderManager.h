#ifndef RENDERMANAGER_HEADER
#define RENDERMANAGER_HEADER

class Renderer;

class RenderManager
{
public:
	static RenderManager* GetInstance(void);
	static void Create(void);
	static void Destroy(void);
	
	bool Initialize(void);

	int GetWindowWidth(void) const;
	void SetWindowWidth(int windowWidth);
	int GetWindowHeight(void) const;
	void SetWindowHeight(int windowHeight);
	bool IsFullscreen(void) const;
	void ToggleFullscreen(void);

	void RenderScene(void);

protected:
	enum RendererType { RENDERER_TYPE_OPENGL, RENDERER_TYPE_DIRECTX };
	static RenderManager* _instance;

	RendererType _prefferedRenderer;
	Renderer* _renderer;

	int _windowWidth;
	int _windowHeight;
	bool _fullscreen;

	float tmpYRotation;

private:
	RenderManager(void);
	~RenderManager(void);
};

#endif // RENDERMANAGER_HEADER