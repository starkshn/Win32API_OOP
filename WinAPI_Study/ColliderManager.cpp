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

			iter = _mapCollisionInfo.find(id._id);

			if (_mapCollisionInfo.end() == iter)
			{
				_mapCollisionInfo.insert(make_pair(id._id, false));
				iter = _mapCollisionInfo.find(id._id);
			}

			if (IsCollision(leftCollider, rightCollider))
			{
				// ���� �浹���̴�.
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
					// �������� �浹���� �ʾҴ�.

					if (!(vecLeft[i]->IsDead()) && !(vecRight[j]->IsDead()))
					{
						leftCollider->OnCollisionEnter(rightCollider);
						rightCollider->OnCollisionEnter(leftCollider);
						iter->second = true;
					}

					// �浹 ������. (�Ϸ� ����������)
				}
			}
			else
			{
				// ���� �浹������ �ʴ�.

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
	// �� ���� ���� ������, �� ū ���� ���� ���

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



