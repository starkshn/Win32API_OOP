#include "pch.h"
#include "PathManager.h"

PathManager::PathManager() : _contentsPath()
{

}

void PathManager::init()
{
	GetCurrentDirectory(255, _contentsPath);

	int len = static_cast<int>(wcslen(_contentsPath));

	for (int i = len - 1; i >= 0; --i)
	{
		if ('\\' == _contentsPath[i])
		{
			_contentsPath[i] = '\0';
			break;
		}
	}

	wcscat_s(_contentsPath, 255, L"\\bin\\Contents\\");
}
