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

	//オプションの数
	int numOptions = argc - NumArgument;
	//オプション配列
	char** options = argv + NumArgument;

	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(argc >= NumArgument);

	TextrueConverter converter;

	//テクスチャ変換
	converter.ConvertTextrueWICToDDS(argv[kFilePath], numOptions, options);

	CoUninitialize();

	//printf("Hello,World!\n");

	////argcの数だけ繰り返す
	//for (int i = 0; i < argc; i++) {
	//	//文字列argvのi番目を表示
	//	printf(argv[i]);
	//	//改行
	//	printf("\n");
	//}

	//system("pause");

	return 0;
}