#include "pch.h"
#include "Object.h"
#include "KeyManager.h"
#include "TimeManager.h"

Object::Object() 
	: 
	_pos{}, 
	_scale{},
	_theta(0)
{

}
Object::~Object()
{
	
}

void Object::render(HDC dc)
{
	Rectangle
	(	dc,
		static_cast<int>(_pos._x - _scale._x / 2.f),
		static_cast<int>(_pos._y - _scale._y / 2.f),
		static_cast<int>(_pos._x + _scale._x / 2.f),
		static_cast<int>(_pos._y + _scale._x / 2.f)
	);
}
