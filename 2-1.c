#include <stdio.h>
#include "2-1.h"

/* getbits函数：返回从第p位开始的n位 */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);  // 按位与的优先级大于偏移
}

/* bitcount函数：统计x中值为1的二进制位数 */
int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

/* strcat 函数：将字符串t连接到字符串s的尾部 */
void strcat(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0')
	{
		i++;  // 得出字符串数组的长度
	}
	while ((s[i++] = t[j++]) != '\0') {  // 逐位添加
		;
	}
}

int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

plus()
{
	char cha1;
	unsigned int num1;
	unsigned int num2;
	unsigned int maxnum;
	unsigned int minnum;
	
	num1 = num2 = 1;
	maxnum = 0;
	minnum = 0;
	while (1)
	{
	
		num1++;
		num2--;
		if (num2 < minnum) {
			minnum = num1;
		}
		if (num1 > maxnum) {
			maxnum = num1;
		}
		printf("%d, %d\n", maxnum, minnum);
	}
}

/* atoi函数：将字符串s转换为相应的整形数。只能整型数字 */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}