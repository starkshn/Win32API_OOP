#include "pch.h"
#include "Monster.h"
#include "MonsterMissile.h"
#include "TimeManager.h"
#include "ResourceManager.h"

Monster::Monster()
	:
	_speed(100.f),
	_loopDistance(),
	_centerAnchor(),
	p_missile(nullptr),
	_direction(1)
{
	p_texture = ResourceManager::GetInstance()->LoadTexture(L"MonsterTexture", L"Textures\\monsterPlane.bmp");
}

Monster::~Monster()
{

}

void Monster::update()
{
	Vector2 pos = GetPos();

	pos._x += GetSpeed() * _direction * DeltaTime_F;

	float diffrenceDis = abs(_centerAnchor._x * pos._x) - _loopDistance;

	if (diffrenceDis > 0.f)
	{
		_direction *= -1;
		pos._x += diffrenceDis * _direction;
	}

	SetPos(pos);
}

void Monster::render(HDC dc)
{
	/*int width = static_cast<int>(_texture->GetWidht());
	int height = static_cast<int>(_texture->GetHeight());

	Vector2 pos = GetPos();

	TransparentBlt
	(
		dc,
		static_cast<int>(pos._x - static_cast<float>(width / 2)),
		static_cast<int>(pos._y - static_cast<float>(height / 2)),
		width, height,
		_texture->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255)
	);

	Object::ComponentRender(dc);*/
}

void Monster::CreateMonsterMissile()
{

}