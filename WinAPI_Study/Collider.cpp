#include "pch.h"
#include "Collider.h"
#include "Core.h"
#include "Object.h"
#include "SelectGDI.h"

UINT Collider::s_id = 0;

Collider::Collider()
	:
	_id(s_id++),
	p_owner(nullptr),
	_collisionCount(0),
	_offsetPos{0.f, 0.f},
	_finalPos{ 0.f, 0.f },
	_colliderScale{ 0.f, 0.f }
{

}

Collider::Collider(const Collider& origin)
	:
	_id(s_id++),
	p_owner(nullptr),
	_offsetPos(origin._offsetPos),
	_colliderScale(origin._colliderScale)
{

}

Collider::~Collider()
{

}

void Collider::finalUpdate()
{
	Vector2 objectPos = p_owner->GetPos();
	_finalPos = objectPos + _offsetPos;

	assert(0 <= _collisionCount);
}

void Collider::render(HDC dc)
{
	HPEN_TYPE pen = HPEN_TYPE::GREEN;

	if (_collisionCount)
	{
		pen = HPEN_TYPE::RED;
	}

	SelectGDI b(dc, HBRUSH_TYPE::HOLLOW);
	SelectGDI p(dc, HPEN_TYPE::GREEN);

	Rectangle
	(
		dc,
		static_cast<int>(_finalPos._x - _colliderScale._x / 2.f),
		static_cast<int>(_finalPos._y - _colliderScale._y / 2.f),
		static_cast<int>(_finalPos._x + _colliderScale._x / 2.f),
		static_cast<int>(_finalPos._y + _colliderScale._y / 2.f)
	);
	
}

void Collider::OnCollisionEnter(Collider* other)
{
	p_owner->OnCollisionEnter(other);
	++_collisionCount;
}

void Collider::OnCollisionStay(Collider* other)
{
	p_owner->OnCollisionStay(other);
}

void Collider::OnCollisionExit(Collider* other)
{
	p_owner->OnCollisionExit(other);
	--_collisionCount;
}