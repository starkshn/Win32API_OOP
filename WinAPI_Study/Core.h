#pragma once
class Core
{
	SINGLE(Core);

private:
	HWND		_hWnd; // 메인 윈도우 핸들
	POINT		_resolution; // 메인 윈도우  해상도
	HDC			h_dc;
	HBITMAP		h_bitMap;
	HDC			h_memDC;

	// 자주 사용하는 GDI Object (커널오브젝트)
	HBRUSH h_brushes[static_cast<UINT>(HBRUSH_TYPE::END)];
	HPEN h_pens[static_cast<UINT>(HPEN_TYPE::END)];

public:
	int init(HWND hWnd, POINT resolution);
	void progress();

private:
	void CreateHBRUSH();
	void CreateHPEN();

public :

	HWND GetMainHwnd() { return _hWnd; }
	POINT GetResolution() { return _resolution; }
	HDC GetMainDC() { return h_dc; }
	HBRUSH GetHBRUSH(HBRUSH_TYPE type) { return h_brushes[static_cast<UINT>(type)]; }
	HPEN GetHBRUSH(HPEN_TYPE type) { return h_pens[static_cast<UINT>(type)]; }

};