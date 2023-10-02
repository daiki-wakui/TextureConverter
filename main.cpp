#include <cstdio>
#include <cstdlib>
#include <DirectXTex.h>

int main(int argc, char* argv[]) {

	printf("Hello,World!\n");

	//argc‚Ì”‚¾‚¯ŒJ‚è•Ô‚·
	for (int i = 0; i < argc; i++) {
		//•¶š—ñargv‚Ìi”Ô–Ú‚ğ•\¦
		printf(argv[i]);
		//‰üs
		printf("\n");
	}

	system("pause");

	return 0;
}