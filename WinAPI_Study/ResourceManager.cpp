#include "pch.h"
#include "ResourceManager.h"
#include "PathManager.h"
#include "Texture.h"
#include <algorithm>

ResourceManager::~ResourceManager()
{
	for_each
	(
		_mapTexture.begin(),
		_mapTexture.end(),
		[&](std::pair<wstring, Texture*>pair)
		{
			if (pair.second != nullptr) 
				delete pair.second;
		}
	);
}

Texture* ResourceManager::LoadTexture(const wstring& key, const wstring& path)
{
	Texture* loadObject = FindTexture(key);

	if (nullptr != loadObject)
		return loadObject;

	wstring filePath = PathManager::GetInstance()->GetContentsPath();
	filePath += path;

	loadObject = new Texture;
	loadObject->Load(filePath);
	loadObject->SetKey(key);
	loadObject->SetRelativePath(path);
	
	_mapTexture.insert(make_pair(key, loadObject));

	return loadObject;
}

Texture* ResourceManager::FindTexture(const wstring& key)
{
	auto iter = _mapTexture.find(key);
	
	if (iter == _mapTexture.end())
		return nullptr;

	return iter->second;
}