#pragma once

class Object;
class Texture;

class Scene
{
private:
	vector<Object*>		_objects[static_cast<UINT>(OBJECT_TYPE::END)];
	wstring				_sceneName;
	Texture* p_backGroundTexture;

public:
	Scene();
	virtual ~Scene();

public:
	void SetName(wstring sceneName) { _sceneName = sceneName; }
	const wstring& GetName() const { return _sceneName; }

	void update();
	virtual void render(HDC dc);

	virtual void Enter() abstract;
	virtual void Exit() abstract;
	
public:
	void AddObject(Object* go, OBJECT_TYPE type)
	{
		_objects[static_cast<UINT>(type)].push_back(go);
	}

	const vector<Object*>& GetSceneObjects(const OBJECT_TYPE& type)
	{
		return _objects[static_cast<UINT>(type)];
	}
};

