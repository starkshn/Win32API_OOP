#pragma once
#include "Resources.h"

class Texture : public Resources
{
private:
	HDC			h_dc;
	HBITMAP		h_bitMap;
	BITMAP		_objectInfo;

private:
	Texture();
	virtual ~Texture() override;

public :
	void Load(const wstring& path);

public:
	void SetWidthInfo(LONG width) { _objectInfo.bmWidth = width; }
	void SetHeightInfo(LONG height) { _objectInfo.bmHeight = height; }

public:
	HDC GetDC() { return h_dc; }
	LONG GetWidth() { return _objectInfo.bmWidth; }
	LONG GetHeight() { return _objectInfo.bmHeight; }
	BITMAP GetInfo() { return _objectInfo; }

	friend class ResourceManager;
};

