#pragma once
#include "Object.h"
class Player : public Object
{
private:

public :
	Player();
	~Player();

public:
	virtual void update() final;
	virtual void render(HDC dc) final;

public:
	void CreateMissile();
	void CreateThreeMissile();

public:

};

