#include "TextrueConverter.h"
#include <Windows.h>

void TextrueConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//ファイルパスをワイド文字列に変換
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);

	//テクスチャを読み込む


}

std::wstring TextrueConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//ワイド文字列に変換した際の文字数を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}

void TextrueConverter::ConvertTextrueWICToDDS(const std::string& filePath)
{
	//テクスチャを読み込む
	LoadWICTextureFromFile(filePath);

	//DDS形式に変換して書き出す


}
