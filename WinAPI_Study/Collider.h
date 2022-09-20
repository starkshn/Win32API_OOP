#pragma once

class Object;

class Collider
{
private:
	static UINT s_id;
	UINT _id = 0;

	UINT _collisionCount;
	
	Object* p_owner;

	Vector2 _offsetPos;
	Vector2 _finalPos;
	Vector2 _colliderScale;

public:
	Collider();
	Collider(const Collider& origin);
	~Collider();

public:
	void finalUpdate();
	void render(HDC dc);

public:
	void OnCollisionEnter(Collider* other);
	void OnCollisionStay(Collider* other);
	void OnCollisionExit(Collider* other);

public:
	void SetOffsetPos(Vector2 pos) { _offsetPos = pos; }
	void SetColliderSacle(Vector2 scale) { _colliderScale = scale; }

public:
	Vector2 GetOffsetPos() { return _offsetPos; }
	Vector2 GetColliderScale() { return _colliderScale; }
	Vector2 GetFinalPos() { return _finalPos; }
	UINT GetID() { return _id; }
	Object* GetColliderOwner() { return p_owner; }

public:
	Collider& operator = (const Collider& other) = delete;

	friend class Object;
};

