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
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Player::Player()
{
	SetObjectName(L"Player");

	CreateCollider();
	GetCollider()->SetOffsetPos(Vector2{ 0.f, 0.f });
	GetCollider()->SetColliderSacle(Vector2{ 40.f, 40.f });

	// 세로 : 56px, 가로 : 56px
	// WALK_LEFT는 인덱스가 9까지 존재
	Texture* texture = ResourceManager::GetInstance()->LoadTexture(L"PlayerAnimationTexture", L"Textures\\MetalSlug_Player.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"WALK_RIGHT", texture, Vector2(0, 56), Vector2(56, 56), Vector2(56, 0), 0.1f, 9);
	GetAnimator()->PlayAnimation(L"WALK_RIGHT", true);

	Animation* anim = GetAnimator()->FindAnimation(L"WALK_RIGHT");

	for (int i = 0; i < anim->GetMaxFrame(); ++i)
	{
		anim->GetAnimFrame(i)._offset = Vector2(0.f, 0.f);
	}
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
	if (KEY_TAP(KEY::SPACE))
	{
		CreateMissile();

		Texture* texture = ResourceManager::GetInstance()->LoadTexture(L"PlayerAnimationTexture", L"Textures\\MetalSlug_Player.bmp");

		GetAnimator()->CreateAnimation(L"Attack", texture, Vector2(0, 112), Vector2(56, 56), Vector2(56, 0), 0.1f, 4);
		GetAnimator()->PlayAnimation(L"Attack", true);

		Animation* anim = GetAnimator()->FindAnimation(L"Attack");

		for (int i = 0; i < anim->GetMaxFrame(); ++i)
		{
			anim->GetAnimFrame(i)._offset = Vector2(0.f, 0.f);
		}
	}
	if (KEY_TAP(KEY::B))
	{
		CreateThreeMissile();
	}

	SetPos(pos);

	GetAnimator()->update();
}

void Player::render(HDC dc)
{
	/*int width = static_cast<int>(p_texture->GetWidth());
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
		RGB(0, 255, 0)
	);*/

	Object::ComponentRender(dc);
}

void Player::CreateMissile()
{
	Vector2 playerPos = GetPos();

	// missile 생성
	Missile* missile = new Missile();

	// 미사일 위치 설정
	playerPos._y -= (GetScale()._y / 2.f) + (missile->GetScale()._y / 2.f);
	missile->SetPos(playerPos);

	// 미사일 크기 설정
	missile->SetScale(Vector2(25.f, 25.f));

	// 미사일 방향
	missile->SetDir(Vector2(0.f, 1.f));

	SetObjectName(L"missile");

	Scene* curScene = SceneManager::GetInstance()->GetCurrentScene();
	curScene->AddObject(missile, OBJECT_TYPE::MISSILE);
}

void Player::CreateThreeMissile()
{
	return;
}