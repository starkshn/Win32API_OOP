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
		// �浹ü �������� ���� ���
		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		for (size_t j = 0; j < vecRight.size(); ++j)
		{
			// �浹ü�� �������� ���� ��� || �� �ڽ��� ���
			if (nullptr == vecRight[j]->GetCollider() || vecLeft[i] == vecRight[j])
				continue;
			
			Collider* leftCollider = vecLeft[i]->GetCollider();
			Collider* rightCollider = vecRight[j]->GetCollider();

			// �� �浹ü�� ������ ���̵� ���� ����
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