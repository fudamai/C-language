#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

/* 简单计算器程序 */
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

/* atof函数：把字符串s转换为相应的双精度浮点数 */
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
		val = 10.0 * val + (s[i] - '0');  // val只统计有效位的值
		power *= 10.0;  // 小数点后每增一位，power进一个十
	}
	return sign * val / power;  // 有效值除以小数点后零位，乘以正负
}