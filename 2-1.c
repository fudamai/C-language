#include <stdio.h>
#include "2-1.h"

/* getbits���������شӵ�pλ��ʼ��nλ */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);  // ��λ������ȼ�����ƫ��
}

/* bitcount������ͳ��x��ֵΪ1�Ķ�����λ�� */
int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

/* strcat ���������ַ���t���ӵ��ַ���s��β�� */
void strcat(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0')
	{
		i++;  // �ó��ַ�������ĳ���
	}
	while ((s[i++] = t[j++]) != '\0') {  // ��λ���
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

/* atoi���������ַ���sת��Ϊ��Ӧ����������ֻ���������� */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}