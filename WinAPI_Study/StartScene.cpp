#include "pch.h"
#include "StartScene.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "SceneManager.h"
#include "Core.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "ColliderManager.h"

StartScene::StartScene()
{
	p_backGroundTexture = ResourceManager::GetInstance()->LoadTexture(L"BackGroundTexture", L"Textures\\BackGround3.bmp");
}
StartScene::~StartScene()
{
	// Scene 전부 삭제
}



void StartScene::Enter()
{
	// Player
	Object* player = new Player();
	player->SetPos(Vector2{640.f, 384.f});
	player->SetScale(Vector2{70.f, 70.f});

	AddObject(player, OBJECT_TYPE::PLAYER);

	// monster
	SetMonsterCount(8);
	float moveDis = 25.f;
	float monsterScale = 50.f;

	Vector2 resolution = Core::GetInstance()->GetResolution();
	float term = (resolution._x - (moveDis + monsterScale / 2.f) * 2) / static_cast<float>(GetMonsterCount() - 1);

	Monster* monster = nullptr;

	for (int i = 0; i < GetMonsterCount(); ++i)
	{
		monster = new Monster();
		monster->SetPos(Vector2( (moveDis + monsterScale / 2.f) + static_cast<float>(i) * term , 50.f));
		monster->SetScale(Vector2(40.f, 40.f));
		monster->SetLoopDistance(moveDis);
		monster->SetCenterAnchor(monster->GetPos());
		AddObject(monster, OBJECT_TYPE::MONSTER);
	}

	ColliderManager::GetInstance()->CheckObjectType(OBJECT_TYPE::PLAYER, OBJECT_TYPE::MONSTER);
}

void StartScene::update()
{
	Scene::update();
}

void StartScene::render(HDC dc)
{
	Vector2 resolution = Core::GetInstance()->GetResolution();

	// background rendering
	/*BitBlt
	(
		dc,
		0, 0,
		resolution._x,
		resolution._y,
		p_backGroundTexture->GetDC(),
		0, 0, SRCCOPY
	);*/

	Scene::render(dc);

}

void StartScene::Exit()
{

}