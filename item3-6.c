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
		str2++;  // �����ַ���������
		num2++;  // ������Ҳ��������
	}
}


/* ������nת��Ϊ�ַ��������浽s��
���������С��ȹ���
*/
itoa_three(int n, char s[], int w)
{
	int i, sign;
	// void reverse(char s[]);  // ��ת������û�����尡

	sign = n;  // �����ֵ�����ͣ����ͳ�����һ��ʮ������
	i = 0;

	do {
		s[i++] = abs(n % 10) + '0';  // �����ֵ��������ֵ���ַ�������ӣ���ö�Ӧ���ֵ��ַ�����
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	if (i < w)  // ʹ��i��Ϊ�жϿ������
	{
		do {
			s[i++] = ' ';
		} while (w > i);

	}
	s[i] = '\0';
	reverse(s);
}