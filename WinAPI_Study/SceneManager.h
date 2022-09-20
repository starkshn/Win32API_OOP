#pragma once

class Scene;

class SceneManager
{
	SINGLE(SceneManager)

private:
	Scene* p_scenes[static_cast<UINT>(SCENE_TYPE::END)];
	Scene* p_currentScene;

public :
	void init();
	void update();
	void render(HDC sceneDC);

public:
	Scene* GetCurrentScene() { return p_currentScene; }
};

