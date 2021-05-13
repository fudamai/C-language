#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000  // �������������ı�����

char *lineptr[MAXLINES];  // ָ���ı��е�ָ������

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);
int getline(char*, int);
void qsort_comp(void *lineptr[], int left, int right,
	int (*comp)(void *, void *));
int numcmp(char*, char*);
void swap_pointer_void(void* v[], int i, int j);

/*
����������-nʱ����������
*/

/* ��������ı��������� */
main(int argc, char *argv[])
{
	int nlines;  // ��ȡ����������Ŀ
	int numeric = 0;  // ��������ֵ������numeric��ֵΪ1

	if (argv > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort_comp((void**)lineptr, 0, nlines - 1,
			(int (*)(void*, void*))(numeric ? numcmp : strcmp));  // �������ʵ�ֲ���
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("error: input too big to sort.\n");
		return 1;
	}
}

/* qsort������������˳���v[left]...v[right]�������� */
void qsort_comp(char* v[], int left, int right, int (*comp)(void*, void*))
{
	int i, last;
	void swap_pointer(char* v[], int i, int j);

	if (left >= right)  // �������Ԫ�صĸ���С��2���򷵻�
		return;
	swap_pointer(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap_pointer_void(v, ++last, i);
	swap_pointer(v, left, last);
	qsort_comp(v, left, last - 1, comp);
	qsort_comp(v, last + 1, right, comp);
}

/* numcmp����������ֵ˳��Ƚ��ַ���s1,s2 */
int numcmp(char* s1, char* s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

/* swap_pointer����������v[i]��v[j] */
void swap_pointer_void(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}