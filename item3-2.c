#include <string.h>
#include <stdio.h>

main3_2()
{
	char str1[100];
	char str2[] = "asd\nfgg\taa";
	noescape(str1, str2);
	printf("%s%s\n", "\\" , "n");
	printf("%s\n", str1);
}

escape(char s[], char t[])
{
	int i, len;
	len = strlen(t);

	for (i = 0; i < len; i++)
	{
		if (t[i] == '\n') {
			s[i] = "\\n";
		}
		else if (t[i] == '\t') {
			s[i] = "\\t";
		}
		else
		{
		s[i] = t[i];
		}
	}
}


/* ���ַ���t���Ƶ��ַ���s */
escape_switch(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; i++)
	{
		switch (t[i]) {
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';  // i��j����ͬ����
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
}


/* ���ƹ����н�ת���ַ�����ת��Ϊʵ���ַ� */
noescape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; i++)
	{
		switch (t[i]) {
		case '\\' + 'n':
			//s[j++] = '\\';
			s[j++] = '\n';  // i��j����ͬ����
			break;
		case '\\' + 't':
			//s[j++] = '\\';
			s[j++] = '\t';
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';
}