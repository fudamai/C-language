#include <stdio.h>
#include <ctype.h>

main(int argc, char* argv[])
{
	int c;
	FILE* fp;

	fopen_s(&fp, argv[1], "r");  // 打开一个文件
	while ((c = getc(fp)) != EOF) { // 从文件中获取字符
		putchar(c);  // 输出字符，标准输出。使用
		printf("%s\n", &(char*)c);
	}
	fclose(fp);
	while ((c = getchar()) != EOF)
	{
		putchar(tolower(c));
	}
	return 0;
}