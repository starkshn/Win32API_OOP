#include "pch.h"
#include "Scene.h"
#include "Object.h"

Scene::Scene()
{
	
}
Scene::~Scene()
{
	
}

void Scene::update()
{
	for (UINT i = 0; i < static_cast<UINT>(OBJECT_TYPE::END); ++i)
	{
		for (size_t j = 0; j < _objects[i].size(); ++j)
		{
			_objects[i][j]->update();
		}
	}
}
void Scene::render(HDC dc)
{
	for (UINT i = 0; i < static_cast<UINT>(OBJECT_TYPE::END); ++i)
	{
		for (size_t j = 0; j < _objects[i].size(); ++j)
		{
			_objects[i][j]->render(dc);
		}
	}
}
