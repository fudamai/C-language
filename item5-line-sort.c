#include <stdio.h>
#include <string.h>

#define MAXLINE 5000  // �������������ı�����

char *lineptr[MAXLINE];  // ָ���ı��е�ָ������

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* ��������ı��������� */
main_line_sort()
{
	int nlines;  // ��ȡ����������Ŀ

	if ((nlines = readlines(lineptr, MAXLINE)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("error: input too big to sort.\n");
		return 1;
	}
}

#define MAXLEN 1000  // ÿ�������ı��е���󳤶�
int getline(char *, int);
char *alloc(int);

/* readlines��������ȡ������ */
int readlines(char* lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;

	while ((len = getline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL) {
			return -1;
		}
		else
		{
			line[len - 1] = '\0';  // ɾ�����з�
			strcpy05_1(p, line);  // ��line����Ԫ�صĵ�ַ��p
			lineptr[nlines++] = p;  // ��ָ�뱣�浽ָ�����顣ͨ��ָ�����ҵ�����line
		}
	}
	return nlines;
}

/* writelines������д������ */
void writelines(char* lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);  // �����ӡ����ָ�롣���������һ��Ԫ�ص�ָ��
}

/* qsort������������˳���v[left]...v[right]�������� */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap_pointer(char *v[], int i, int j);

	if (left >= right)  // �������Ԫ�صĸ���С��2���򷵻�
		return;
	swap_pointer(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap_pointer(v, ++last, i);
	swap_pointer(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* swap_pointer����������v[i]��v[j] */
void swap_pointer(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* getline��������һ�ж��뵽s�в������䳤�� */
int getline(char s[], int lim)
{
	int c, i;
	/*��forѭ���ڣ������ı���������ʱ������ѭ��
	�������ı�����δ�������ʲ���ִ��if(c =='\n'),ֱ��ִ��s[i] = c
	����ִ��copy
	��ʼ��whileѭ��ִ�еڶ��ֶ�ȡc����ʣ�µ�cд�뵽����s�������һ�ֶ�ȡ��ȫ���ı����ͼ�⵽'\n'����'\n'���뵽
	����s�У���һ���������s�������д�ˣ�
	*/
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		//printf("%d, [40]", i);
		++i;
	}
	s[i] = '\0';
	//printf("%d, [44]", i);
	return i;
}