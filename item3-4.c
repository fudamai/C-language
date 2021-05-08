#include <stdio.h>
#include <ctype.h>
#include <string.h>

main3_4()
{
	int num;
	char str1[100];

	//num = 2147483647; // 
	num = 2147483648;
	// num = 4294967294; //  
	itoa34(num, str1);

	printf("%s\n", str1);
	printf("%d\n", num);
}

void reverse34(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

itoa34(int n, char s[])
{
	int i, sign;
	// void reverse34(char s[]);  // 倒转空数组没有意义啊

	sign = n;  // 输入的值是整型，解释出来是一个十进制数
	i = 0;

	do {
		s[i++] = abs(n % 10) + '0';  // 求绝对值，将绝对值与字符常量相加，获得对应数字的字符常量
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse34(s);
}

/*
对二补码能表示的最大正数2的字长减一的次方再减一
最小的负数为2的字长减一次方，
去掉符号后，最小负数绝对值比最大正数大一
*/