#pragma once

class Resources
{
private:
	wstring _key;
	wstring _relativePath;

public:
	Resources();
	virtual ~Resources();

public:
	void SetKey(const wstring& key) { _key = key; }
	void SetRelativePath(const wstring& path) { _relativePath = path; }

	const wstring& GetKey() { return _key; }
	const wstring& GetRelativePath() { return _relativePath; }
};

