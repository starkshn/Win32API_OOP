#pragma once
#include "Object.h"
class MonsterMissile : public Object
{
private:
	CLONE(MonsterMissile);

public:
	MonsterMissile();
	virtual ~MonsterMissile() override;

public:
	virtual void update() override;
	virtual void render(HDC dc) override;
	

};

