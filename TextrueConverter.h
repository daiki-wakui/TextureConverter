#pragma once
#include <string>
#include <DirectXTex.h>

class TextrueConverter
{
private:

	//�摜�̏��
	DirectX::TexMetadata metadata_;

	//�摜�C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;


	//�f�B���N�g���p�X
	std::wstring directoryPath_;

	//�t�@�C����
	std::wstring fileName_;

	//�t�@�C���g���q
	std::wstring fileExt_;

	//�e�N�X�`���ǂݍ���
	void LoadWICTextureFromFile(const std::string& filePath);

	//�t�H���_�p�X�ƃt�@�C�����𕪗�����
	void SeparateFilePath(const std::wstring& filePath);

	void SaveDDSTextureToFile(int numOption, char* options[]);

	//���C�h������ϊ�
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

public:

	void ConvertTextrueWICToDDS(const std::string& filePath,int numOption = 0 , char* options[] = nullptr);


	static void OutputUsage();
};

