#include <stdio.h>

/* cat函数：连接多个文件，版本1 */
main05_c(int argc, char* argv[])
{
	FILE* fp;
	void filecopy(FILE*, FILE*);

	if (argc == 1)
		filecopy(stdin, stdout);
	else
		while (--argc > 0) {
			fopen_s(&fp, *++argv, "r");

			if (fp == NULL) {  // win32要求将fopen换为fopen_s
				printf("cat: can't open %s\n", *argv);
				return 1;
			}
			else {
				filecopy(fp, stdout);  // 复制文件到标准输出
				fclose(fp);
			}
		}
	return 0;
}

/* filecopy函数：将文件ifp复制到文件ofp */
void filecopy(FILE* ifp, FILE* ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}