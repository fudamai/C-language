#include <stdio.h>

/* cat函数：连接多个文件，版本2 */
main07_c_e(int argc, char *argv[])
{
	FILE* fp;
	void filecopy(FILE*, FILE*);
	char* prog = argv[0];

	if (argc == 1)
		filecopy(stdin, stdout);
	else
	{
		while (--argc > 0) {
			if ((fopen_s(&fp, *++argv, "r")) == NULL) {
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			}
			else {
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
	if (ferror(stdout)) {
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}
	exit(0);
}