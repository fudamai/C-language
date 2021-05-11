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

/* �沨�������� */
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

#define MAXVAL 100  // ջval��������

extern int sp;  // ��һ������ջλ��
extern double val[MAXVAL];  // ֵջ

/* eleout������Э������ջ����ֵ */
double eleout(void)
{
	++sp;  // ����pop������sp����ǰ���Լ�����ֻ��ӡ������£���ӡǰ��sp���� 1 ���ɱ�֤sp ֵ���䡣ʵ����ֻ��ӡ������
	
	/*if (sp > 0) {
		return val[sp];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}*/
}

/* ����ջ������Ԫ�ص�ֵ */
exchange() {
	int c;

	c = val[sp];
	val[sp] = val[sp - 1];
	val[sp - 1] = c;
	eleout();
}

/* ���ջ */
void rubbish() {
	sp = 0;
}

/* ��ֵջ��Ԫ�� */
void copy() {
	val[sp + 1] = val[sp];
	sp++;
}