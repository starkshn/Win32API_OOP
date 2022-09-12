#pragma once
#include "pch.h"

// Singletone
#define SINGLE(type) public: static type* GetInstance() { static type manager; return &manager; } private : type(); ~type();

#define DeltaTime_F TimeManager::GetInstance()->GetfDeltaTime()
#define DeltaTime TimeManager::GetIstance()->GetDeltaTime()

#define KEY_CHECK(key, state) KeyManager::GetInstance()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)

#define PI 3.1415926535f

enum class OBJECT_TYPE
{
	DEFAULT,
	PLAYER,
	MONSTER,
	MISSILE,
	THREEEMISSILE,
	MONSTERMISSILE,

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

enum class HBRUSH_TYPE
{
	HOLLOW,

	END,
};

enum class HPEN_TYPE
{
	RED,
	GREEN,
	BLUE,

	END,
};

