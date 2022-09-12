#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"


Missile::Missile()
{}

Missile::~Missile()
{}

void Missile::update()
{
	Vector2 pos = GetPos();
	Vector2 scale = GetScale();

	Vector2 dir = GetDir();
	
	pos._y += 200.f * DeltaTime_F * dir._y;
	pos._x += 200.f * DeltaTime_F * dir._x;

	SetPos(pos);
}

void Missile::render(HDC dc)
{
	Vector2 pos = GetPos();
	Vector2 scale = GetScale();

	Ellipse
	(
		dc,
		static_cast<int>(pos._x - scale._x / 2.f),
		static_cast<int>(pos._x - scale._x / 2.f),
		static_cast<int>(pos._x - scale._x / 2.f),
		static_cast<int>(pos._x - scale._x / 2.f)
	);
}