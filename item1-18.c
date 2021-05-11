
#include <stdio.h>
#define MAXLINE 10	//���������е���󳤶�

int getline18(char line[], int maxline);
int remove18(char s[]);

//��ӡ�������
int main18()
{
	char line[MAXLINE];		//��ǰ������

	while (getline18(line, MAXLINE) > 0)
	{
		if (remove18(line) > 0)
		{
			printf("%s", line);
		}
	}

	return 0;
}

int remove18(char s[])
{
	int i;

	i = 0;
	while (s[i] != '\n')
	{
		++i; // ���з�ǰ���ַ���
	}
	--i;

	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
	{
		--i;  // ȥ���ո���������ַ���
	}

	if (i >= 0)
	{
		++i;
		s[i] = '\n';  // ��ӻ���
		++i;
		s[i] = '\0';  // ����ַ���������
	}

	return i;
}

//����һ�е�s�в��ҷ��س���
int getline18(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (i < lim - 2)
		{
			s[j] = c;
			++j;
		}

	}
	if (c == '\n')
	{
		s[j] = c;
		++i;
		++j;
	}

	s[j] = '\0';

	return i;
}