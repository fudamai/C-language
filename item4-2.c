#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

/* 简单计算器程序 */
main4_2()
{
	double sum, atof_d_4_2(char[]);
	char line[MAXLINE];
	int getline4_2(char line[], int max);

	sum = 0;
	while (getline4_2(line, MAXLINE) > 0)
		//printf("\t%g\n", sum += atof_d_4_2(line));
		printf("\t%g\n", atof_d_4_2(line));
	return 0;


}

/* atof函数：把字符串s转换为相应的双精度浮点数 */
double atof_d_4_2(char s[])
{
	double val, power;
	int i, sign, esign;
	int powernum = 0;


	esign = 1;
	power = 1.0;
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

	/* 处理科学计数法 */
	if (s[i] == 'e') {
		i++;
	}
	/* 统计幂的大小及正负 */
	while (s[i] != EOF && s[i] != '\n') {
		switch (s[i]) {
		case '-':
			esign = 0;
			break;
		case '+':
			esign = 1;
			break;
		default:
			powernum = 10 * powernum + (s[i] - '0');
			break;
		}
		i++;
	}
	/* 合并幂位 */
	if (esign) {
		for (int n = 1; n <= powernum; n++) {  // 减'0'，将字符串转为整型
					
			power /= 10.0;  // 没有负号，小数点前移。返回时再除一次，小数点后移
		}
	}
	else
	{
		for (int n = 1; n <= powernum; n++) {
			power *= 10.0;  // 有负号，小数点后移。返回时再除一次，小数点前移
		}
	}
	return sign * val / power;  // 有效值除以小数点后零位，乘以正负
}


/* getline函数：将行保存到s中，并返回改行的长度 */
int getline4_2(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')  // 限制了长度
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* 题干：
扩充atof函数，使之能处理科学计数发表示的数字。
字符串 123.45e-6 转成 浮点数 0.00012345.
*/