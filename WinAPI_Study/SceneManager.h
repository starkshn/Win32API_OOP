#pragma once

class Scene;

class SceneManager
{
	SINGLE(SceneManager);

private:
	Scene* _scenes[static_cast<UINT>(SCENE_TYPE::END)];
	Scene* _currentScene;

public :
	void init();
	void update();
	void render(HDC sceneDC);

public:
	Scene* GetCurrentScene() { return _currentScene; }
};

