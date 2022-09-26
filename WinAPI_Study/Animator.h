#pragma once

class Object;
class Animation;
class Texture;

class Animator
{
private:
	Object*						p_owner;
	map<wstring, Animation*>	_mapAnimations;
	Animation*					p_curAnimation;
	bool						_animRepeat;

public:
	Animator();
	Animator(const Animator& other);
	~Animator();

public:
	void update();
	void finalUpdate();
	void render(HDC dc);

public:
	void CreateAnimation
	(
		const wstring& animationName,
		Texture* texture, Vector2 startPos,
		Vector2 sliceSize, Vector2 step,
		float duration, UINT frameCount
	);

	Animation* FindAnimation(const wstring& animName);
	void PlayAnimation(const wstring& animName, bool animRepeat);

public:
	Object* GetOwnerObject() { return p_owner; };

	friend class Object;
};

