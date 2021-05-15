#include <stdio.h>


/* fgets��������iopָ����ļ�������ȡn-1���ַ����ټ���һ��NULL */
char* fgets(char *s, int n, FILE *iop)
{
	register int c;
	register char* cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

/* fputs���������ַ���s�����iopָ����ļ��� */
int fputs(char *s, FILE *iop)
{
	int c;

	while (c = *s++)
		putc(c, iop);
	return ferror(iop) ? EOF : 1;
}

/* �����Ǳ�׼����fgets��fputs�����Ĵ��� */