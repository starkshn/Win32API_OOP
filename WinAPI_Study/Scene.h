#pragma once

class Object;

class Scene
{

private:
	vector<Object*>	_objects[static_cast<UINT>(OBJECT_TYPE::END)];
	wstring				_sceneName;

public:
	Scene();
	virtual ~Scene();

public:
	void SetName(wstring sceneName) { _sceneName = sceneName; }
	const wstring& GetName() const { return _sceneName; }

	void update();
	void render(HDC dc);

	virtual void Enter() abstract;
	virtual void Exit() abstract;
	

protected:
	void AddObject(Object* go, OBJECT_TYPE type)
	{
		_objects[static_cast<UINT>(type)].push_back(go);
	}
	void EraseObject(Object* go, OBJECT_TYPE type)
	{
		auto typeVector = _objects[static_cast<UINT>(type)];
		for (int i = 0; i < typeVector.size(); ++i)
		{
			if (typeVector[i] == go)
				delete go;
		}
	}
};

