#pragma once
class Core
{
	SINGLE(Core);

private:
	HWND	_hWnd; // 메인 윈도우 핸들
	POINT	_resolution; // 메인 윈도우  해상도
	HDC		_hDC;

	HBITMAP _bitMap;
	HDC		 _memDC;

public:
	int init(HWND hWnd, POINT resolution);
	void progress();

public :
	HWND GetMainHwnd() { return _hWnd; }

};