#include "pch.h"
#include "TimeManager.h"
#include "Core.h"

TimeManager::TimeManager()
	:
	_curCount{},
	_frequency {},
	_updateCount{},
	_deltaTime{0},
	_accTime{0},
	_fps{0}
{

}
TimeManager::~TimeManager()
{

}

void TimeManager::init()
{
	QueryPerformanceCounter(&_prevCount);

	QueryPerformanceFrequency(&_frequency);
}

void TimeManager::update()
{
	QueryPerformanceCounter(&_curCount);

	_deltaTime = static_cast<double>(_curCount.QuadPart - _prevCount.QuadPart) / static_cast<double>(_frequency.QuadPart);

	_prevCount = _curCount;

	++_updateCount;
	_accTime += _deltaTime; // DT´©Àû

	if (_accTime >= 1.)
	{
		_fps = _updateCount;
		_accTime = 0;
		_updateCount = 0;

		wchar_t bf[255] = {};
		swprintf_s(bf, L"FPS : %d, DT : %.10f", _fps, _deltaTime);
		SetWindowText(Core::GetInstance()->GetMainHwnd(), bf);
	}

}