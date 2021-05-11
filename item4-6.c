#include <stdio.h>
#include <stdlib.h>  // 为了使用atof()函数

#define MAXOP 100  // 操作数或运算符的最大长度
#define NUMBER '0'  // 标识找到一个数

int getop(char[]);
void push(double);
double pop(void);

/* 逆波兰计算器 */
main4_6()
{
	int type, i, var = 0;
	double op2, v;
	char s[MAXOP];
	double variable[26];

	/* 添加一个包含26个英文字母的数组 */
	for (i = 0; i < 26; i++)
		variable[i] = 0.0;

	while ((type = getop(s)) != EOF) {
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
		case '=':
			pop();  // 弹出的是压进去变量名
			if (var >= 'A' && var <= 'Z')
				variable[var - 'A'] = pop();  // 给变量赋值
			else
				printf("error: no variable name \n");
			break;
		case '\n':
			v = pop();
			printf("\t%.8g\n", v);
			break;
		default:
			if (type >= 'A' && type <= 'Z')
				push(variable[type - 'A']);  // 压进去一个地址
			else if (type == 'v')
				push(v);
			else
				printf("error: unknown command %s\n", s);
			break;
		}
		var = type;
	}
	return 0;
}