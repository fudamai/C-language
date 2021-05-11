#include <stdio.h>

main3_5()
{
	int num1, num2;
	char str1[100];

	num1 = 15;
	num2 = 16;
	
	itob(num1, str1, num2);
	printf("%s\n", str1);
}

/*
进制转化.参数b是进制，n是输入，s是输出
*/
itob(int n, char s[], int b)
{
	int i, j, sign;
	void reverse(char s[]);

	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		j = n % b;
		s[i++] = (j <= 9) ? j+'0' : j+'a'-10;  // 超过十时，从a开始重新计数，要减十
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/*
解题思路：先按逆序生成b进制数的每一位数字，再用函数reverse对字符串s中的字符做一次颠倒而得到最终结果
*/