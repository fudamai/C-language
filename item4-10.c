#include <stdio.h>
#include <stdlib.h>  // 为了使用atof()函数
#include <ctype.h>

#define MAXOP 100  // 操作数或运算符的最大长度
#define NUMBER '0'  // 标识找到一个数
#define BUFSIZE 100

char buf4_10[BUFSIZE];  // 用于ungetch函数的缓冲区
int bufp4_10 = 0;  // buf中下一个空闲位置
extern int getline(char, int);

/* getop函数：获取下一个运算符或数值操作数 */
int getop4_10(char s[])
{
	int i, c;

	if (buf4_10[bufp4_10] == '\0') {  // 获取新行前判断上一行是否处理完毕
		if (getline(buf4_10, BUFSIZE) == 0) {
			return EOF;  // 没有获取到
		}
		else {
			bufp4_10 = 0;  // 处理完毕，指针归零
		}
	}

	while ((s[0] = c = buf4_10[bufp4_10++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;  // 不是数
	i = 0;
	if (isdigit(c))  // 收集整数部分
		while (isdigit(s[++i] = c = buf4_10[bufp4_10++]))  // 小数点在这里已经赋值完成，超前读入一个字符
			;
	if (c == '.')  // 收集小数部分
		while (isdigit(s[++i] = c = buf4_10[bufp4_10++]))  // 先赋值，再getch。赋值时执行的是覆盖操作。getch返回时，也是先赋值，再判断
			;
	s[i] = '\0';
	if (c != EOF)  // 在Windows中是个多余的判断
		bufp4_10--;
	return NUMBER;
}