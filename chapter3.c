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

/* ���ַ�����ʽ������ת���������� */
int atoi3(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)  // �����հ׷�
		;
	sign = (s[i] == '-') ? -1: 1;  // ��������
	if (s[i] == '+' || s[i] == '-')  // ��������
		i++;
	for (n = 0; isdigit(s[i]); i++)  // ���ַ�����ʽ������ת����������
		n = 10 * n + (s[i] - '0');
	return sign * n;
}

/* shellsort������������˳���v[0]...v[n-1]�������� */
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

/* itoa������������nת��Ϊ�ַ��������浽s�� */
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

/* trim������ɾ���ַ���β���Ŀո�����Ʊ�������з� */
int trim(char s[])
{
	int n;

	for (n = strlen(s) - 1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	s[n + 1] = '\0';
	return n;
}

/* ��һ�����������в���x */
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