#include <cstdio>
#include <cstdlib>
#include <DirectXTex.h>

int main(int argc, char* argv[]) {

	printf("Hello,World!\n");

	//argcの数だけ繰り返す
	for (int i = 0; i < argc; i++) {
		//文字列argvのi番目を表示
		printf(argv[i]);
		//改行
		printf("\n");
	}

	system("pause");

	return 0;
}