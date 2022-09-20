#pragma once
#include "Object.h"

class Texture;

class Player : public Object
{
private:
	CLONE(Player);

	Texture* p_texture;

public :
	Player();
	virtual ~Player() override;

public:
	virtual void update() override;
	virtual void render(HDC dc) override;

public:
	void CreateMissile();
	void CreateThreeMissile();

};

