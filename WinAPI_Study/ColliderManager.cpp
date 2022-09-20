#include "pch.h"
#include "ColliderManager.h"
#include "Object.h"
#include "Collider.h"
#include "SceneManager.h"
#include "Scene.h"

void ColliderManager::update()
{
	for (UINT row = 0; row < static_cast<UINT>(OBJECT_TYPE::END); ++row)
	{
		for (UINT col = 0; col < static_cast<UINT>(OBJECT_TYPE::END); ++col)
		{
			if (_arrCheckCollision[row] & (1 << col))
			{
				CollisionObjectUpdate((OBJECT_TYPE)row, (OBJECT_TYPE)col);
			}
		}
	}
}

void ColliderManager::CollisionObjectUpdate(OBJECT_TYPE left, OBJECT_TYPE right)
{
	Scene* curScene = SceneManager::GetInstance()->GetCurrentScene();
	const vector<Object*>& vecLeft = curScene->GetSceneObjects(left);
	const vector<Object*>& vecRight = curScene->GetSceneObjects(right);
	map<ULONGLONG, bool>::iterator iter;

	for (size_t i = 0; i < vecLeft.size(); ++i)
	{
		// 충돌체 보유하지 않은 경우
		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		for (size_t j = 0; j < vecRight.size(); ++j)
		{
			// 충돌체를 보유하지 않은 경우 || 나 자신일 경우
			if (nullptr == vecRight[j]->GetCollider() || vecLeft[i] == vecRight[j])
				continue;
			
			Collider* leftCollider = vecLeft[i]->GetCollider();
			Collider* rightCollider = vecRight[j]->GetCollider();

			// 두 충돌체의 유일한 아이디 조합 생성
			COLLIDER_ID id;
			id._leftID = leftCollider->GetID();
			id._rightID = rightCollider->GetID();

			

		}


	}
}

void ColliderManager::CheckObjectType()
{

}



bool ColliderManager::IsCollision(Collider* leftCollider, Collider* rightCollider)
{

}