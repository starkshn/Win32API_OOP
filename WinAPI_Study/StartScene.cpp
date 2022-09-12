#include "pch.h"
#include "StartScene.h"
#include "Object.h"

StartScene::StartScene()
{

}
StartScene::~StartScene()
{

}

void StartScene::Enter()
{
	Object* go = new Object();

	go->SetPos(Vector2{640.f, 383.f});
	go->SetScale(Vector2{100.f, 100.f});

	AddObject(go, OBJECT_TYPE::DEFAULT);
}
void StartScene::Exit()
{

}