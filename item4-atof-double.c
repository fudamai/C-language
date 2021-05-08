#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

/* �򵥼��������� */
main4_a_d()
{
	double sum, atof_d(char []);
	char line[MAXLINE];
	int getline(char line[], int max);

	sum = 0;
	while (getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof_d(line));
	return 0;
}

/* atof���������ַ���sת��Ϊ��Ӧ��˫���ȸ����� */
double atof_d(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');  // valֻͳ����Чλ��ֵ
		power *= 10.0;  // С�����ÿ��һλ��power��һ��ʮ
	}
	return sign * val / power;  // ��Чֵ����С�������λ����������
}