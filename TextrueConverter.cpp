#include "TextrueConverter.h"
#include <Windows.h>

void TextrueConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//�t�@�C���p�X�����C�h������ɕϊ�
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);

	//�e�N�X�`����ǂݍ���


}

std::wstring TextrueConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//���C�h������ɕϊ������ۂ̕��������v�Z
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//���C�h������
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//���C�h������ɕϊ�
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}

void TextrueConverter::ConvertTextrueWICToDDS(const std::string& filePath)
{
	//�e�N�X�`����ǂݍ���
	LoadWICTextureFromFile(filePath);

	//DDS�`���ɕϊ����ď����o��


}
