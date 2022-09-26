#pragma once

class Collider;
class Animator;

class Object
{
private :
	wstring		_objectName;

	// ũ��, ��ġ
	Vector2		_pos;
	Vector2		_scale;

	// ���� ����
	Vector2		_dir;
	float		_theta;

	// component
	Collider* p_collider;
	Animator* p_animator;
	
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

	virtual void OnCollisionEnter(Collider* other) 
	{

	}
	virtual void OnCollisionStay(Collider* other) 
	{

	}
	virtual void OnCollisionExit(Collider* other) 
	{

	}

public:
	void ComponentRender(HDC dc);

public:
	void CreateCollider();
	void CreateAnimator();

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
	Vector2			GetPos() { return _pos; }
	Vector2			GetScale() { return _scale; }
	float			GetTheta() { return _theta; }
	Vector2			GetDir() { return _dir; }
	const wstring& GetObjectName() { return _objectName; };
	Collider*		GetCollider() { return p_collider; }
	Animator*		GetAnimator() { return p_animator; }

	friend class EventManager;
};

