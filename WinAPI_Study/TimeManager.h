#pragma once
class TimeManager
{
	SINGLE(TimeManager);

private :
	LARGE_INTEGER _curCount;
	LARGE_INTEGER _prevCount;
	LARGE_INTEGER _frequency;

	double	_deltaTime;
	double	_accTime;
	UINT		_updateCount;
	UINT		_fps;

public :
	void init();
	void update();

public :
	double GetDeltaTime() { return _deltaTime; }
	float GetfDeltaTime() { return static_cast<float>(_deltaTime); }
};

