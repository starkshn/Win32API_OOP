#pragma once
#include "Scene.h"

class Texture;

class StartScene : public Scene
{
private:
	UINT _monsterCount;
	Texture* p_backGroundTexture;
	
public:
	StartScene();
	virtual ~StartScene() override;

private:
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void render(HDC dc) override;

public:
	void SetMonsterCount(UINT monsterCount) { _monsterCount = monsterCount; }

	int GetMonsterCount() { return _monsterCount; }
	
};

