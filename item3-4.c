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
	// void reverse34(char s[]);  // ��ת������û�����尡

	sign = n;  // �����ֵ�����ͣ����ͳ�����һ��ʮ������
	i = 0;

	do {
		s[i++] = abs(n % 10) + '0';  // �����ֵ��������ֵ���ַ�������ӣ���ö�Ӧ���ֵ��ַ�����
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse34(s);
}

/*
�Զ������ܱ�ʾ���������2���ֳ���һ�Ĵη��ټ�һ
��С�ĸ���Ϊ2���ֳ���һ�η���
ȥ�����ź���С��������ֵ�����������һ
*/