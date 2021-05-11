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

/* �沨�������� */
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

//#define MAXVAL 100  // ջval��������
//
//int sp = 0;  // ��һ������ջλ��
//double val[MAXVAL];  // ֵջ
//
///* push��������fѹ�뵽ֵջ�� */
//void push(double f)
//{
//	if (sp < MAXVAL)
//		val[sp++] = f;
//	else
//		printf("error: stack full, can't push %g\n", f);
//}
//
///* pop����������������ջ����ֵ */
//double pop(void)
//{
//	if (sp > 0)
//		return val[--sp];
//	else {
//		printf("error: stack empty\n");
//		return 0.0;
//	}
//}

/* ���ÿ⺯�� */
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

/* getop��������ȡ��һ�����������ֵ������ */
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
		return c;  // ������
	if (isdigit(c))  // �ռ���������
		while (isdigit(s[++i] = c = getch()))  // С�����������Ѿ���ֵ��ɣ���ǰ����һ���ַ�
			;
	if (c == '.')  // �ռ�С������
		while (isdigit(s[++i] = c = getch()))  // �ȸ�ֵ����getch����ֵʱִ�е��Ǹ��ǲ�����getch����ʱ��Ҳ���ȸ�ֵ�����ж�
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

//#define BUFSIZE 100
//
//char buf[BUFSIZE];  // ����ungetch�����Ļ�����
//int bufp = 0;  // buf����һ������λ��
//
//int getch(void)  // ȡһ���ַ���������ѹ�ص��ַ���
//{
//	return (bufp > 0) ? buf[--bufp] : getchar();
//}
//
//void ungetch(int c)  // ���ַ�ѹ��������
//{
//	if (bufp >= BUFSIZE)
//		printf("ungetch: too many characters\n");
//	else
//		buf[bufp++] = c;
//}