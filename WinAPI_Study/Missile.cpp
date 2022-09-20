#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Texture.h"


Missile::Missile()
{
	p_texture = ResourceManager::GetInstance()->LoadTexture(L"BackGroundTexture", L"Textures\\missile.bmp");
}

Missile::~Missile()
{

}

void Missile::update()
{
	Vector2 pos = GetPos();
	Vector2 dir = GetDir();
	
	pos._x += 600.f * dir._x * DeltaTime_F;
	pos._y -= 600.f * dir._y * DeltaTime_F;

	SetPos(pos);
}

void Missile::render(HDC dc)
{
	int width = p_texture->GetWidth();
	int height = p_texture->GetHeight();

	Vector2 pos = GetPos();

	TransparentBlt
	(
		dc,
		static_cast<int>(pos._x - static_cast<float>(width / 2.f)),
		static_cast<int>(pos._y - static_cast<float>(height / 2.f)),
		0, 0,
		p_texture->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255)
	);

}