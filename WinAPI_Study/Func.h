#pragma once

class Object;

void CreateObjectEvent(Object* obj, OBJECT_TYPE objectType);

void DeleteObjectEvent(Object* objectPtr);

void ChangeScene(SCENE_TYPE sceneType);

template <typename T>
void SafeDeleteVector(vector<T>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		if (nullptr != vec[i])
			delete vec[i];
	}
	vec.clear();
}

template <typename T1, typename T2>
void SafeDeleteMap(map<T1, T2> _map)
{
	typename map<T1, T2>::iterator iter = _map.begin();

	for (; iter != _map.end(); ++iter)
	{
		if (nullptr != iter->second)
			delete iter->second;
	}
	_map.clear();
}
