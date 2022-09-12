#pragma once
#include "Scene.h"

class StartScene : public Scene
{
public:
	StartScene();
	virtual ~StartScene() override;

private:
	virtual void Enter() override;
	virtual void Exit() override;



};

