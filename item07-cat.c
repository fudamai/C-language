#include <stdio.h>

/* cat���������Ӷ���ļ����汾1 */
main05_c(int argc, char* argv[])
{
	FILE* fp;
	void filecopy(FILE*, FILE*);

	if (argc == 1)
		filecopy(stdin, stdout);
	else
		while (--argc > 0) {
			fopen_s(&fp, *++argv, "r");

			if (fp == NULL) {  // win32Ҫ��fopen��Ϊfopen_s
				printf("cat: can't open %s\n", *argv);
				return 1;
			}
			else {
				filecopy(fp, stdout);  // �����ļ�����׼���
				fclose(fp);
			}
		}
	return 0;
}

/* filecopy���������ļ�ifp���Ƶ��ļ�ofp */
void filecopy(FILE* ifp, FILE* ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}