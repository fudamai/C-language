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
����ת��.����b�ǽ��ƣ�n�����룬s�����
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
		s[i++] = (j <= 9) ? j+'0' : j+'a'-10;  // ����ʮʱ����a��ʼ���¼�����Ҫ��ʮ
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/*
����˼·���Ȱ���������b��������ÿһλ���֣����ú���reverse���ַ���s�е��ַ���һ�εߵ����õ����ս��
*/