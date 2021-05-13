#include <stdio.h>
#include <string.h>

#define MAXLINE 5000  // 进行排序的最大文本行数

char *lineptr[MAXLINE];  // 指向文本行的指针数组

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* 对输入的文本进行排序 */
main_line_sort()
{
	int nlines;  // 读取的输入行数目

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

#define MAXLEN 1000  // 每个输入文本行的最大长度
int getline(char *, int);
char *alloc(int);

/* readlines函数：读取输入行 */
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
			line[len - 1] = '\0';  // 删除换行符
			strcpy05_1(p, line);  // 将line数组元素的地址给p
			lineptr[nlines++] = p;  // 将指针保存到指针数组。通过指针能找到数组line
		}
	}
	return nlines;
}

/* writelines函数：写输入行 */
void writelines(char* lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);  // 这里打印的是指针。保存数组第一个元素的指针
}

/* qsort函数：按递增顺序对v[left]...v[right]进行排序 */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap_pointer(char *v[], int i, int j);

	if (left >= right)  // 如果数组元素的个数小于2，则返回
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

/* swap_pointer函数：交换v[i]和v[j] */
void swap_pointer(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* getline函数：将一行读入到s中并返回其长度 */
int getline(char s[], int lim)
{
	int c, i;
	/*当for循环内，输入文本大于限制时，跳出循环
	但由于文本流尚未结束，故不会执行if(c =='\n'),直接执行s[i] = c
	跳回执行copy
	开始在while循环执行第二轮读取c，将剩下的c写入到数组s。如果这一轮读取了全部文本，就检测到'\n'，将'\n'插入到
	数组s中（这一轮里的数组s被清空重写了）
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