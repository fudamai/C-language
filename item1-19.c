#include <stdio.h>
#define MAXLINE 1000

int getline19(char line[], int maxline);
void reverse19(char s[]);

// ��ӡ������
int main()
{
	char line[MAXLINE];

	while (getline19(line, MAXLINE) > 0)
	{
		reverse19(line);
		printf("%s", line);
	}
	return 0;
}

void reverse19(char s[])
{
	int i, j;
	char temp;

	i = 0;
	while (s[i] != '\0')
	{
		i++; // ���������ĳ���
	}
	i--;
	if (s[i] == '\n')
	{
		i--;
	}

	j = 0;
	while (j < i)
	{
		temp = s[j];  // ��������һ��ֵ
		s[j] = s[i];  // �������һ��ֵ�����һ��ֵ�����滻
		s[i] = temp;  // �����һ��ֵ���һ��ֵ�滻
		--i;
		++j;
	}
}

//����һ�е�s�в��ҷ��س���
int getline19(char s[], int lim)
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