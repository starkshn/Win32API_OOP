#include "pch.h"
#include "Object.h"
#include "KeyManager.h"
#include "TimeManager.h"

Object::Object() : _pos(), _scale()
{
}
Object::~Object()
{
	
}

void Object::update()
{
	if (KeyManager::GetInstance()->GetKeyState(KEY::W) == KEY_STATE::HOLD)
	{
		_pos._y -= 200.f * DeltaTime_F;
	}
	if (KeyManager::GetInstance()->GetKeyState(KEY::A) == KEY_STATE::HOLD)
	{
		_pos._x -= 200.f * DeltaTime_F;
	}
	if (KeyManager::GetInstance()->GetKeyState(KEY::S) == KEY_STATE::HOLD)
	{
		_pos._y += 200.f * DeltaTime_F;
	}
	if (KeyManager::GetInstance()->GetKeyState(KEY::D) == KEY_STATE::HOLD)
	{
		_pos._x += 200.f * DeltaTime_F;
	}

}
void Object::render(HDC dc)
{
	Rectangle
	(	dc,
		static_cast<int>(_pos._x - _scale._x / 2.f),
		static_cast<int>(_pos._y - _scale._y / 2.f),
		static_cast<int>(_pos._x + _scale._x / 2.f),
		static_cast<int>(_pos._y + _scale._x / 2.f)
	);
}
