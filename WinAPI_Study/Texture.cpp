#include "pch.h"
#include "Texture.h"
#include "Core.h"

Texture::Texture()
	:
	h_dc(0),
	h_bitMap{0},
	_objectInfo{}
{

}

Texture::~Texture()
{
	DeleteDC(h_dc);
	DeleteObject(h_bitMap);
}

void Texture::Load(const wstring& path)
{
	h_bitMap = (HBITMAP)LoadImage(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	h_dc = CreateCompatibleDC(Core::GetInstance()->GetMainDC());

	HBITMAP prevBit = (HBITMAP)SelectObject(h_dc, h_bitMap);
	DeleteObject(prevBit);

	GetObject(h_bitMap, sizeof(BITMAP), &_objectInfo);

	if (h_bitMap == nullptr)
		assert(h_bitMap);
}