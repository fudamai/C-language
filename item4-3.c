#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

//main()
//{
//	int num1, num2;
//
//	num1 = 9;
//	num2 = -5;
//	printf("%d \n", num1 % num2);
//	printf("%d \n", num1 / num2);
//}

/* 逆波兰计算器 */
main4_3()
{
	int type;
	double op2;
	int num1, num2;
	char s[MAXOP];

	while ((type = getop4_3(s)) != EOF) {
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
		case '%':
			num2 = pop();
			num1 = pop();

			if (num2 != 0)
				push(num1 % num2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop函数：获取下一个运算符或数值操作数 */
int getop4_3(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;  // 不是数
	i = 0;
	if (c == '-') {
		s[++i] = c = getch();
	}
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