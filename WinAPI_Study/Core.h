#pragma once
class Core
{
	SINGLE(Core);

private:
	HWND		_hWnd; // ���� ������ �ڵ�
	POINT		_resolution; // ���� ������  �ػ�
	HDC			h_dc;
	HBITMAP		h_bitMap;
	HDC			h_memDC;

	// ���� ����ϴ� GDI Object (Ŀ�ο�����Ʈ)
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