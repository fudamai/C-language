#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'  // 标识找到一个数


int getch(void);
void ungetch(int);

/* getop函数：获取下一个运算符或数值操作数 */
int getop4_11(char s[])
{
	int i, c;
	static int lastc = 0;

	if (lastc == 0)
		c = getch();
	else {
		c = lastc;  // 从缓冲区取值
		lastc = 0;
	}
	
	while ((s[0] = c) == ' ' || c == '\t')
		c = getch();
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;  // 不是数
	i = 0;
	if (isdigit(c))  // 收集整数部分
		while (isdigit(s[++i] = c = getch()))  // 小数点在这里已经赋值完成，超前读入一个字符
			;
	if (c == '.')  // 收集小数部分
		while (isdigit(s[++i] = c = getch()))  // 先赋值，再getch。赋值时执行的是覆盖操作。getch返回时，也是先赋值，再判断
			;
	s[i] = '\0';
	if (c != EOF)  // 检测到当前字符不是结尾，压回
		lastc = c;
	return NUMBER;
}