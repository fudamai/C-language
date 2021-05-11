#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'

int getop4_5(char[]);
void push(double);
double pop(void);

//main()
//{
//	printf("%g", pow(2.0, 2.0));
//}

/* 逆波兰计算器 */
main4_5()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop4_5(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() + pop());
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case NAME:
			mathfun(s);
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

//#define MAXVAL 100  // 栈val的最大深度
//
//int sp = 0;  // 下一个空闲栈位置
//double val[MAXVAL];  // 值栈
//
///* push函数：把f压入到值栈中 */
//void push(double f)
//{
//	if (sp < MAXVAL)
//		val[sp++] = f;
//	else
//		printf("error: stack full, can't push %g\n", f);
//}
//
///* pop函数：弹出并返回栈顶的值 */
//double pop(void)
//{
//	if (sp > 0)
//		return val[--sp];
//	else {
//		printf("error: stack empty\n");
//		return 0.0;
//	}
//}

/* 调用库函数 */
mathfun(char s[])
{
	double op2;

	if (strcmp(s, "sin") == 0) {
		push(sin(pop()));
	} else if(strcmp(s, "exp") == 0) {
		push(exp(pop()));
	} else if(strcmp(s, "pow") == 0) {
		op2 = pop();
		push(pow(pop(), op2));
	} else {
		printf("error: %s not supported\n", s);
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop函数：获取下一个运算符或数值操作数 */
int getop4_5(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (islower(c)) {
		while (islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		if (strlen(s) > 1) {
			return NAME;
		}
		else {
			return c;
		}
	}
	if (!isdigit(c) && c != '.')
		return c;  // 不是数
	if (isdigit(c))  // 收集整数部分
		while (isdigit(s[++i] = c = getch()))  // 小数点在这里已经赋值完成，超前读入一个字符
			;
	if (c == '.')  // 收集小数部分
		while (isdigit(s[++i] = c = getch()))  // 先赋值，再getch。赋值时执行的是覆盖操作。getch返回时，也是先赋值，再判断
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

//#define BUFSIZE 100
//
//char buf[BUFSIZE];  // 用于ungetch函数的缓冲区
//int bufp = 0;  // buf中下一个空闲位置
//
//int getch(void)  // 取一个字符（可能是压回的字符）
//{
//	return (bufp > 0) ? buf[--bufp] : getchar();
//}
//
//void ungetch(int c)  // 把字符压回输入中
//{
//	if (bufp >= BUFSIZE)
//		printf("ungetch: too many characters\n");
//	else
//		buf[bufp++] = c;
//}