#pragma once
#include <string>

class TextrueConverter
{
private:

	//テクスチャ読み込み
	void LoadWICTextureFromFile(const std::string& filePath);

	//ワイド文字列変換
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

public:

	void ConvertTextrueWICToDDS(const std::string& filePath);

};

