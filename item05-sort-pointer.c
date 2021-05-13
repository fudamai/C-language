#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000  // 进行排序的最大文本行数

char *lineptr[MAXLINES];  // 指向文本行的指针数组

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);
int getline(char*, int);
void qsort_comp(void *lineptr[], int left, int right,
	int (*comp)(void *, void *));
int numcmp(char*, char*);
void swap_pointer_void(void* v[], int i, int j);

/*
输入命令行-n时，倒序排序
*/

/* 对输入的文本进行排序 */
main(int argc, char *argv[])
{
	int nlines;  // 读取的输入行数目
	int numeric = 0;  // 若进行数值排序，则numeric的值为1

	if (argv > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort_comp((void**)lineptr, 0, nlines - 1,
			(int (*)(void*, void*))(numeric ? numcmp : strcmp));  // 函数如何实现插入
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("error: input too big to sort.\n");
		return 1;
	}
}

/* qsort函数：按递增顺序对v[left]...v[right]进行排序 */
void qsort_comp(char* v[], int left, int right, int (*comp)(void*, void*))
{
	int i, last;
	void swap_pointer(char* v[], int i, int j);

	if (left >= right)  // 如果数组元素的个数小于2，则返回
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

/* numcmp函数：按数值顺序比较字符串s1,s2 */
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

/* swap_pointer函数：交换v[i]和v[j] */
void swap_pointer_void(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}