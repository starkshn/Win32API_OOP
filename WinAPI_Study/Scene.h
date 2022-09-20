#pragma once

class Object;
class Texture;

class Scene
{
private:
	vector<Object*>		_objects[static_cast<UINT>(OBJECT_TYPE::END)];
	wstring				_sceneName;

public:
	Scene();
	virtual ~Scene();

public:
	virtual void update();
	virtual void render(HDC dc);
	virtual void Enter() abstract;
	virtual void Exit() abstract;
	
public:
	void AddObject(Object* go, OBJECT_TYPE type)
	{
		_objects[static_cast<UINT>(type)].push_back(go);
	}
	void DeleteSceneObjects(OBJECT_TYPE objectType);
	void DeleteSceneAllObjects();

public:
	void SetName(wstring sceneName) { _sceneName = sceneName; }

public:
	const wstring& GetName() const { return _sceneName; }
	const vector<Object*>& GetSceneObjects(const OBJECT_TYPE& type)
	{
		return _objects[static_cast<UINT>(type)];
	}


};

