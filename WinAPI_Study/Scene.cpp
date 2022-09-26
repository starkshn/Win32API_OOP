#include "pch.h"
#include "Scene.h"
#include "Object.h"

Scene::Scene()
{
	
}
Scene::~Scene()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(OBJECT_TYPE::END); ++i)
	{
		for (size_t j = 0; j < _objects[i].size(); ++j)
		{
			if (nullptr != _objects[i][j])
				delete _objects[i][j];
		}
	}
}

void Scene::update()
{
	for (UINT i = 0; i < static_cast<UINT>(OBJECT_TYPE::END); ++i)
	{
		for (size_t j = 0; j < _objects[i].size(); ++j)
		{
			if (!_objects[i][j]->IsDead())
			{
				_objects[i][j]->update();
			}
		}
	}
}

void Scene::finalUpdate()
{
	for (UINT i = 0; i < static_cast<UINT>(OBJECT_TYPE::END); ++i)
	{
		for (size_t j = 0; j < _objects[i].size(); ++j)
		{
			_objects[i][j]->finalUpdate();
		}
	}
}

void Scene::render(HDC dc)
{
	for (UINT i = 0; i < static_cast<UINT>(OBJECT_TYPE::END); ++i)
	{
		vector<Object*>::iterator iter = _objects[i].begin();

		for (iter = _objects[i].begin(); iter != _objects[i].end(); )
		{
			if (!(*iter)->IsDead())
			{
				(*iter)->render(dc);
				++iter;
			}
			else
			{
				iter = _objects[i].erase(iter);
			}
		}
	}
}
