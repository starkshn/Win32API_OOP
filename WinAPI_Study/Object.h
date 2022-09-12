#pragma once
class Object
{
private :
	Vector2 _pos;
	Vector2 _scale;
	Vector2 _dir;
	float _theta;

public:
	Object();
	virtual ~Object();

public:
	virtual void update() abstract;
	virtual void render(HDC dc);

public :
	void SetPos(Vector2 pos) { _pos = pos;  }
	void SetScale(Vector2 scale) { _scale = scale;  }
	void SetTheta(float theta) { _theta = theta; }
	void SetDir(Vector2 dir) { _dir = dir; _dir.Normalize(); }

	Vector2 GetPos() { return _pos; }
	Vector2 GetScale() { return _scale; }
	float GetTheta() { return _theta; }
	Vector2 GetVectorDir() { return _dir; }


};

