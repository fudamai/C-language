#include <stdio.h>
#include <ctype.h>
#include <string.h>

int strindex_char(char s[], char t);

main4_1()
{
	char str1[] = "abcdefghijklmn";
	char a[] = "i";

	printf("%d\n", strindex_rev(str1, a));
}

/* �����ַ���t �� s �����ұ߳��ֵ�λ�� */
int strindex_rev(char s[], char t[])
{
	int i, j, k, ls, lt;

	ls = strlen(s);
	lt = strlen(t);
	for (i = ls - 1; i >= 0; i--) {  // �������
		//for (j = i, k = lt - 1; k >= 0 && s[j] == t[k]; j--, k--)  // if��ѭ�����жϣ���ʡ��Դ����k����һ��
		//	;
		//if (k == -1)  // kΪ-1��˵������t���ַ����������жϣ�����s����ͬ
		//	return i;
		for (j = i, k = lt - 1; k >= 0 && s[j] == t[k]; j--, k--)  // if��ѭ�����ж�
			if (k == 0)
				return i;
		;
	}
	return -1;
}

/* �����ַ��� s �г��ֵ�λ�� */
int strindex_char(char s[], char t)
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