#pragma once
#include "Object.h"

class MonsterMissile;
class Texture;

class Monster : public Object
{
private:
	CLONE(Monster);

	float			_speed;
	float			_loopDistance;
	int				_direction;
	bool			_missileFire;
	UINT			_monsterId = 0;

	int				_hp = 5;

	Vector2			_centerAnchor;
	Texture*		p_texture = nullptr;
	MonsterMissile* p_missile = nullptr;
	
public:
	Monster();
	virtual ~Monster() override;

public:
	virtual void update() override;
	virtual void render(HDC dc) override;

public:
	virtual void OnCollisionEnter(Collider* other) override;
	virtual void OnCollisionStay(Collider* other) override;
	virtual void OnCollisionExit(Collider* other) override;

public:
	void CreateMonsterMissile();

public:
	void SetSpeed(float speed) { _speed = speed; }
	void SetCenterAnchor(Vector2 anchor) { _centerAnchor = anchor; }
	void SetLoopDistance(float loopDs) { _loopDistance = loopDs; }
	void SetMonsterId(UINT id) { _monsterId = id; }
	void SetMissileFire(bool fire) { _missileFire = fire; }

public:
	float	GetSpeed() { return _speed; }
	Vector2 GetCenterAnchor() { return _centerAnchor; }
	float	GetLoopDistance() { return _loopDistance; }
	int		GetMonsterId() { return _monsterId; }
	bool	GetMissileFire() { return _missileFire; }
};

