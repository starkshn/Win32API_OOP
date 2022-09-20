#pragma once

class Collider;

union COLLIDER_ID
{
	struct
	{
		UINT _leftID;
		UINT _rightID;
	};

	ULONGLONG _id;
};

class ColliderManager
{
	SINGLE(ColliderManager);

private:
	map<ULONGLONG, bool> _mapCollisionInfo;
	UINT _arrCheckCollision[static_cast<UINT>(OBJECT_TYPE::END)];

private:
	void CollisionObjectUpdate(OBJECT_TYPE left, OBJECT_TYPE right);
	bool IsCollision(Collider* leftCollider, Collider* rightCollider);

public:
	void update();
	void CheckObjectType();
	void ResetObjects()
	{
		memset(_arrCheckCollision, 0, sizeof(UINT) * static_cast<UINT>(OBJECT_TYPE::END));
	}



};

