#include "pch.h"
#include "Animation.h"
#include "TimeManager.h"
#include "Animator.h"
#include "Object.h"
#include "Texture.h"

Animation::Animation()
	:
	p_animator(nullptr),
	p_texture(nullptr),
	_animationName(),
	_vecAnimFrame{},
	_curFrame(0),
	_accTime(0.f),
	_animFinish(false)
{

}

Animation::~Animation()
{

}

void Animation::update()
{
	if (_animFinish)
		return;

	_accTime += DeltaTime_F;

	if (_accTime > _vecAnimFrame[_curFrame]._duration)
	{
		++_curFrame;

		if (_vecAnimFrame.size() <= _curFrame)
		{
			_curFrame = -1;
			_animFinish = true;
			_accTime = 0.f;
			return;
		}

		_accTime = _accTime - _vecAnimFrame[_curFrame]._duration;
	}
}

void Animation::render(HDC dc)
{
	if (_animFinish)
		return;

	Object* go = p_animator->GetOwnerObject();
	Vector2 pos = go->GetPos();

	pos += _vecAnimFrame[_curFrame]._offset;

	TransparentBlt
	(
		dc,
		(int)(pos._x - (_vecAnimFrame[_curFrame]._sliceSize._x / 2.f)),
		(int)(pos._y - (_vecAnimFrame[_curFrame]._sliceSize._y / 2.f)),
		(int)(_vecAnimFrame[_curFrame]._sliceSize._x),
		(int)(_vecAnimFrame[_curFrame]._sliceSize._y),
		p_texture->GetDC(),
		(int)(_vecAnimFrame[_curFrame]._leftTop._x),
		(int)(_vecAnimFrame[_curFrame]._leftTop._y),
		(int)(_vecAnimFrame[_curFrame]._sliceSize._x),
		(int)(_vecAnimFrame[_curFrame]._sliceSize._y),
		RGB(0, 255, 0)
	);
}

void Animation::Create
(
	Texture* texture, Vector2 startPos, Vector2 sliceSize, Vector2 step, float duration, UINT frameCount
)
{
	p_texture = texture;

	AnimFrame frm = {};

	for (UINT i = 0; i < frameCount; ++i)
	{
		frm._duration = duration;
		frm._sliceSize = sliceSize;
		frm._leftTop = startPos + (step * i);

		_vecAnimFrame.push_back(frm);
	}
}

