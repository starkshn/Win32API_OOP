#pragma once

enum class KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	AWAY,
};

enum class KEY
{
	LEFT,
	UP,
	DOWN,
	RIGHT,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	Z,
	X,
	C,
	V,
	B,

	ALT,
	LSHIFT,
	SPACE,
	CTRL,
	ENTER,
	ESC,

	LAST,
};

struct KeyInfo
{
	KEY_STATE	_state;
	bool			_isPrevInput;
};

class KeyManager
{
	SINGLE(KeyManager)

private :
	vector<KeyInfo> _keys;

public :
	void init();
	void update();
	KEY_STATE GetKeyState(KEY inputKey) 
	{
		return _keys[static_cast<UINT>(inputKey)]._state;
	}

};

