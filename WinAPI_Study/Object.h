#pragma once

class Collider;

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
	Collider* p_collider;
	
	// alive
	bool _alive;

public:
	Object();
	Object(const Object& origin);
	virtual ~Object();

public:
	virtual void	update() abstract;
	virtual void	finalUpdate() final;
	virtual void	render(HDC dc);

	virtual Object* Clone() abstract;

	virtual void OnCollisionEnter(Collider* other) {}
	virtual void OnCollisionStay(Collider* other) {}
	virtual void OnCollisionExit(Collider* other) {}

public:
	void ComponentRender(HDC dc);

public:
	void CreateCollider();

public:
	void SetDead() { _alive = false; };
	bool IsDead() { return !_alive; }

public :
	void SetPos(Vector2 pos) { _pos = pos;  }
	void SetScale(Vector2 scale) { _scale = scale;  }
	void SetTheta(float theta) { _theta = theta; }
	void SetDir(Vector2 dir) { _dir = dir; _dir.Normalize(); }
	void SetObjectName(const wstring name) { _objectName = name; }

public:
	Vector2		GetPos() { return _pos; }
	Vector2		GetScale() { return _scale; }
	float		GetTheta() { return _theta; }
	Vector2		GetDir() { return _dir; }
	Collider*	GetCollider() { return p_collider; }

};

