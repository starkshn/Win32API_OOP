#include "pch.h"
#include "SceneManager.h"
#include "StartScene.h"

SceneManager::SceneManager() : _scenes(), _currentScene(nullptr)
{

}
SceneManager::~SceneManager()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(SCENE_TYPE::END); ++i)
	{
		if (_scenes[i] != nullptr)
		{
			delete _scenes[i];
		}
	}
}

void SceneManager::init()
{
	_scenes[static_cast<UINT>(SCENE_TYPE::START)] = new StartScene();
	_scenes[static_cast<UINT>(SCENE_TYPE::START)]->SetName(L"StartScene");

	_currentScene = _scenes[static_cast<UINT>(SCENE_TYPE::START)];
	_currentScene->Enter();
}
void SceneManager::update()
{
	_currentScene->update();
}
void SceneManager::render(HDC sceneDC)
{
	_currentScene->render(sceneDC);
}
