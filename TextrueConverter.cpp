#include "TextrueConverter.h"
#include <Windows.h>

using namespace DirectX;

void TextrueConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	HRESULT result;

	//�t�@�C���p�X�����C�h������ɕϊ�
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);

	//�e�N�X�`����ǂݍ���

	//WIC�e�N�X�`�����[�h
	result = LoadFromWICFile(wfilePath.c_str(), WIC_FLAGS_NONE, &metadata_, scratchImage_);
	assert(SUCCEEDED(result));

	SeparateFilePath(wfilePath);

	
}

void TextrueConverter::SeparateFilePath(const std::wstring& filePath)
{
	size_t pos1;
	std::wstring exceptExt;

	//��؂蕶��'.'���o�Ă����ԍŌ�̕���������
	pos1 = filePath.rfind('.');

	//�������q�b�g������
	if (pos1 != std::wstring::npos) {
		//��؂蕶���̌����t�@�C���g���q�Ƃ��ĕۑ�
		fileExt_ = filePath.substr(pos1 + 1, filePath.size() - pos1 - 1);
		//��؂蕶���O�܂ł𔲂��o��
		exceptExt = filePath.substr(0, pos1);
	}
	else {
		fileExt_ = L"";
		exceptExt = filePath;
	}

	//��؂蕶�� '\\'���o�ł����ԍŌ������
	pos1 = exceptExt.rfind('\\');

	if (pos1 != std::wstring::npos) {
		directoryPath_ = exceptExt.substr(0, pos1 + 1);

		fileName_ = exceptExt.substr(pos1 + 1, exceptExt.size() - pos1 - 1);
		return;
	}

	pos1 = exceptExt.rfind('/');
	if (pos1 != std::wstring::npos) {
		directoryPath_ = exceptExt.substr(0, pos1 + 1);

		fileName_ = exceptExt.substr(pos1 + 1, exceptExt.size() - pos1 - 1);
		return;
	}

	directoryPath_ = L"";
	fileName_ = exceptExt;
}

void TextrueConverter::SaveDDSTextureToFile()
{
	HRESULT result;
	ScratchImage mipChain;

	//�~�b�v�}�b�v�쐬
	result = GenerateMipMaps(scratchImage_.GetImages(),
		scratchImage_.GetImageCount(), scratchImage_.GetMetadata(),
		TEX_FILTER_DEFAULT, 0, mipChain);

	if (SUCCEEDED(result)) {
		//�C���[�W�ƃ��^�f�[�^������������
		scratchImage_ = std::move(mipChain);
		metadata_ = scratchImage_.GetMetadata();
	}

	//���k�`���ɕϊ�
	ScratchImage converted;
	result = Compress(scratchImage_.GetImages(),
		scratchImage_.GetImageCount(),
		metadata_, DXGI_FORMAT_BC7_UNORM_SRGB, TEX_COMPRESS_BC7_QUICK | TEX_COMPRESS_SRGB_OUT |
		TEX_COMPRESS_PARALLEL, 1.0f, converted);

	if (SUCCEEDED(result)) {
		scratchImage_ = std::move(converted);
		metadata_ = scratchImage_.GetMetadata();
	}

	metadata_.format = MakeSRGB(metadata_.format);

	

	std::wstring filePath = directoryPath_ + fileName_ + L".dds";

	result = SaveToDDSFile(scratchImage_.GetImages(), scratchImage_.GetImageCount(), metadata_,
		DDS_FLAGS_NONE, filePath.c_str());
	assert(SUCCEEDED(result));
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
	SaveDDSTextureToFile();
}
