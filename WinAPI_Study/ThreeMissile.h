#pragma once
#include "Object.h"


class ThreeMissile : public Object
{
private:
    CLONE(ThreeMissile);

public:
    ThreeMissile();
    virtual ~ThreeMissile() override;

public:
    virtual void update() override;
    virtual void render(HDC dc) override;
};

