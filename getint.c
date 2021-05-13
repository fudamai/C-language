#include <ctype.h>
#include <stdio.h>

#define SIZE 100

int getch(void);
void ungetch(int);

main_getint()
{
	int n, array[SIZE], getint(int*);

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];  // 用于ungetch函数的缓冲区
int bufp = 0;  // buf中下一个空闲位置

int getch(void)  // 取一个字符（可能是压回的字符）
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  // 把字符压回输入中
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}