#pragma once
#include "Object.h"
class Missile : public Object
{
private:

public:
	Missile();
	~Missile();

public:
	virtual void update() final;
	virtual void render(HDC dc) final;
};

