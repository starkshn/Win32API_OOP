#include "pch.h"
#include "Core.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "SceneManager.h"

Core::Core()
{

}

Core::~Core()
{
	ReleaseDC(_hWnd, _hDC);

	DeleteDC(_memDC);
	DeleteObject(_bitMap);
}

int Core::init(HWND hWnd, POINT resolution)
{
	_hWnd = hWnd;
	_resolution = resolution;

	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = { 0, 0, _resolution.x, _resolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); // window의 윈도우 위치와 크기를 변경해주는 함수

	_hDC = GetDC(_hWnd);

	_bitMap = CreateCompatibleBitmap(_hDC, _resolution.x, _resolution.y);
	_memDC = CreateCompatibleDC(_hDC);

	HBITMAP prevBit = static_cast<HBITMAP>(SelectObject(_memDC, _bitMap));
	DeleteObject(prevBit);

	TimeManager::GetInstance()->init();
	KeyManager::GetInstance()->init();
	SceneManager::GetInstance()->init();

	return S_OK;
}

void Core::progress()
{
	// Managers update
	TimeManager::GetInstance()->update();
	KeyManager::GetInstance()->update();
	SceneManager::GetInstance()->update();

	// rendering...
	// window clear
	Rectangle(_memDC, -1, -1, _resolution.x + 1, _resolution.y + 1);
	
	SceneManager::GetInstance()->render(_memDC);

	BitBlt(_hDC, 0, 0, _resolution.x, _resolution.y, _memDC, 0, 0, SRCCOPY);
}
