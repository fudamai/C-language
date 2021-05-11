#include <stdio.h>
#include <stdlib.h>  // Ϊ��ʹ��atof()����

#define MAXOP 100  // �����������������󳤶�
#define NUMBER '0'  // ��ʶ�ҵ�һ����

int getop(char[]);
void push(double);
double pop(void);

/* �沨�������� */
main4_6()
{
	int type, i, var = 0;
	double op2, v;
	char s[MAXOP];
	double variable[26];

	/* ���һ������26��Ӣ����ĸ������ */
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
			pop();  // ��������ѹ��ȥ������
			if (var >= 'A' && var <= 'Z')
				variable[var - 'A'] = pop();  // ��������ֵ
			else
				printf("error: no variable name \n");
			break;
		case '\n':
			v = pop();
			printf("\t%.8g\n", v);
			break;
		default:
			if (type >= 'A' && type <= 'Z')
				push(variable[type - 'A']);  // ѹ��ȥһ����ַ
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