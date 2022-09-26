#include "pch.h"
#include "Monster.h"
#include "MonsterMissile.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Collider.h"

Monster::Monster()
	:
	p_texture(nullptr),
	_speed(100.f),
	_loopDistance(50.f),
	_direction(1),
	_missileFire(false),
	_centerAnchor{0.f, 0.f}
{
	SetObjectName(L"Monster_1");

	CreateCollider();
	GetCollider()->SetOffsetPos(Vector2{ 0.f, 0.f });
	GetCollider()->SetColliderSacle(Vector2{ 30.f, 30.f });

	p_texture = ResourceManager::GetInstance()->LoadTexture(L"MonsterTexture", L"Textures\\monsterPlane.bmp");
}

Monster::~Monster()
{

}

void Monster::update()
{
	Vector2 pos = GetPos();

	pos._x += _speed * _direction * DeltaTime_F;

	float diffrenceDis = abs(_centerAnchor._x - pos._x) - _loopDistance;

	if (0.f < diffrenceDis)
	{
		_direction *= -1;
		pos._x += diffrenceDis * _direction;
	}

	SetPos(pos);
}

void Monster::render(HDC dc)
{
	int width = static_cast<int>(p_texture->GetWidth());
	int height = static_cast<int>(p_texture->GetHeight());

	Vector2 pos = GetPos();

	TransparentBlt
	(
		dc,
		static_cast<int>(pos._x - static_cast<float>(width / 2)),
		static_cast<int>(pos._y - static_cast<float>(height / 2)),
		width, height,
		p_texture->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255)
	);

	Object::ComponentRender(dc);
}

void Monster::OnCollisionEnter(Collider* other)
{
	Object* otherPtr = other->GetColliderOwner();

	if (otherPtr->GetObjectName() == L"Player")
	{
		_hp -= 1;

		if (_hp <= 0)
			DeleteObjectEvent(this);
	}
}

void Monster::OnCollisionStay(Collider* other)
{

}

void Monster::OnCollisionExit(Collider* other)
{

}

void Monster::CreateMonsterMissile()
{

}