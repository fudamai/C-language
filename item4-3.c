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

/* �沨�������� */
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

/* getop��������ȡ��һ�����������ֵ������ */
int getop4_3(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;  // ������
	i = 0;
	if (c == '-') {
		s[++i] = c = getch();
	}
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