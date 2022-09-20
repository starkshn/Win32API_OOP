#include "pch.h"
#include "Player.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "Missile.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Texture.h"
#include "PathManager.h"
#include "ResourceManager.h"

Player::Player() : p_texture(nullptr)
{
	p_texture = ResourceManager::GetInstance()->LoadTexture(L"PlayerTexture", L"Textures\\Plane2.bmp");
}

Player::~Player()
{

}

void Player::update()
{
	Vector2 pos = GetPos();

	if (KEY_HOLD(KEY::W))
	{
		pos._y -= 200.f * DeltaTime_F;
	}
	if (KEY_HOLD(KEY::S))
	{
		pos._y += 200.f * DeltaTime_F;
	}
	if (KEY_HOLD(KEY::A))
	{
		pos._x -= 200.f * DeltaTime_F;
	}
	if (KEY_HOLD(KEY::D))
	{
		pos._x += 200.f * DeltaTime_F;
	}

	// Missile
	if (KEY_TAP(KEY::V))
	{
		CreateMissile();
	}
	if (KEY_TAP(KEY::B))
	{
		CreateThreeMissile();
	}

	SetPos(pos);
}

void Player::render(HDC dc)
{
	int width = static_cast<int>(p_texture->GetWidth());
	int height = static_cast<int>(p_texture->GetHeight());

	Vector2 pos = GetPos();

	TransparentBlt
	(
		dc,
		static_cast<int>( pos._x - static_cast<float>(width / 2) ),
		static_cast<int>( pos._y - static_cast<float>(height / 2) ),
		width, height,
		p_texture->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255)
	);
}

void Player::CreateMissile()
{
	// missile ����
	Missile* missile = new Missile();

	// �̻��� ��ġ ����
	Vector2 playerPos = GetPos();
	playerPos._y -= GetScale()._y / 2.f;
	missile->SetPos(playerPos);

	playerPos._y -= (GetScale()._y / 2.f) + (missile->GetScale()._y / 2.f);
	missile->SetPos(playerPos);

	// �̻��� ũ�� ����
	missile->SetScale(Vector2(25.f, 25.f));

	// �̻��� ����
	missile->SetDir(Vector2(0.f, 1.f));

	SetObjectName(L"missile");

	Scene* curScene = SceneManager::GetInstance()->GetCurrentScene();
	curScene->AddObject(missile, OBJECT_TYPE::MISSILE);
}

void Player::CreateThreeMissile()
{
	return;
}