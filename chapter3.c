#include <stdio.h>
#include <ctype.h>
#include <string.h>

main3()
{
	int list[100];
	int i;
	for (i = 0; i < 10; i++)
		list[i] = i;
	int an = 5;
	/*shellsort(list, an);*/
	printf("%d", binsearch(1, list, 10));
}

/* 将字符串格式的数字转换成整型数 */
int atoi3(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)  // 跳过空白符
		;
	sign = (s[i] == '-') ? -1: 1;  // 跳过符号
	if (s[i] == '+' || s[i] == '-')  // 跳过符号
		i++;
	for (n = 0; isdigit(s[i]); i++)  // 将字符串格式的数字转换成整型数
		n = 10 * n + (s[i] - '0');
	return sign * n;
}

/* shellsort函数：按递增顺序对v[0]...v[n-1]进行排序 */
//void shellsort(int v[], int n)
//{
//	int gap, i, j, temp;
//
//	for (gap = n/2; gap > 0; gap /= 2)
//		for (i = gap; i < n; i++)
//			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
//				temp = v[j];
//				v[j] = v[j + gap];
//				v[j + gap] = temp;
//			}
//}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itoa函数：将数字n转换为字符串并保存到s中 */
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* trim函数：删除字符串尾部的空格符、制表符、换行符 */
int trim(char s[])
{
	int n;

	for (n = strlen(s) - 1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	s[n + 1] = '\0';
	return n;
}

/* 在一个递增数组中查找x */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}