#pragma once



class Object
{
private :
	wstring		_objectName;

	// 크기, 위치
	Vector2		_pos;
	Vector2		_scale;

	// 벡터 방향
	Vector2		_dir;
	float		_theta;

	// component
	
	// alive
	bool _alive;

public:
	Object();
	virtual ~Object();

public:
	virtual void update() abstract;
	virtual void render(HDC dc);

	virtual Object* Clone() abstract;

public :
	void SetPos(Vector2 pos) { _pos = pos;  }
	void SetScale(Vector2 scale) { _scale = scale;  }
	void SetTheta(float theta) { _theta = theta; }
	void SetDir(Vector2 dir) { _dir = dir; _dir.Normalize(); }
	void SetObjectName(const wstring name) { _objectName = name; }

	Vector2 GetPos() { return _pos; }
	Vector2 GetScale() { return _scale; }
	float	GetTheta() { return _theta; }
	Vector2 GetDir() { return _dir; }


};

