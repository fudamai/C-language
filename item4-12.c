#include <stdio.h>
#include <stdlib.h>

char itoa_recur(int, char);

main4_12()
{
	int in = -199999999;
	char s[100];

	itoa_recur(in, s);
	printf(s);
}

/* �ݹ�汾itoa */
int i = 0, sign;
char itoa_recur(int n, char s[])
{

	if (n / 10) {
		itoa_recur(n / 10, s);
	}
	else {
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';  // ��Ϊ���Ǽ�����������̣����Բ������ַ�˳��װ����
	s[i] = '\0';
}

//void reverse(char s[])
//{
//	int c, i, j;
//
//	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
//	{
//		c = s[i];
//		s[i] = s[j];
//		s[j] = c;
//	}
//}
//
///* itoa������������nת��Ϊ�ַ��������浽s�� */
//void itoa(int n, char s[])
//{
//	int i, sign;
//
//	if ((sign = n) < 0)
//		n = -n;
//	i = 0;
//	do {
//		s[i++] = n % 10 + '0';
//	} while ((n /= 10) > 0);
//	if (sign < 0)
//		s[i++] = '-';
//	s[i] = '\0';
//	reverse(s);
//}