#pragma once
#include <string>

class TextrueConverter
{
private:

	//�e�N�X�`���ǂݍ���
	void LoadWICTextureFromFile(const std::string& filePath);

	//���C�h������ϊ�
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

public:

	void ConvertTextrueWICToDDS(const std::string& filePath);

};

