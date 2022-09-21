#include "pch.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Object.h"

EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

void EventManager::update()
{
	// 이전 프레임에서 등록해둔 Dead Object 삭제한다.
	for (size_t i = 0; i < _vecDead.size(); ++i)
	{
		delete _vecDead[i];
	}
	_vecDead.clear();

	// 이벤트 처리
	for (size_t i = 0; i < _vecEvents.size(); ++i)
	{
		ExcuteEvent(_vecEvents[i]);
	}
	_vecEvents.clear();
}

void EventManager::ExcuteEvent(const EVENT& e)
{
	switch (e._eventType)
	{
		case EVENT_TYPE::CREATE_OBJECT:
		{
			Object* newObjPtr = (Object*)e._objectPtr;
			OBJECT_TYPE newObjectType = (OBJECT_TYPE)e._objectType;

			SceneManager::GetInstance()->GetCurrentScene()->AddObject(newObjPtr, newObjectType);
		}
			break;
		case EVENT_TYPE::DELETE_OBJECT:
		{
			Object* deadObjPtr = (Object*)e._objectPtr;

			if (!deadObjPtr->IsDead())
			{
				deadObjPtr->SetDead();
				_vecDead.push_back(deadObjPtr);
			}
		}
			break;
		case EVENT_TYPE::SCENE_CHANGE:
		{
			/*SceneManager::GetInstance()->ChangeRealScene((SCENE_TYPE)e._objectPtr)*/
		}
			break;
	}

}
