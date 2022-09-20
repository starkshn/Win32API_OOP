#pragma once

class Texture;

class ResourceManager
{
	SINGLE(ResourceManager)

private:
	map<wstring, Texture*> _mapTexture;

public:
	Texture* LoadTexture(const wstring& key, const wstring& path);
	Texture* FindTexture(const wstring& key);

	struct DeleteTexture
	{
		void operator () (std::pair<wstring, Texture*> pair)
		{
			if (pair.second != nullptr)
				delete pair.second;
		}
	};
};

