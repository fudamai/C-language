#include <stdio.h>
#include <ctype.h>

int strrindex(char s[], char t);

main()
{
	char str1[] = "abcdefghijklmn";
	char a = 'g';

	printf("%d\n", strrindex(str1, a));
}

int strrindex(char s[], char t)
{
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == t) {
			return i;
		}
	}
	return -1;
}

/* ��ɣ�
��д����strrindex(s, t)���������ַ���t��s�����ұ߳��ֵ�λ�á�
���s�в�����t���򷵻�-1��
*/