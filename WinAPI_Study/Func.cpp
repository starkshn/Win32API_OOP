#include "pch.h"
#include "Func.h"
#include "EventManager.h"

void CreateObjectEvent(Object* objectPtr, OBJECT_TYPE type)
{
	EVENT evt = {};
	evt._eventType = EVENT_TYPE::CREATE_OBJECT;
	evt._objectPtr = (DWORD_PTR)objectPtr;
	evt._objectType = (DWORD_PTR)type;

	EventManager::GetInstance()->AddEvent(evt);
}

void DeleteObjectEvent(Object* objectPtr)
{
	EVENT evt = {};
	evt._eventType = EVENT_TYPE::DELETE_OBJECT;
	evt._objectPtr = (DWORD_PTR)objectPtr;

	EventManager::GetInstance()->AddEvent(evt);
}

void ChangeScene(SCENE_TYPE type)
{
	// �̹������ӿ����� �̺�Ʈ ����� �ϰ� ���� �����ӿ� ���� ������ �� ���̴�.
	EVENT evt = {};
	evt._eventType = EVENT_TYPE::SCENE_CHANGE;
	evt._objectPtr = (DWORD_PTR)type;

	EventManager::GetInstance()->AddEvent(evt);
}