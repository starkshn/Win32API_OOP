#include "pch.h"
#include "SceneManager.h"
#include "StartScene.h"

SceneManager::SceneManager() 
	: 
	p_scenes(), 
	p_currentScene(nullptr)
{

}
SceneManager::~SceneManager()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(SCENE_TYPE::END); ++i)
	{
		if (p_scenes[i] != nullptr)
		{
			delete p_scenes[i];
		}
	}
}

void SceneManager::init()
{
	p_scenes[static_cast<UINT>(SCENE_TYPE::START)] = new StartScene;
	p_scenes[static_cast<UINT>(SCENE_TYPE::START)]->SetName(L"StartScene");



	p_currentScene = p_scenes[static_cast<UINT>(SCENE_TYPE::START)];
	p_currentScene->Enter();
}

void SceneManager::update()
{
	p_currentScene->update();
	p_currentScene->finalUpdate();
}

void SceneManager::render(HDC sceneDC)
{
	p_currentScene->render(sceneDC);
}
