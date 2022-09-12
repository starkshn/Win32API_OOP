#include "pch.h"
#include "Core.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "PathManager.h"

Core::Core()
	: 
	_hWnd(0),
	_resolution{},
	h_dc(0),
	h_bitMap(),
	h_memDC(0),
	h_brushes{},
	h_pens{}
{
	CreateHBRUSH();
	CreateHPEN();
}

Core::~Core()
{
	ReleaseDC(_hWnd, h_dc);

	DeleteDC(h_memDC);
	DeleteObject(h_bitMap);

	for (UINT i = 0; i < static_cast<UINT>(HPEN_TYPE::END); ++i)
	{
		DeleteObject(h_pens[i]);
	}
}

int Core::init(HWND hWnd, POINT resolution)
{
	_hWnd = hWnd;
	_resolution = resolution;

	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = { 0, 0, _resolution.x, _resolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); // window의 윈도우 위치와 크기를 변경해주는 함수

	h_dc = GetDC(_hWnd);

	h_bitMap = CreateCompatibleBitmap(h_dc, _resolution.x, _resolution.y);
	h_memDC = CreateCompatibleDC(h_dc);

	HBITMAP prevBit = static_cast<HBITMAP>(SelectObject(h_memDC, h_bitMap));
	DeleteObject(prevBit);

	PathManager::GetInstance()->init();
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
	Rectangle(h_memDC, -1, -1, _resolution.x + 1, _resolution.y + 1);
	
	SceneManager::GetInstance()->render(h_memDC);

	BitBlt(h_dc, 0, 0, _resolution.x, _resolution.y, h_memDC, 0, 0, SRCCOPY);
}

void Core::CreateHBRUSH()
{
	h_brushes[static_cast<UINT>(HBRUSH_TYPE::HOLLOW)] = static_cast<HBRUSH>(GetStockObject(HOLLOW_BRUSH));
}

void Core::CreateHPEN()
{
	h_pens[static_cast<UINT>(HPEN_TYPE::RED)] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	h_pens[static_cast<UINT>(HPEN_TYPE::GREEN)] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	h_pens[static_cast<UINT>(HPEN_TYPE::BLUE)] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}
