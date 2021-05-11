#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
double eleout(void);
void copy();
void rubbish();

/* 逆波兰计算器 */
main4_4()
{
	int type;
	double op2;
	char s[MAXOP];

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
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case 'p':
			eleout();
			break;
		case 'e':
			exchange();
			break;
		case 'r':
			rubbish();
			break;
		case 'c':
			copy();
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

#define MAXVAL 100  // 栈val的最大深度

extern int sp;  // 下一个空闲栈位置
extern double val[MAXVAL];  // 值栈

/* eleout函数：协助返回栈顶的值 */
double eleout(void)
{
	++sp;  // 由于pop函数对sp采用前置自减。在只打印的情况下，打印前让sp自增 1 即可保证sp 值不变。实现了只打印不弹出
	
	/*if (sp > 0) {
		return val[sp];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}*/
}

/* 交换栈顶两个元素的值 */
exchange() {
	int c;

	c = val[sp];
	val[sp] = val[sp - 1];
	val[sp - 1] = c;
	eleout();
}

/* 清空栈 */
void rubbish() {
	sp = 0;
}

/* 赋值栈顶元素 */
void copy() {
	val[sp + 1] = val[sp];
	sp++;
}