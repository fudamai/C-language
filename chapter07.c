#include <stdio.h>
#include <ctype.h>

main(int argc, char* argv[])
{
	int c;
	FILE* fp;

	fopen_s(&fp, argv[1], "r");  // ��һ���ļ�
	while ((c = getc(fp)) != EOF) { // ���ļ��л�ȡ�ַ�
		putchar(c);  // ����ַ�����׼�����ʹ��
		printf("%s\n", &(char*)c);
	}
	fclose(fp);
	while ((c = getchar()) != EOF)
	{
		putchar(tolower(c));
	}
	return 0;
}