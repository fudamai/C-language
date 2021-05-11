#include <stdio.h>

main3_6()
{
	int num1, num2;
	char str1[100];

	num1 = 15;
	num2 = 16;

	itoa_three(num1, str1, num2);
	printf("%s\n", str1);

	char str2 = "a"[0];
	while (str2 != '\0')
	{
		str2++;  // 单个字符可以自增
		num2++;  // 整型数也可以自增
	}
}


/* 将数字n转换为字符串并保存到s中
添加限制最小宽度功能
*/
itoa_three(int n, char s[], int w)
{
	int i, sign;
	// void reverse(char s[]);  // 倒转空数组没有意义啊

	sign = n;  // 输入的值是整型，解释出来是一个十进制数
	i = 0;

	do {
		s[i++] = abs(n % 10) + '0';  // 求绝对值，将绝对值与字符常量相加，获得对应数字的字符常量
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	if (i < w)  // 使用i作为判断宽度依据
	{
		do {
			s[i++] = ' ';
		} while (w > i);

	}
	s[i] = '\0';
	reverse(s);
}