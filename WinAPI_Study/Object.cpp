#include "pch.h"
#include "Object.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "Collider.h"
#include "Animator.h"

Object::Object() 
	: 
	_pos{}, 
	_scale{},
	_theta(0),
	p_collider(nullptr),
	p_animator(nullptr),
	_alive(true)
{

}

Object::Object(const Object& origin)
	:
	_objectName(origin._objectName),
	_pos(origin._pos),
	_scale(origin._scale),
	p_collider(nullptr),
	p_animator(nullptr),
	_alive(true)
{
	if (origin.p_collider)
	{
		p_collider = new Collider(*origin.p_collider);
		p_collider->p_owner = this;
	}

	if (origin.p_animator)
	{
		p_animator = new Animator(*origin.p_animator);
		p_animator->p_owner = this;
	}
}

Object::~Object()
{
	if (nullptr != p_collider)
		delete p_collider;

	if (nullptr != p_animator)
		delete p_animator;
}

void Object::finalUpdate()
{
	if (p_collider != nullptr)
	{
		p_collider->finalUpdate();
	}
}

void Object::render(HDC dc)
{
	Rectangle
	(	
		dc,
		static_cast<int>(_pos._x - _scale._x / 2.f),
		static_cast<int>(_pos._y - _scale._y / 2.f),
		static_cast<int>(_pos._x + _scale._x / 2.f),
		static_cast<int>(_pos._y + _scale._x / 2.f)
	);

	ComponentRender(dc);
}

void Object::ComponentRender(HDC dc)
{
	if (p_collider != nullptr)
		p_collider->render(dc);

	if (p_animator != nullptr)
		p_animator->render(dc);
}

void Object::CreateCollider()
{
	p_collider = new Collider;
	p_collider->p_owner = this;
}

void Object::CreateAnimator()
{
	p_animator = new Animator();
	p_animator->p_owner = this;
}





