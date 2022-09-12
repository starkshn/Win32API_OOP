#pragma once
#include "Object.h"

class Texture;

class Player : public Object
{
private:
	Texture* p_texture;

public :
	Player();
	virtual ~Player() override;

public:
	virtual void update() final;
	virtual void render(HDC dc) final;

public:
	void CreateMissile();
	void CreateThreeMissile();

public:

};

