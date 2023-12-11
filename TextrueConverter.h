#pragma once
#include <string>
#include <DirectXTex.h>

class TextrueConverter
{
private:

	//画像の情報
	DirectX::TexMetadata metadata_;

	//画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;


	//ディレクトリパス
	std::wstring directoryPath_;

	//ファイル名
	std::wstring fileName_;

	//ファイル拡張子
	std::wstring fileExt_;

	//テクスチャ読み込み
	void LoadWICTextureFromFile(const std::string& filePath);

	//フォルダパスとファイル名を分離する
	void SeparateFilePath(const std::wstring& filePath);

	void SaveDDSTextureToFile(int numOption, char* options[]);

	//ワイド文字列変換
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

public:

	void ConvertTextrueWICToDDS(const std::string& filePath,int numOption = 0 , char* options[] = nullptr);


	static void OutputUsage();
};

