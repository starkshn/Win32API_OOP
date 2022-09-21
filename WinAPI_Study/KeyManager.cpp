#include "pch.h"
#include "KeyManager.h"

unsigned int g_VK[static_cast<unsigned int>(KEY::LAST)] =
{
	VK_LEFT, 
	VK_UP,
	VK_DOWN,
	VK_RIGHT,
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'Z',
	'X',
	'C',
	'V',
	'B',

	VK_MENU,
	VK_LSHIFT,
	VK_SPACE,
	VK_CONTROL,
	VK_RETURN,
	VK_ESCAPE,

	//LAST,
};

KeyManager::KeyManager()
{

}

KeyManager::~KeyManager()
{

}

void KeyManager::init()
{
	for (int i = 0; i < static_cast<unsigned int>(KEY::LAST); ++i)
	{
		_keys.push_back(KeyInfo{ KEY_STATE::NONE, false } );
	}
}

void KeyManager::update()
{
	HWND hWnd = GetFocus();

	if (nullptr != hWnd)
	{
		for (UINT i = 0; i < static_cast<UINT>(KEY::LAST); ++i)
		{
			if (GetAsyncKeyState(g_VK[i]) & 0x8000)
			{
				if (_keys[i]._isPrevInput)
				{
					_keys[i]._state = KEY_STATE::HOLD;
				}
				else
				{
					_keys[i]._state = KEY_STATE::TAP;
				}
				_keys[i]._isPrevInput = true;
			}
			else
			{
				if (_keys[i]._isPrevInput)
				{
					_keys[i]._state = KEY_STATE::AWAY;
				}
				else
				{
					_keys[i]._state = KEY_STATE::NONE;
				}
				_keys[i]._isPrevInput = false;
			}
		}
	}
	else
	{
		for (UINT i = 0; i < static_cast<UINT>(KEY::LAST); ++i)
		{
			_keys[i]._isPrevInput = false;
			if (_keys[i]._state == KEY_STATE::TAP || _keys[i]._state == KEY_STATE::HOLD)
			{
				_keys[i]._state = KEY_STATE::AWAY;
			}
			else if (_keys[i]._state == KEY_STATE::AWAY)
			{
				_keys[i]._state = KEY_STATE::NONE;
			}
		}
	}
}
