#pragma once
#include "Object.h"

class Texture;

class Missile : public Object
{
private:
	CLONE(Missile);

	Texture* p_texture;

public:
	Missile();
	virtual ~Missile() override;

public:
	virtual void update() final;
	virtual void render(HDC dc) final;
};

