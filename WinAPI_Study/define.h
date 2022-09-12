#pragma once
#include "pch.h"

// Singletone
#define SINGLE(type) public: static type* GetInstance() { static type manager; return &manager; } private : type(); ~type();

#define DeltaTime_F TimeManager::GetInstance()->GetfDeltaTime()
#define DeltaTime TimeManager::GetIstance()->GetDeltaTime()

enum class OBJECT_TYPE
{
	DEFAULT,
	PLAYER,
	MONSTER,
	ARROW,
	MISSILE,

	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	END = 12,
};
