#pragma once
class Core
{
	SINGLE(Core);

private:
	HWND	_hWnd; // ���� ������ �ڵ�
	POINT	_resolution; // ���� ������  �ػ�
	HDC		_hDC;

	HBITMAP _bitMap;
	HDC		 _memDC;

public:
	int init(HWND hWnd, POINT resolution);
	void progress();

public :
	HWND GetMainHwnd() { return _hWnd; }

};