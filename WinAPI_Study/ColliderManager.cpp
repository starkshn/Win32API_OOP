#include "pch.h"
#include "ColliderManager.h"
#include "Object.h"
#include "Collider.h"
#include "SceneManager.h"
#include "Scene.h"

ColliderManager::ColliderManager()
{

}

ColliderManager::~ColliderManager()
{

}


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

			iter = _mapCollisionInfo.find(id._id);

			if (_mapCollisionInfo.end() == iter)
			{
				_mapCollisionInfo.insert(make_pair(id._id, false));
				iter = _mapCollisionInfo.find(id._id);
			}

			if (IsCollision(leftCollider, rightCollider))
			{
				// 현재 충돌중이다.
				if (iter->second)
				{
					if (vecLeft[i]->IsDead() || vecRight[j]->IsDead())
					{
						leftCollider->OnCollisionExit(rightCollider);
						rightCollider->OnCollisionExit(leftCollider);
						iter->second = false;
					}
					else
					{
						leftCollider->OnCollisionStay(rightCollider);
						rightCollider->OnCollisionStay(leftCollider);
					}
				}
				else
				{
					// 이전에는 충돌하지 않았다.

					if (!(vecLeft[i]->IsDead()) && !(vecRight[j]->IsDead()))
					{
						leftCollider->OnCollisionEnter(rightCollider);
						rightCollider->OnCollisionEnter(leftCollider);
						iter->second = true;
					}

					// 충돌 없었다. (일로 내려오면은)
				}
			}
			else
			{
				// 현재 충돌중이지 않다.

				if (iter->second)
				{
					leftCollider->OnCollisionExit(rightCollider);
					rightCollider->OnCollisionExit(leftCollider);
					iter->second = false;
				}
			}

		}
	}
}

bool ColliderManager::IsCollision(Collider* leftCollider, Collider* rightCollider)
{
	Vector2 leftPos = leftCollider->GetFinalPos();
	Vector2 leftScale = leftCollider->GetColliderScale();

	Vector2 rightPos = rightCollider->GetFinalPos();
	Vector2 rightScale = rightCollider->GetColliderScale();

	if ( abs(rightPos._x - leftPos._x) < (rightScale._x + leftScale._x) / 2.f && abs(rightPos._y - leftPos._y) < (rightScale._y + leftScale._y) / 2.f)
	{
		return true;
	}

	return false;
}

void ColliderManager::CheckObjectType(OBJECT_TYPE left, OBJECT_TYPE right)
{
	// 더 작은 값을 행으로, 더 큰 값을 열로 사용

	UINT row = static_cast<UINT>(left);
	UINT col = static_cast<UINT>(right);

	if (col < row)
	{
		UINT temp = static_cast<UINT>(row);
		row = static_cast<UINT>(col);
		col = temp;
	}

	if (_arrCheckCollision[row] & (1 << col))
		_arrCheckCollision[row] &= ~(1 << col);
	else
		_arrCheckCollision[row] |= (1 << col);
}



