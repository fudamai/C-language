#include <string.h>
#include <stdio.h>

void reverse_recur(char);

main4_13()
{
	char str13[] = "abcdefg";

	reverse_recur(str13);
	printf(str13);
}

void reverse_recur(char s[])
{
	void reverser(char [], int, int);
	reverser(s, strlen(s), 0);
}


/* ����������ַ������ȡ���ʶ��ȵ�i=0 */
void reverser(char s[], int l, int i) {
	int c, j;
	j = l - (i + 1);
	if(i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverser(s, l, ++i);
	}
}

//void reverse34(char s[])
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

/*
��ɣ�
��дһ���ݹ�汾��reverse(s)�������Խ��ַ���s����
*/