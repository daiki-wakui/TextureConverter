#include <cstdio>
#include <cstdlib>
#include <DirectXTex.h>
#include "TextrueConverter.h"

enum Argument{
	kApplicationPath,
	kFilePath,

	NumArgument
};

int main(int argc, char* argv[]) {
	if (argc < NumArgument) {
		TextrueConverter::OutputUsage();
		return 0;
	}

	//�I�v�V�����̐�
	int numOptions = argc - NumArgument;
	//�I�v�V�����z��
	char** options = argv + NumArgument;

	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(argc >= NumArgument);

	TextrueConverter converter;

	//�e�N�X�`���ϊ�
	converter.ConvertTextrueWICToDDS(argv[kFilePath], numOptions, options);

	CoUninitialize();

	//printf("Hello,World!\n");

	////argc�̐������J��Ԃ�
	//for (int i = 0; i < argc; i++) {
	//	//������argv��i�Ԗڂ�\��
	//	printf(argv[i]);
	//	//���s
	//	printf("\n");
	//}

	//system("pause");

	return 0;
}